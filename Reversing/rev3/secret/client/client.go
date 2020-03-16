package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

const sendBuf = "hello can you hear me?"
const requestFlag = "can i have the flag?"

func main() {
	// connect to server

	if len(os.Args) != 2 {
		fmt.Println("usage: " + os.Args[0] + " IP:PORT")
		return
	}

	initial := "Establishing Connection ... \n"
	fmt.Println(initial)

	conn, err := net.Dial("tcp", os.Args[1])
	if err == nil {
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
	} else {
		fmt.Print("Could not connect to server please contact admin")
	}

}
