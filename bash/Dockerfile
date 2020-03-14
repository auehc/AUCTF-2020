from ubuntu:latest

run apt-get update && apt-get install -y openssh-server && mkdir /var/run/sshd \
	echo "root:campbellsnowvanrellharper" | chpasswd && useradd -m level1 && \
	useradd -m level2 && useradd -m level3 && useradd -m level4 && useradd -m level5 && \
	echo "level1:aubie" | chpasswd && echo "level2:auctf{W3lcoM3_2_da_C7F}" | chpasswd && \
	echo "level3;auctf{g0tt@_muv_fas7}" | chpasswd && echo "level4:auctf{wut_r_d33z_RaNdom_numz}" | chpasswd && \
	echo "level5:auctf{n3tc@_purt_\$can}" | chpasswd

add level1 /home/level1
add level2 /home/level2
add level3 /home/level3
add level4 /home/level4
add level5 /home/level5

run chown level3:level2 /home/level2/random_dirs.sh && chmod 550 random_dirs.sh && \
  chown level3:level3 /home/level2/flag.txt && chmod g+s random_dirs.sh && chmod 400 /home/level2/flag.txt \
  chown level4:level3 /home/level3/passcodes.sh && chown level4:level4 /home/level4/flag.txt && \
  chmod 400 /home/level3/flag.txt && chmod 550 /home/level3/passcodes.sh && chmod g+s passcodes.sh && \
  chown level5:level4 /home/level4/print_file.sh && chown level5:level5 /home/level4/flag.txt && \
  chmod 400 /home/level4/flag.txt && chmod 550 /home/level4/print_file.sh && chmod g+s /home/level4/print_file.sh && \
  chown root:root /home/level5/flag.txt && chown root:level5 /home/level5/portforce.sh && \
  chmod 400 /home/level5/flag.txt && chmod 550 /home/level5/portforce.sh && \
  chmod g+s /home/level5/portforce.sh && \
  chmod -w /home/* && chmod o-r /home/*

expose 22
cmd ["/usr/sbin/sshd", "-D"]
