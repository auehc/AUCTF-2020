Oops
--

Open vhdx file using 7zip or alternatively you can binwalk and extract the initrd.gz file. 

Extract initrd.gz
```file initrd```
Extract the cpio archive
```cpio -idv < initrd```
Flag is hidden as the 'cat' binary in /bin/ 
```cd /bin/ && cat ./cat```
siica{rul_nbkf_vsrnog_vx}

My friend 'c' who is chharles on Github: 
https://github.com/chharles/AUCTF-2020/commits/master
use the key.txt "soGJvcjTknXM" to solve the Vigenère cipher


Also the flag is also in initrd, /usr/bin/find left it there by accident :)


Flag: auctf{pls_dont_delete_me}