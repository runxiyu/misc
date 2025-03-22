package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"

	"github.com/alecthomas/chroma/v2"
	"github.com/alecthomas/chroma/v2/formatters/html"
	"github.com/alecthomas/chroma/v2/lexers"
	"github.com/alecthomas/chroma/v2/styles"
)

func main() {
	if len(os.Args) < 2 {
		progname := "syntax-highlighting"
		if len(os.Args) == 1 {
			progname = os.Args[1]
		}
		fmt.Fprintf(os.Stderr, "Usage: %s <filename>\nThe filename is only used for file extension detection.\nInput must be provided on standard input.\n", progname)
		os.Exit(1)
	}
	filename := os.Args[1]

	reader := bufio.NewReader(os.Stdin)
	var builder strings.Builder
	for {
		line, err := reader.ReadString('\n')
		builder.WriteString(line)
		if err == io.EOF {
			break
		} else if err != nil {
			fmt.Fprintf(os.Stderr, "Error reading input: %v\n", err)
			os.Exit(1)
		}
	}
	data := builder.String()

	var lexer chroma.Lexer
	lexer = lexers.Match(filename)
	if lexer == nil {
		if strings.HasPrefix(data, "#!") {
			lexer = lexers.Analyse(data)
		}
		if lexer == nil {
			lexer = lexers.Get("text")
		}
	}

	lexer = chroma.Coalesce(lexer)

	style := styles.Get("emacs")
	if style == nil {
		style = styles.Fallback
	}

	formatter := html.New()

	fmt.Println("<style>")
	if err := formatter.WriteCSS(os.Stdout, style); err != nil {
		fmt.Fprintf(os.Stderr, "Error writing CSS: %v\n", err)
		os.Exit(1)
	}
	fmt.Println("</style>")

	iterator, err := lexer.Tokenise(nil, data)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error tokenizing: %v\n", err)
		os.Exit(1)
	}
	if err := formatter.Format(os.Stdout, style, iterator); err != nil {
		fmt.Fprintf(os.Stderr, "Error formatting: %v\n", err)
		os.Exit(1)
	}
}
