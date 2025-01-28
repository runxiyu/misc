package main

import (
	"net/http"
	"time"
	"fmt"
	"os"
	// "runtime/debug"
)

func main() {
	// debug.SetMaxThreads(2)
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		time.Sleep(5000000000)
		fmt.Fprintf(w, "Hello, world!")
	})

	fmt.Printf("pid: %d\n", os.Getpid())
	http.ListenAndServe(":8081", nil)
}
