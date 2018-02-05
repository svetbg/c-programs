#include "stdio.h"

#define square(x) (x) * (x)

int main()
{
    int x = 9;
    printf("%d\n", square(x+1));
}