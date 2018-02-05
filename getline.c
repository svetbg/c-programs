#include <stdio.h>
#include <string.h>
#define MAXLINE 10 /* maximum input line length */

int getline1(char line [], int max);
int getline2(char line [], int max);
void copy(char dest[], char src[]);

/* find all lines matching pattern */
int main( )
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int len, max;

    int decrease_before = 0;
    int decrease_after = 0;
    printf("before: %d : %d\tafter: %d : %d\n", --decrease_before, decrease_before, decrease_after--, decrease_after);

    while ((len = getline1(line, MAXLINE)) > 1) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        printf("line: %s len: %d max: %d\n", line, len, max);
    }
    
    if (max > 0)
        printf("line: %s\tmax: %d\n", longest, max);
}

/* getline: get line into s, return length */
int getline1(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim> 0 && (c=getchar()) != EOF && c != '\n') {
        //printf("%d\n", lim);
        s[i++] = c;
    }
    if (c == '\n' )
        s[i++] = c;
    s[i] = '\0';

    return i;    
}

int getline2(char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i]= '\0';
    return i;
}

void copy(char d[], char s[])
{
    int i = 0, j = 0;


    while ((d[i++]=s[j++]) != '\0');
}