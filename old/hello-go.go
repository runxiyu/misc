package main

import (
	"net/http"
	"fmt"
	"os"
	// "runtime/debug"
)

func main() {
	// debug.SetMaxThreads(2)
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello, world!")
	})

	fmt.Printf("pid: %d\n", os.Getpid())
	http.ListenAndServe(":8081", nil)
}
