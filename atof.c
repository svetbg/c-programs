#include <ctype.h>
#include <stdio.h>

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0'); // s[i] - '0' is used to get the integer equivalence of the s[i] char
    }
    
    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

int main()
{
    char line[20] = "    +25.65555";

    double ff = atof(line);

    printf("%d\n", '5');
    printf("%f\n", ff);
}