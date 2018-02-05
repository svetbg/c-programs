#include <stdio.h>
#include <string.h>

char name[500];
int cost[50];

void init() 
{
    int t;
    
    for (t=0; t<500; t++)
        name[t] = '\0';
}

void enter()
{
    char s[10];
    int place;

    for (place=0; place<50; place++) {
        if (!name[place*10])
            break;
    }

    if (place == 50) {
        printf("%s\n", "The list is full!");

        return;
    }

    printf("%s\n%s", "Please enter: ", "name of the record (up to 9 symbols");
    printf("%s\n", " space, value (<= +/- 32767)");

    scanf("%9s%d", &name[place*10], &cost[place]);
}

int find()
{
    char s[10];
    int place;

    printf("%s\n", "Please enter the name of the record: ");
    scanf("%9s", s);

    for (place=0; place<50; place++) {
        if (!strcmp(s, &name[place*10]))
            break;
    }

    if (place == 50) {
        printf("%s\n", "There is no such name in the list!");

        return(-1);
    }

    return place;
}

void display(int place)
{
    printf("%s %s %d\n", &name[place*10], "has value", cost[place]);
}

void update(int place)
{
    printf("%s\n%s", "Please enter: ", "name of the record (up to 9 symbols");
    printf("%s\n", " space, value (<= +/- 32767)");

    scanf("%9s%d", &name[place*10], &cost[place]);
}

 void delete(int place)
{
    printf("%s\n", "The record is deleted.");
    name[10*place] = '\0';
    cost[place] = 0;
}

int main(void)
{
    char ch;
    int record;
    init();

    do {
        printf("\n\n");
        printf("%s\n", "Main menu:");
        printf("\n\n%s\n\n", "1. Enter a new record");
        printf("%s\n\n", "2. Search for a name");
        printf("%s\n\n", "3. Edit a record");
        printf("%s\n\n", "4. Delete a record");
        printf("%s\n\n", "5. Exit to DOS");

        do {
            printf("%s", "Enter a number and <CR>:");
            ch = getchar();
        } while (ch < '1' || ch > '5');
        printf("\n");

        if (ch == '1') {
            enter();

            goto loop;
        }
        if (ch == '2') {
            record = find();
            if (record != -1)
                display(record);

            goto loop;
        }
        if (ch == '3') {
            record = find();
            if (record != -1)
                update(record);

            goto loop;
        }
        if (ch == '4') {
            record = find();
            if (record != -1)
                delete(record);

            goto loop;
        }

        loop: getchar();
    } while (ch != '5');
}