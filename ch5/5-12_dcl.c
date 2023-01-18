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
int bufp = 0;

int main() /* convert declarations to words */
{
    while (gettoken() != EOF) /* 1st token on line */
    {
       printf("main: %s\n", token); 
       strcpy(datatype, token); /* is the datatype */
       out[0] = '\0';
       dcl(); /* parse rest of line */
       if (tokentype != '\n')
           printf("main: syntax error\n");
       printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    //printf("before if %c\n",*p);
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
        //printf("0 %c\n%c\n%s\n",c ,p[0], token);
        //*p++ = c;
        printf("1 %c\n%c\n%s\n",c ,p[0], token);
        
        for (*p++ = c, printf("2 %c\n%c\n%s\n",c ,p[0], token); isalnum(c = getch()); )
        {
            //printf("name b/ %c %c\n",c, *p);
            *p++ = c;
            printf("3 %c\n%c\n%s\n",c ,p[0], token);
        }
        *p = '\0';
        printf("4 %c\n%c\n%s\n",c ,p[0], token);
        ungetch(c);
        printf("5 %c\n%c\n%s\n",c ,p[0], token);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

#define BUFSIZE 100
//93
//139

char buf[BUFSIZE];

int getch(void) /* get a (possibly pushbacrk) char */
{
    char _c;
    //return (bufp > 0) ? token[--bufp]: getchar(); 
    if (bufp > 0)
        _c = buf[--bufp];
    else
        _c = getchar(); 

    //printf("getch: %c\n", _c);
    return _c;
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too much characters\n");
    else
        buf[bufp++] = c;
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
    {
        printf("dirdcl(NAME): %s\n", token);
        strcpy(name, token);
    }
    else
        printf("ERROR: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}
