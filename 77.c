#include <stdio.h>
#include <stdlib.h>

int *pi;
int *pimin;

void pushi(int i)
{
    if (pi == (pimin + 10)) {
        printf("The stack is full!\n");
        return;
    }

    *pi = i;
    pi++;
}

int popi()
{
    int i;
    if (pi == pimin) {
        printf("The stack is empty!\n");
        return 0;
    }

    pi--;
    i = *pi;

    return i;
}

int main(void)
{
    // char *malloc();
    pi = (int *) malloc(20);
    pimin = pi;
    pushi(10);
    pushi(20);

    printf("The second number is: %d\n", popi());
    printf("The first number is: %d\n", popi());
}