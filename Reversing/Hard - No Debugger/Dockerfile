FROM 32bit/ubuntu:16.04

RUN apt update && apt install -y socat
RUN groupadd ctf

RUN mkdir /rev

COPY dont_break_me /rev/debug
COPY flag.txt /rev/
COPY entry.sh /rev/entry.sh

RUN useradd -G ctf --home=/rev revuser
RUN useradd -G ctf --home=/rev revflag

RUN chown revflag:revflag /rev/debug
RUN chown revflag:revflag /rev
RUN chown revflag:revflag /rev/flag.txt

RUN chmod 4755 /rev/debug
RUN chmod 4755 /rev/entry.sh
RUN chmod 444 /rev/flag.txt

EXPOSE 30005
ENTRYPOINT ["/rev/entry.sh"]
