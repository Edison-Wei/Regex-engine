#include "util.h"

// Node constructor
Node* node(int character, Node *out, Node* out1) {
    Node *new_node = malloc(sizeof(Node));
    new_node->character = character;
    new_node->left = out;
    new_node->right = out;
    
    return new_node;
}

// Fragment constructor
Fragment fragment(Node *start, Ptrlist *out) {
    Fragment frag = { start, out };
    return frag;
}

Ptrlist *list1(Node **output) {
    Ptrlist *l;
    l = (Ptrlist*)output;
    l->next = NULL;
    return l;
}

Ptrlist *append(Ptrlist *list1, Ptrlist *list2) {
    Ptrlist *oldList1;

    oldList1 = list1;
    while(list1->next) {
        list1 = list1->next;
    }
    list1->next = list2;
    return oldList1;
}

void patch(Ptrlist *list, Node *node) {
    Ptrlist *next;

    for (; list; list=next) {
        next = list->next;
        list->node = node;
    }
}