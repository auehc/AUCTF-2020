Boom
--

Extract the .gz file to reveal a sql dump, inside the table there is a .7z file containing an image. Import the mySQL table to reassemble the 7z file.

```mysql -u user -p'fdsafds' -e "USE test; SELECT image FROM images INTO DUMPFILE '/tmp/boom';"```

Alot of people where having trouble with this because they either redirected the output like this 

```"select image from images;" > flag.7z,```

or used into outfile like this

```select image into outfile '/tmp/flag.7z' from images```

If you use INTO DUMPFILE instead of INTO OUTFILE, MySQL writes only one row into the file, without any column or line termination and without performing any escape processing. This is useful if you want to store a BLOB value in a file.

https://dev.mysql.com/doc/refman/8.0/en/select-into.html

Alternative way: import table and using myphpadmin or adminer and download the file. 

Alternative way: create a php script to read the contents of the table

Extract the 7z file to reveal the image. Finally, decrease the brightness and increase the contrast of the image to reveal the flag.
https://gchq.github.io/CyberChef/#recipe=Image_Brightness_/_Contrast(-58,50)

Flag: auctf{B00M_!!}
