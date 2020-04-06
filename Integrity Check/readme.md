During our ctf we had multiple issues of bad actors trying to break our boxes. So we used these scripts to ensure the boxes were still working. Otherwise they were reset.


Cronjobs
```
0 * * * * cd ~/AUCTF-2020/ && /bin/bash build.sh >> ~/build.log
*/3 * * * * /bin/bash ~/AUCTF-2020/Integrity\ Check/check-web2.sh >> ~/web.log
*/5 * * * * /bin/bash ~/AUCTF-2020/Integrity\ Check/bash_check.sh >> ~/bash.log
```
