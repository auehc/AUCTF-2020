import cmd
from os import system


acl_file_path = "acl.txt"


class Shell(cmd.Cmd):
    intro = '<insert challenge description and intro here>'
    doc_header = 'Use help <command> for help on specific command.'
    prompt = 'user@pyshell$ '

    def can_read(self, perm):
        return perm >= 4

    def can_write(self, perm):
        return perm == 2 or perm >= 5

    def do_ls(self, args):
        '''
        List files in current directory. Refer to ls man page for arguments
        '''
        system(f"ls {args}")

    def do_man(self, args):
        '''
        View man page of command
        '''
        system(f"man {args}")

    def parse_acl(self, filename, logic):
        with open(acl_file_path) as f:
            for line in f:
                if filename in line:
                    perms = line.split(":")[2].strip()
                    if logic(int(perms[2])):
                        return True
                    elif line.split(":")[1] == "user" and logic(int(perms[0])):
                        return True
                    else:
                        return False

    def do_echo(self, args):
        filename = args.split(" ")[-1]
        can_edit = self.parse_acl(filename, self.can_write)
        if can_edit:
            system(f"echo {args}")
        else:
            print("Don't have da permzzz")

    def do_cat(self, args):
        '''
        View contents of file
        '''
        filename = args.split(" ")[-1]
        can_view = self.parse_acl(filename, self.can_read)
        if can_view:
            system(f"cat {args}")
        else:
            print("Don't have da permzzz")


if __name__ == '__main__':
    Shell().cmdloop()
