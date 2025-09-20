#include "parser.h"

/// @brief Given a regular expression. Translate the expression into a readable form. (ex. [a-zA-Z]@gmail.com = heLLo@gmail.com)
/// @param parser a Graph pointer to be filled with nodes from the regular expression
/// @param regex an array of char (a string) containing the regular expression to be decoded
Node* post2nfa(char *postfix) {
    char *p;
    Fragment stack[1000], *stackp, e1, e2, e;
    Node *n;

    #define push(n) *stackp++ = n
    #define pop()   *--stackp

    stackp = stack;
    for(p=postfix; *p; p++) {
        switch(*p) {
            case '.':
                e2 = pop();
                e1 = pop();
                patch(e1.out, e2.start);
                push(Fragment(e1.start, e2.out));
                break;
            case '|':
                e2 = pop();
                e1 = pop();
                n = node(SPLIT, e1.start, e2.start);
                push(Fragment(n, append(e1.out, e2.out)));
                break;
            case '?':
                e = pop();
                n = node(SPLIT, e.start, NULL);
                push(Fragment(n, append(e.out, list1(&n->right))));
                break;
            case '*':
                e = pop();
                n = node(SPLIT, e.start, NULL);
                patch(e.out, n);
                push(Fragment(n, list1(&n->right)));
                break;
            case '+':
                e = pop();
                n = node(SPLIT, e.start, NULL);
                patch(e.out, n);
                push(Fragment(n, list1(&n->right)));
                break;
            default:
                n = node(*p, NULL, NULL);;
                push(Fragment(s, list1(&n->left)));
                break;
        }
    }
    e = pop();
    patch(e.out, matchstate);
    return e.start;
    #undef pop
    #undef push
}