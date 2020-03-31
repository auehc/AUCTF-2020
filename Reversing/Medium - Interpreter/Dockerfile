FROM ubuntu:latest

RUN apt update && apt install -y socat default-jre
RUN groupadd ctf


COPY mr_game_and_watch.class /interpret.class
COPY flag.txt /
COPY entry.sh /

RUN useradd -G ctf --home=/ revuser
RUN useradd -G ctf --home=/ revflag

RUN chown revflag:revflag /interpret.class
RUN chown revflag:revflag /flag.txt

RUN chmod 4755 /interpret.class
RUN chmod 4755 /entry.sh
RUN chmod 444 /flag.txt

EXPOSE 30001
ENTRYPOINT ["/entry.sh"]
