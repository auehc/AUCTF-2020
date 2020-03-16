// socket client for golang
// https://golangr.com
package main

import (
	"bufio"
	"fmt"
	"net"
)

const host = "127.0.0.1:8000" // host for connection
const sendBuf = "hello can you hear me?"
const requestFlag = "can i have the flag?"

func main() {
	// connect to server
	conn, _ := net.Dial("tcp", host)
	for {
		// send to server
		fmt.Fprintf(conn, sendBuf)
		// wait for reply
		message, _ := bufio.NewReader(conn).ReadString('\n')
		fmt.Print("Message from server: " + message)

		// send to server
		fmt.Fprintf(conn, requestFlag)
		// wait for reply
		_, _ = bufio.NewReader(conn).ReadString('\n')
		fmt.Print("Message from server: " + "")

	}
}
