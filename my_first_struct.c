#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100;

struct MyStruct {
    char code;
    struct MyStruct *next;
};

struct tnode {
    char *word;
    int count;
    struct tnode *left, *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
// char *strdup(char *);



struct MyStruct *create(int n)
{
    struct MyStruct *start = malloc(sizeof(struct MyStruct));
    start->code = 'A';
    printf("An element with code: %c was created\n", start->code);
    struct MyStruct *p, *q;
    
    p = start;
    int k;
    for (k=2; k<=n; k++) {
        q = malloc(sizeof(struct MyStruct));
        q->code = p->code + 1;
        p->next = q;
        
        printf("An element with code: %c was created\n", q->code);
        p = q;
    }
    
    p->next = 0;
    return start;
}

void show(struct MyStruct *start)
{
    while (start) {
        printf("%c\t%p\n", start->code, start->next);
        start = start->next;
    }
}

void delete(struct MyStruct *start)
{
    struct MyStruct *p = start->next;
    
    if (p != 0) {
        delete(p);
    }
    
    printf("Deleted struct with code: %c\n", start->code);
    free(start);
}

int main(void)
{
    // struct MyStruct *pnt = create(5);
    // show(pnt);
    // delete(pnt);


    struct tnode *root;
    char *words[] = {"test", "hi", "mama", "test", "hello", "window", "hi", "hi"};
    int n = 8;
    char **str = words;

    while (n-- > 0 && *str) {
        root = addtree(root, *str++);
    }
    treeprint(root);

    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        // p->word = w; // works also
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);

    return p;

}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// char *strdup(char *s)
// {
//     char *p;

//     p = (char *) malloc(strlen(s) + 1);
//     if (p != NULL)
//         strcpy(p, s);

//     return p;
// }
