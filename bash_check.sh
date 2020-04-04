#!/bin/bash

for i in {2..5}
do
	x=`sudo docker exec auctf-2020_bash_1 /usr/bin/sha256sum /home/level$i/flag.txt| cut -d " " -f 1`
	y=`sha256sum /home/ctf/AUCTF-2020/Bash/level$i/flag.txt | cut -d " " -f 1`
	# echo "OUTPUT:"
	# echo `sudo docker exec auctf-2020_bash_1 /usr/bin/sha256sum /home/level$i/flag.txt`
	# echo "DONE"
	if [[ ! $x == $y ]]
	then
		echo "$i broken"
		# echo "'$x'"
		# echo "'$y'"
		sudo docker container rm -f auctf-2020_bash_1
		sudo docker run -dit -p 30040:22 --name auctf-2020_bash_1 auctf-2020_bash
	else
		echo "$i not broken"
	fi
done

# docker exec -it auctf-2020_bash_1 /usr/bin/sha256sum /home/level2/random_dirs.sh | cut -d " " -f 1
# docker exec -it auctf-2020_bash_1 /usr/bin/sha256sum /home/level3/passcodes.sh | cut -d " " -f 1
# docker exec -it auctf-2020_bash_1 /usr/bin/sha256sum /home/level4/print_file.sh | cut -d " " -f 1
# docker exec -it auctf-2020_bash_1 /usr/bin sha256sum /home/level5/portforce.sh | cut -d " " -f 1
