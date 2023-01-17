#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;          /* type of last token */
char token[MAXTOKEN];   /* last token string*/
char name[MAXTOKEN];    /* identifiyer name */
char datatype[MAXTOKEN];/* data type = char, int etc */
char out[1000];          /* output string */

main() /* convert declarations to words */
{
    while (gettoken() != EOF) /* 1st token on line */
    {
       strcpy(datatype, token); /* is the datatype */
       out[0] = '\0';
       dcl(); /* parse rest of line */
       if (tokentype != '\n')
           printf("syntax error\n");
       printf("%s: %s %s", name, out, datatype);
    }
    return 0;
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } 
}

#define BUFSIZE 100
char buf[BUFSIZE]; // token?
int bufp = 0;

int getch(void) /* get a (possibly pushbacrk) char */
{
    //return (bufp > 0) ? buf[--bufp]: getchar(); 
    return (bufp > 0) ? token[--bufp]: getchar(); 
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too much characters\n");
    else
        token[bufp++] = c;
}

/* dcl: parse a diclarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse direct diclrator */
void dirdcl(void)
{
    int type;
    if (tokentype == '('){ /* (dcl) */
        dcl();
        if (tokentype != ')')
            printf("ERROR: missing )\n");
    } else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("ERROR: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " functio returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}


