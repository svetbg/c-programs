#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void show(int a[], int n)
{
    int i;

    for (i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int i, j, c;
    int A[2][SIZE] = {{10, 20, 30}, {40, 50, 60}};
    int B[4][SIZE] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};
    int A1[SIZE] = {1, 2, 3};

    char *C[] = {"I'm sym C programist!", "Az ucha ezik za programirane C", "abc"};

    int *pa[SIZE]; // an array of int pointers
    int (*pnt)[SIZE]; // a pointer to an array of int

    // printf("%s\t%s\n", *++C, C[0]);

    pnt = A;
    show(pnt[0], SIZE);
    pnt = &A1;
    pa[0] = &A1[0];
    show(*pnt, SIZE);

    char **str;
    str = C;

    // for (j=0; j<2; j++) {
    //     printf("%s\n", *str++);
    // }
    // printf("%c\n", (*++str)[0]);
    // printf("%c\n", (*str++)[0]);
    // printf("%c\n", (*++str)[0]);
    // while ((*str++)[0]) {
    //     printf("%c\n", *str[0]);
    // }

    char **tmp = str;
    for (i=0; i<argc; i++) {
        // printf("%s\n", *argv++);
    }

    printf("%c\n", (*++str)[0]);
    str = tmp;
    printf("%c = ", (*str)[1]);
    str = tmp;
    printf("%c\n", *++str[0]);
    str = tmp;

    while (--argc > 0 && (*++argv)[0] == '-') {
        printf("%c\n", *argv[0]);
        while (c = *++argv[0]){
            printf("%c\n", c);
        }
    }

    // pa = A;
    // for (i=0; i<2; i++) {
    //     for (j=0; j<SIZE; j++) {
    //         printf("%d ", pa[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // pa = B;
    // for (i=0; i<4; i++) {
    //     for (j=0; j<SIZE; j++) {
    //         printf("%d ", pa[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}