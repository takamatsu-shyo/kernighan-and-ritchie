#define NAME_MAX 14 // longest filename component
                    // system dependent

typedef struct{             // portable directory entry
    long ino;               // inode number
    char name[NAME_MAX+1];  // name + '\0' terminator
} my_Dirent;

typedef struct{     // minimal DIR: no bufering, etc
    int fd;         // file descriptor for directory
    my_Dirent d;       // the directory entry
} my_DIR;

my_DIR *my_opendir(char *dirname);
my_Dirent *my_readdir(my_DIR *dfd);
void my_closedir(my_DIR *dfd);
