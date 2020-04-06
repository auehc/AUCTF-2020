Har Har Har
--

There is an image in the http stream that is base64 encoded.

Get the image by copying the base64 text from the first response to a file (base64txt in this answer) and running the following:
```base64 --decode base64txt > har.png```

Alternative Solution. Open a web browser press F12 and click on networks. Then drag the file into the networks area. Click preview and it will show you the image.
https://imgur.com/bFOiWRL

Flag: auctf{har_har34}