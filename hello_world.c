#include <stdio.h>

char *month_name(int n)
{
    char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

int *get_rand_number()
{
    static int num = 5;

    return &num;
}

int main(void) {

    int *num;
    num = get_rand_number();

    int a[] = {1, 2};
    int b[] = {3, 4};
    int *pa = a;
    int *pb = b;

    printf("%d\t%d\n", *pa++, *++pb);

    *num = 6;
    num = get_rand_number();

	printf("%s\n", "Hello world!");

    printf("%s\n", month_name(2));

    printf("%d\n", *num);
}