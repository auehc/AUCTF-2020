Block2
--

First you need to create a database to put the table in. 
```CREATE DATABASE temp;```

Then take the .sql file and put in the database.
```source /path/to/database/file/co_block.sql```

Then use the database you created
```USE temp;```

Finally find all the rows where rolled_back = 1 
```SELECT * FROM co_block WHERE rolled_back = 1```

Only one row meets those parameters and it has the unix timestamp of: 1581060905

Insert the timestamp into the flag format. 

Flag: auctf{1581060905}


