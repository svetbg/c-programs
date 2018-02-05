#include "stdio.h"
#include "stdlib.h"

int cmpstr(char *s1, char *s2)
{    
    while (*s1) {
        //printf("*s1: %d  s1: %s\n", *s1, s1);
        
        if (*s1++ != *s2++) {

            return *(s1--);
        }
    }

    if (*s2) {
        return (*s2);
    }
    return 0;
}

int strlen1(char *s)
{
    char *p = s;
    
    while (*++p) {
        
    }
    
    return p - s;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

#define SIZE 30000

void bubble_sort()
{
    int my_array[SIZE];
    int i, j, k;

    srand(5);
    for (i=0; i<SIZE; i++) {
        my_array[i] = rand()%3214;
        //printf("%2d\n", my_array[i]);
    }

    for (j=1; j < SIZE-1; j++) {
        for (i=0; i<SIZE-j; i++) {
            if (my_array[i] > my_array[i+1]) {
                k = my_array[i];
                my_array[i] = my_array[i+1];
                my_array[i+1] = k;
            }
        }
    }

    for (i=0; i<SIZE; i++) {
        //printf("my_array[%d]=%2d\n", i, my_array[i]);
    }
}

void bubble_sort_swap_check()
{
    int my_array[SIZE];
    int i, j=0, k;
    int swapped = 1;

    srand(5);
    for (i=0; i<SIZE; i++) {
        my_array[i] = rand()%3214;
        //printf("%2d\n", my_array[i]);
    }

    while (swapped) {
        swapped = 0;
        j++;
        for (i=0; i<SIZE-j; i++) {
            if (my_array[i] > my_array[i+1]) {
                k = my_array[i];
                my_array[i] = my_array[i+1];
                my_array[i+1] = k;

                swapped = 1;
            }
        }
    }

    for (i=0; i<SIZE; i++) {
        //printf("my_array[%d]=%2d\n", i, my_array[i]);
    }
}

void bubble_sort_pointer()
{
    int *my_array, tmp_arr[SIZE];
    int i, j;

    my_array = tmp_arr;

    srand(5);
    for (i=0; i<SIZE; i++) {
        *(my_array+i) = rand()%3214;
        //printf("%2d\n", my_array[i]);
    }

    for (j=1; j < SIZE-1; j++) {
        for (i=0; i<SIZE-j; i++) {
            if (*(my_array+i) > *(my_array+i+1)) {
                int k = *(my_array+i);
                *(my_array+i) = *(my_array+i+1);
                *(my_array+i+1) = k;
            }
        }
    }

    for (i=0; i<SIZE; i++) {
        //printf("my_array[%d]=%2d\n", i, my_array[i]);
    }
}

int v[10] = {1, 6, 3, 14, 5, 7, 19, 13, 15, 2};
/* shellsort: sort v[0] ...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap> 0; gap /= 2) {
        printf("gap: %d\n", gap);
        for (i = gap; i < n; i++) {
            printf("\ti: %d\n", i);
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                printf("\t\tj: %d\n", j);
                printf("\t\t\tv[%d]=%d <-> v[%d]=%d\n", j, v[j], j+gap, v[j+gap]);
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                
            }
        }
    }
}

void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    /* record sign */
    /* make n positive */
    int j = 0;
    do {
        int j;
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';
        printf("s[%d]=%c\t%d\n", j, s[j], n);
        j++;
        /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
}

void main(int argc, char *argv[])
{
    
    int c, except = 0, number = 0, found = 0, tmp, old;

    int test_arr[SIZE];
    char ss;



    srand(5);
    for (int i=0; i<SIZE; i++) {
        test_arr[i] = rand()%3214;
        //printf("%2d\n", my_array[i]);
    }

    char str[10];

    printf("%c\n", 8);

    itoa(530, str);
    printf("%s\n", str);


    //*/
    // shellsort(test_arr, SIZE);
    //shellsort(v, 10);
    // for (int ii=0; ii < SIZE; ii++) {
    //     printf("v[%d]=%d\n", ii, test_arr[ii]);
    // }
    /*/
    bubble_sort_pointer();
    //*/

    //printf("%d\n", strlen1("This is a test"));
}