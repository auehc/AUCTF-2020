package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

const sendBuf = "hello can you hear me?"
const requestFlag = "can i have the flag?"

func main() {

	if len(os.Args) != 2 {
		fmt.Println("usage: " + os.Args[0] + " IP:PORT")
		return
	}
	initial := "Establishing Connection ... \n"
	fmt.Println(initial)

	url := "http://" + os.Args[1] + "/question.php"
	client := &http.Client{}
	req, err := http.NewRequest("GET", url, nil)
	if err == nil {
		req.Header.Set("HELLO", sendBuf)
		req.Header.Set("HAND", requestFlag)
		res, err := client.Do(req)

		if err == nil {
			body, _ := ioutil.ReadAll(res.Body)
			fmt.Print("Message from server: " + string(body))

			cookie := res.Header.Get("COOKIE")

			req, _ = http.NewRequest("GET", url, nil)
			req.Header.Set("COOKIE", cookie)
			_, _ = client.Do(req)

			fmt.Print("Message from server: " + "")

			// wait for reply
		} else {
			fmt.Print("Could not connect to server please contact admin")
		}
	} else {
		fmt.Print("Could not connect to server please contact admin")
	}

}
