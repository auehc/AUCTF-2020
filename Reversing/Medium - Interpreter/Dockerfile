FROM ubuntu:latest

RUN apt update
RUN apt install -y socat
RUN apt install -y default-jre
RUN groupadd ctf

RUN mkdir /rev

COPY interpret.class /rev/
COPY flag.txt /rev/
COPY entry.sh /rev/entry.sh

RUN useradd -G ctf --home=/rev revuser
RUN useradd -G ctf --home=/rev revflag

RUN chown revflag:revflag /rev/interpret.class
RUN chown revflag:revflag /rev
RUN chown revflag:revflag /rev/flag.txt

RUN chmod 4755 /rev/interpret.class
RUN chmod 4755 /rev/entry.sh
RUN chmod 444 /rev/flag.txt

EXPOSE 30001
ENTRYPOINT ["/rev/entry.sh"]
