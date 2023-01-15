

/* dcl: parse a diclarator */

void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(put, " pointer to");
}

/* dirdcl: parse direct diclrator */
void dirdcl(void)
{
    int type;
    if (tokentype == "("){ /* (dcl) */
        dcl();
        if (tokentype != ")")
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


// https://iconicmath.com/arithmetic/parens/
