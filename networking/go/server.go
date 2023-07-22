package main

import (
	"fmt"
	"log"
	"net"
)

func main() {

	listener, err := net.Listen("tcp", ":8080")
	if err != nil {
		log.Println("Listener start fail: ", err)
		return
	}

	fmt.Println("Server listening on port 8080")

	defer listener.Close()

	for {
		conn, err := listener.Accept()

		if err != nil {
			log.Println("Listener connection fail: ", err)
		}

		go func(c net.Conn) {
			defer c.Close()
			// Your code would handle the connection here.
		}(conn)
	}
}
