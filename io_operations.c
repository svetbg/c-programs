#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) /* lower: convert input to lower case */
{
    FILE *fp;
    void filecpy(FILE *, FILE *);
    char *prog = argv[0];

    if (argc == 1)
        filecpy(stdin, stdout);
    else
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n" ,prog, *argv);
                exit(1);
            } else {
                filecpy(fp, stdout);
                if (argc > 1)
                    printf("\n************************************************************\n");
                fclose(fp);
            }
        }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing to stdout\n", prog);
        exit(2);
    }

    exit(0);
}

void filecpy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}