from python:2.7

copy ftp_server.py .
copy flag.txt .
copy web_server.py .
copy startup.sh .
copy requirements.txt .
copy /templates/help /templates/help
run pip install -r requirements.txt && rm requirements.txt


expose 80
entrypoint /startup.sh && /bin/bash
