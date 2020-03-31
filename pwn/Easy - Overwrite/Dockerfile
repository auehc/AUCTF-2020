FROM 32bit/ubuntu:16.04

RUN apt update && apt install -y socat
RUN groupadd ctf

RUN mkdir /pwn

COPY turkey /pwn/overwrite
COPY flag.txt /pwn/
COPY entry.sh /pwn/

RUN useradd -G ctf --home=/pwn pwnuser
RUN useradd -G ctf --home=/pwn pwnflag

RUN chown pwnflag:pwnflag /pwn/overwrite
RUN chown pwnflag:pwnflag /pwn

RUN chmod 4755 /pwn/overwrite
RUN chmod 4755 /pwn/entry.sh

EXPOSE 30011
ENTRYPOINT ["/pwn/entry.sh"]
