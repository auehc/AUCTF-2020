FROM ubuntu:latest

RUN apt-get update && apt-get install -y socat default-jre
RUN groupadd ctf


COPY mr_game_and_watch.class /mr_game_and_watch.class
COPY flag.txt /
COPY entry.sh /

RUN useradd -G ctf --home=/ revuser
RUN useradd -G ctf --home=/ revflag

RUN chown revflag:revflag /mr_game_and_watch.class
RUN chown revflag:revflag /flag.txt

RUN chmod 4755 /mr_game_and_watch.class
RUN chmod 4755 /entry.sh
RUN chmod 444 /flag.txt

EXPOSE 30001
ENTRYPOINT ["/entry.sh"]
