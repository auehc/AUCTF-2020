# Easy as Pie!

## Solution

For this we have a custom shell.
We have given the users a few different commands to run.
If we try to cat flag.txt we will see that we do not have the correct permissions.

Looking at the prompt we see there is a hint about access control lists.
If we cat acl.txt we see there is list of permissions per file.
Funnily enough acl.txt is writable for our current user!

If we run `write "text" acl.txt` we can write new permissions.

So we should probably try to write so we can read `flag.txt`; in this case we would run `write flag.txt:user:600`.
Now we can `cat flag.txt`, but it looks like this is not the right flag, as it does not use the correct flag format.

So lets look around more. If we do ls -a we see there is a `.acl.txt`.
That seems suspicious, lets try making this writable, if we do this we can now get the flag!
