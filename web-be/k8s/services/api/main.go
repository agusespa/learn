package main

import (
	"fmt"
	"io"
	"net/http"
)

func timeHandler(w http.ResponseWriter, r *http.Request) {
	currentTime := getCurrentTime()
	fmt.Fprintf(w, "Current time: %s", currentTime)
}

func main() {
	http.HandleFunc("/now", timeHandler)

	port := 3000
	fmt.Printf("Starting server on port %d...\n", port)
	err := http.ListenAndServe(fmt.Sprintf(":%d", port), nil)
	if err != nil {
		fmt.Printf("Error starting server: %s\n", err)
	}
}

func getCurrentTime() string {
	resp, err := http.Get("http://127.0.0.1:3030")
	if err != nil {
		fmt.Printf("Error in response: %s\n", err)
	}
	defer resp.Body.Close()
	body, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Printf("Error in reading: %s\n", err)
	}
	return string(body)
}
