#include <stdio.h>
#include "stdlib.h"
#include "ctype.h"

#ifndef MAXOP
#define MAXOP 100
#endif

#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);

int sp = 0, bufp = 0;
double val[MAXVAL];
char buf[BUFSIZE];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cannot push %g\n", f);
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty!\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;

    printf("s: %s\tc: %c\n", s, c);
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        printf("type: %c\ts: %s\n", type, s);
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: zero devisor!\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many chars!\n");
    } else {
        buf[bufp++] = c;
    }
}