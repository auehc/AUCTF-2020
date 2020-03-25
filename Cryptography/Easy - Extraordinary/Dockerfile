FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat python python3 


RUN groupadd ctf


COPY extraordinary.py /
COPY entry.sh /entry.sh

RUN useradd -G ctf --home=/ cryptouser
RUN useradd -G ctf --home=/ cryptoflag

RUN chown cryptoflag:cryptoflag /extraordinary.py
RUN chown cryptoflag:cryptoflag / 

RUN chmod 4755 /extraordinary.py
RUN chmod 4755 /entry.sh


EXPOSE 30030
ENTRYPOINT ["/entry.sh"]
