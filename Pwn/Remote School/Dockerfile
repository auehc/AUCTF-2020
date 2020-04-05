FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat
RUN groupadd ctf

RUN mkdir /pwn

COPY online /pwn/challenge
COPY flag.txt /pwn/
COPY entry.sh /pwn/

RUN useradd -G ctf --home=/pwn pwnuser
RUN useradd -G ctf --home=/pwn pwnflag

RUN chown pwnflag:pwnflag /pwn/challenge
RUN chown pwnflag:pwnflag /pwn

RUN chmod 4755 /pwn/challenge
RUN chmod 4755 /pwn/entry.sh

EXPOSE 30013
ENTRYPOINT ["/pwn/entry.sh"]
