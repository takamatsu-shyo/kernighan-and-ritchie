#include <stdlib.h>
#include <stdio.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; // found
    return NULL; // not found
}

char *strdup(char *);

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) // not found
    {
        np = (struct nlist *) malloc (sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        printf("%u\n", hashval);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else  // already there
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
   return np; 
}

main()
{
    const char *names[5];
    names[0] = "x";
    names[1] = "y";
    names[2] = "w";
    names[3] = "h";
    names[4] = "x";

    const char *defines[5];
    defines[0] = "x";
    defines[1] = "y";
    defines[2] = "width";
    defines[3] = "height";
    defines[4] = "x";


    printf("%u\n", install(names[0], defines[0]));
    printf("%u\n", install(names[1], defines[1]));
    printf("%u\n", install(names[2], defines[2]));
    printf("%u\n", install(names[3], defines[3]));
    printf("%u\n", install(names[4], defines[4]));
    printf("all in\n");
    
    struct nlist *np;
    for (int i = 0; i < 5; i++)
    {
        printf("%u\n", hash(names[i]));
        printf("%s %s\n", hashtab[hash(names[i])]->name, hashtab[hash(names[i])]->defn);
    }
}
