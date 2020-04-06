# Mobile1

## Solution

Running the linux command `file` on the file reveals that its _just_ a zip file. Meaning we can just run `unzip` on the file. Running `unzip` on it creates a folder called `Payload` which contains a folder called `mobile1.app`.

From here there are 2 paths to getting the flag:
1. Running `strings` utility on `Info.plist` which will give the flag. `Info.plist` is just an file used by Apple to contain App Info
2. The other way is to view the storyboard of the app. A storyboard is essentially a screen of the iPhone app. By going into the `Base.lproj/Main.storyboardc/` folder we will see 3 files. The important file is `BYZ-38-t0r-view-8bC-Xf-vdC.nib` but we have to run `strings` on it since it contains binary data. 

Following either methods gives you the flag: `auctf{i0s_r3v3rs1ng_1s_1nt3r3st1ng}`