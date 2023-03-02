#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my_dirent.h"
//#include "dirent.h"
#include <stdlib.h>

void fsize(char *);

// print file sized
main(int argc, char **argv)
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

//int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

// fsize: print size of file "name"
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1)
    {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

// dirwalk: apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    my_Dirent *dp;
    my_DIR *dfd;

    if ((dfd = my_opendir(dir)) == NULL)
    {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = my_readdir(dfd)) != NULL)
    {
        if (strcmp(dp->name, ".") == 0
         || strcmp(dp->name, ".") == 0)
            continue; // skip self and parent
        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s %s too long\n",
                    dir, dp->name);
        else
        {
            sprintf(name, "%s %s", dir, dp->name);
            (*fcn)(name);
        }
        my_closedir(dfd);
    }

}

int fstat(int fd, struct stat *);

// opendir: open a directory for readdir calls
my_DIR *my_opendir(char *dirname)
{
    int fd;
    struct stat stbuf;
    my_DIR *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
            || fstat(fd, &stbuf) == -1
            || (stbuf.st_mode & S_IFMT) != S_IFDIR
            || (dp = (my_DIR *) malloc(sizeof(my_DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}

// closedir: close directory opened by opendir
void my_closedir(my_DIR *dp)
{
    if (dp)
    {
        close(dp->fd);
        free(dp);
    }
}

#include <sys/dir.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

// readdir: read directory entries in sequence
my_Dirent *my_readdir(my_DIR *dp)
{
    struct direct dirbuf; // local directory structure
    static my_Dirent d; // return: portable structure

    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
            == sizeof(dirbuf))
    {
        if (dirbuf.d_ino == 0) // slot not in use
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0'; // ensure termination
        return &d;
    }
    return NULL;
}
