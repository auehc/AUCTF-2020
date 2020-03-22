import cmd
from os import system


acl_file_path = "acl.txt"
class Shell(cmd.Cmd):
    intro = '<insert challenge description and intro here>'
    doc_header = 'Use help <command> for help on specific command.'
    prompt = 'user@shell$ '

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
    
    def parse_acl(self, filename):
        with open(acl_file_path) as f:
            for line in f:
                if filename in line:
                    perms = line.split(":")[2].strip()
                    if int(perms[2]) >= 4:
                        return True
                    elif line.split(":")[1] == "user" and int(perms[0]) >= 4:
                        return True
                    else:
                        return False

    def do_cat(self, args):
        '''
        View contents of file
        '''
        can_view = self.parse_acl(args)
        if can_view:
            system(f"cat {args}")
        else:
            print("Don't have da permzzz")
    
    def do_nano(self, args):
        '''
        Open up file in nano
        '''
        system(f"nano -R {args}")


if __name__ == '__main__':
    Shell().cmdloop()