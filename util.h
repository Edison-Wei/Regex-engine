#if !defined(UTILS)
#define UTILS

#include <stdio.h>
#include <stdlib.h>

#define GOAL 1
#define SPLIT 2
typedef struct Node Node;
typedef union Ptrlist Ptrlist;
typedef struct Fragment Fragment;

struct Node{
    int character;
    Node *left; // output
    Node *right; //output2
    int lastlist;
};

struct Fragment {
    Node *start;
    Ptrlist *out;
};
Fragment fragment(Node *start, Ptrlist *out);

union Ptrlist {
    Ptrlist *next;
    Node *node;
};

#endif // UTILS
