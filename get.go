// This stupid program just tests download concurrency.

package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"sync"
)

func downloadFile(filepath string, url string) (err error) {

	out, err := os.Create(filepath)
	if err != nil {
		return err
	}
	defer out.Close()

	resp, err := http.Get(url)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	_, err = io.Copy(out, resp.Body)
	if err != nil {
		return err
	}

	return nil
}

func main() {
	var wg sync.WaitGroup

	for i := 0; i < 2000; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			err := downloadFile(fmt.Sprintf("download-%d", i), "http://localhost:8081")
			if err != nil {
				panic(err)
			}
			fmt.Printf(".")
		}()
	}
	wg.Wait()
}
