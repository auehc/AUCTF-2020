from ubuntu:latest

copy flag flag.file
run apt-get update -y && apt-get install -y apache2 wget gcc make && a2enmod cgi && \
  wget https://ftp.gnu.org/gnu/bash/bash-4.3.tar.gz && mv bash-4.3.tar.gz /opt/
workdir /opt/
run tar -xvf /opt/bash-4.3.tar.gz
workdir /opt/bash-4.3
run ls -al && ./configure && make && ln -sf /opt/bash-4.3/bash /bin/bash_shellshock
copy myscript /usr/lib/cgi-bin/scriptlet
entrypoint service apache2 start && /bin/bash
expose 80
