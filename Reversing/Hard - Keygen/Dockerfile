FROM ubuntu:latest

RUN apt update && apt install -y socat
RUN groupadd ctf

RUN mkdir /rev

COPY sora /rev/keygen
COPY flag.txt /rev/
COPY entry.sh /rev/entry.sh

RUN useradd -G ctf --home=/rev revuser
RUN useradd -G ctf --home=/rev revflag

RUN chown revflag:revflag /rev/keygen
RUN chown revflag:revflag /rev
RUN chown revflag:revflag /rev/flag.txt

RUN chmod 4755 /rev/keygen
RUN chmod 4755 /rev/entry.sh
RUN chmod 444 /rev/flag.txt

EXPOSE 30004
ENTRYPOINT ["/rev/entry.sh"]
