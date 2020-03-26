FROM ubuntu:latest

RUN apt update
RUN apt install -y socat
RUN groupadd ctf

RUN mkdir /rev

COPY cracker_barrel /rev/crackme
COPY flag.txt /rev/
COPY entry.sh /rev/entry.sh

RUN useradd -G ctf --home=/rev revuser
RUN useradd -G ctf --home=/rev revflag

RUN chown revflag:revflag /rev/crackme
RUN chown revflag:revflag /rev
RUN chown revflag:revflag /rev/flag.txt

RUN chmod 4755 /rev/crackme
RUN chmod 4755 /rev/entry.sh
RUN chmod 444 /rev/flag.txt

EXPOSE 30000
ENTRYPOINT ["/rev/entry.sh"]
