from ubuntu:latest

run apt-get update && apt-get install -y openssh-server sudo vim netcat nano && mkdir /var/run/sshd && \
  echo "root:campbellsnowvanrellharper" | chpasswd && useradd -m level1 && \
  useradd -m level2 && useradd -m level3 && useradd -m level4 && useradd -m level5 && \
  echo "level1:aubie" | chpasswd && echo "level2:auctf{W3lcoM3_2_da_C7F}" | chpasswd && \
  echo "level3:auctf{g0tt@_muv_fas7}" | chpasswd && echo "level4:auctf{wut_r_d33z_RaNdom_numz}" \
  | chpasswd && echo "level5:auctf{FunKy_P3rm1ssi0nZ}" | chpasswd \
  && echo "level2 ALL=(level3) NOPASSWD:/home/level2/random_dirs.sh" >> /etc/sudoers \
  && echo "level3 ALL=(level4) NOPASSWD:/home/level3/passcodes.sh" >> /etc/sudoers \
  && echo "level4 ALL=(level5) NOPASSWD:/home/level4/print_file.sh" >> /etc/sudoers \
  && echo "level5 ALL=(ALL) NOPASSWD:/home/level5/portforce.sh" >> /etc/sudoers

run rm -rf /usr/bin/wall

add level1 /home/level1
add level2 /home/level2
add level3 /home/level3
add level4 /home/level4
add level5 /home/level5

run chown level3:level2 /home/level2/random_dirs.sh && chmod 550 /home/level2/random_dirs.sh \
  && chown level3:level3 /home/level2/flag.txt && chmod 2550 /home/level2/level2_runner \
  && chmod 440 /home/level2/flag.txt && chown level4:level3 /home/level3/passcodes.sh \
  && chown level4:level4 /home/level3/flag.txt && chmod 440 /home/level3/flag.txt \
  && chmod 550 /home/level3/passcodes.sh && chown level5:level4 /home/level4/print_file.sh \
  && chown level5:level5 /home/level4/flag.txt && chmod 440 /home/level4/flag.txt \
  && chmod 550 /home/level4/print_file.sh && chmod 2550 /home/level4/level4_runner \
  && chown root:root /home/level5/flag.txt && chown root:level5 /home/level5/portforce.sh \
  && chmod 440 /home/level5/flag.txt && chmod 550 /home/level5/portforce.sh \
  && chmod 2550 /home/level5/level5_runner && chmod -w /home/* &&  rm /home/*/*.c \
  && rm /home/*/*_runner && chown root:root /home/* 

expose 22
cmd ["/usr/sbin/sshd", "-D"]
