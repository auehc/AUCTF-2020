# AUCTF 2020 BASH Challenges

## BASH 1
We `ssh` into the box with `ssh challenges.auctf.com -p 30040 -l level1` with
password `aubie`. When we login to the box, we can `ls` the directory. We can
see that there is a README file that we have read access to. `cat README`.

## BASH 2
Once we login to `level2` with the flag for `level1`, we are able to see that
there is a script named `random_dirs.sh`. If we look at this script with `cat`,
we can see what commands are being run. Running `ls -al` on the directory also
tells us the users for the respective files in the directory. Using this knowledge,
we can see that we don't have read access to flag.txt, and that is permission is
granted to `level3`. We can run `sudo -l` to see if we are able to run the program
as the user `level3`. This output shows that we are able to run the script without
a password as user `level3`. Thus we can solve the challenge with `sudo -u level3 ./random_dirs.sh & cat /tmp/*`.

## BASH 3
We start off this box like any other and login to `level3`. The directory contains
a script that expects a passcode to print the file. We can write a quick brute
force script with the following `while [[ 1 == 1 ]];do echo '0' | sudo -u level4 ./passcodes.sh; done | grep auctf`.
This may take a while to run, but should print our flag when it guesses correctly.

Unintended solution: just input `x`, as `$input` equals with `$x`.

## BASH 4
This box is very easy. Log in with `level4`. We can see that the `level4` can execute a script that calls
cat. We can print out the flag by running `sudo -u level5 ./print_file.sh`

## BASH 5
We can solve this challege similarly to `level3`. This time, we can have the script listening in the background.
`sudo ./port_force.sh & nc -z localhost 1024-65535`. Again we'll wait for this to run, and get our flag. 
