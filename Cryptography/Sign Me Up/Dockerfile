FROM 32bit/ubuntu:16.04

RUN apt-get update
RUN apt-get install -y socat python python3


RUN groupadd ctf


COPY pick_your_poison.py /
COPY entry.sh /entry.sh

RUN useradd -G ctf --home=/ cryptouser
RUN useradd -G ctf --home=/ cryptoflag

RUN chown cryptoflag:cryptoflag /pick_your_poison.py
RUN chown cryptoflag:cryptoflag /

RUN chmod 4755 /pick_your_poison.py
RUN chmod 4755 /entry.sh


EXPOSE 30031
ENTRYPOINT ["/entry.sh"]
