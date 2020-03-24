FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat python python3 

EXPOSE 7777
ENTRYPOINT ["/entry.sh"]