import cmd
from os import system


class File():

    def __init__(self, name, content):
        self.name = name
        self.content = content

    def can_read(self, perm):
        return perm >= 4

    def can_write(self, perm):
        return perm == 2 or perm >= 5

    def parse_acl(self, acl, filename, logic):
        for entry in acl.content:
            entry_filename = entry.split(":")[0]
            if filename == entry_filename:
                perms = entry.split(":")[2].strip()
                if logic(int(perms[2])):
                    return True
                elif entry.split(":")[1] == "user" and logic(int(perms[0])):
                    return True
                else:
                    return False

    def get_file_contents(self, acl):
        if self.parse_acl(acl, self.name, self.can_read):
            if isinstance(self.content, list):
                for elem in self.content:
                    print(elem)
            else:
                print(self.content)
        else:
            print("Don't have da permzzz")

    def write(self, acl, content):
        if self.parse_acl(acl, self.name, self.can_write):
            if isinstance(self.content, list):
                self.content.insert(0, content)
            else:
                self.content = content + self.content
        else:
            print("Don't have da permzzz")

    def __str__(self):
        return self.name


files = [
    File("acl.txt", ["user.txt:user:600", ".acl.txt:root:600",
                     ".flag.txt:user:600", "flag.txt:root:600", "acl.txt:root:606"]),
    File(".acl.txt", "auctf{h4_y0u_g0t_tr0ll3d_welC0m#_t0_pWN_l@nd}"),
    File(".flag.txt", "nope not here sorry :)"),
    File("user.txt", "this is some user content. I bet u wish the flag was here"),
    File("flag.txt", "aUctf_{h3y_th3_fl4g_\:\(¯}")
]


class Shell(cmd.Cmd):
    intro = 'Welcome to my custom shell written in Python! To get started type `help`'
    doc_header = 'Use help <command> for help on specific command.'
    prompt = 'user@pyshell$ '

    def do_ls(self, args):
        '''
        List files in current directory.
        Can type `ls hidden` to view hidden files
        '''
        if args == "hidden":
            for file in files:
                print(file)
        else:
            for file in files:
                if file.name[0] != ".":
                    print(file)

    def do_write(self, args):
        '''
        write <content> <filename>
        adds content to the beginning of the file.
        '''
        filename = args.split(" ")[-1]
        for file in files:
            if file.name == filename:
                print(args.split(" ")[0])
                file.write(files[0], args.split(" ")[0])

    def do_cat(self, args):
        '''
        View contents of file
        '''
        filename = args.split(" ")[-1]
        for file in files:
            if file.name == filename:
                file.get_file_contents(files[0])


if __name__ == '__main__':
    Shell().cmdloop()
