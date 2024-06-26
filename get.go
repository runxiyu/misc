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
	fmt.Printf("pid: %d\n", os.Getpid())
	var wg sync.WaitGroup

	for i := 0; i < 10000; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			err := downloadFile(fmt.Sprintf("/tmp/test-download-%d", i), "http://localhost:5555")
			if err != nil {
				panic(err)
			}
			fmt.Printf(".")
		}()
	}
	wg.Wait()
}
