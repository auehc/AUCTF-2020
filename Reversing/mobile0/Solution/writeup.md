# Mobile0

## Solution

Upon researching online for some Android reversing tools you could have found a tool called `apktool`. That tool allows us to view the contents of the apk file. So run `apktool d mobile0.apk` for decoding the apk file. After `apktool` has run, there will be a folder called `mobile0`. Inside there is a `res` folder which also has a `values` folder. So the important path is `mobile0/res/values` because this contains `strings.xml` which contains the strings in an android application. Which means, that it contains our flag of: `auctf{m0b1le_r3v3rs1ng!!}`
