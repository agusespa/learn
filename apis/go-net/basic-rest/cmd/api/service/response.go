package service

import (
	"fmt"
	"log"
	"net"
)

func Build200Response(conn net.Conn, payload string) {
	statusLine := "HTTP/1.1 200 OK\r\n"
	headers := "Content-Type: application/json\r\n"
	headers += fmt.Sprintf("Content-Length: %d\r\n", len(payload))
	response := statusLine + headers + "\r\n" + payload
	sendResponse(response, conn)
}

func Build201Response(conn net.Conn, payload string) {
	statusLine := "HTTP/1.1 201 Created\r\n"
	headers := "Content-Type: application/json\r\n"
	headers += fmt.Sprintf("Content-Length: %d\r\n", len(payload))
	response := statusLine + headers + "\r\n" + payload
	sendResponse(response, conn)
}

func Build400Response(conn net.Conn) {
	statusLine := "HTTP/1.1 400 Bad Request\r\n"
	headers := "Content-Length: 0\r\n\r\n"
	response := statusLine + headers
	sendResponse(response, conn)
}

func Build404Response(conn net.Conn) {
	statusLine := "HTTP/1.1 404 Not Found\r\n"
	headers := "Content-Length: 0\r\n\r\n"
	response := statusLine + headers
	sendResponse(response, conn)
}

func Build405Response(conn net.Conn) {
	statusLine := "HTTP/1.1 405 Method Not Allowed\r\n"
	headers := "Content-Length: 0\r\n\r\n"
	response := statusLine + headers
	sendResponse(response, conn)
}

func Build500Response(conn net.Conn) {
	statusLine := "HTTP/1.1 500 Internal Server Error\r\n"
	headers := "Content-Length: 0\r\n\r\n"
	response := statusLine + headers
	sendResponse(response, conn)
}

func sendResponse(response string, conn net.Conn) {
	_, err := conn.Write([]byte(response))
	if err != nil {
		log.Println("Error: ", err)
		return
	}
}
