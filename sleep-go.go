package main

import (
	"net/http"
	"time"
	"fmt"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		time.Sleep(5000000000)
		fmt.Fprintf(w, "Hello, world!")
	})

	http.ListenAndServe(":8081", nil)
}
