#include <stdio.h>
#include "match.h"

int match(Graph *graph, char *string) {
    Node *left_node = graph->nodes->left;
    Node *right_node = graph->nodes->right;
    int left_match = 0;
    int right_match = 0;

    do {
        int character = (int)string[0];
        if (left_node != NULL) {
            if (left_node->character == character) {
                left_node = left_node->left;
            }
            if (left_node->character == GOAL){
                left_match = 1;
            }
        }
        if (right_node != NULL) {
            if (right_node->character == character) {
                right_node = right_node->left;
            }
            if (right_node->character == GOAL){
                right_match = 1;
            }
        }

        string++;

    } while (string[0] != '\0');
    
    return (left_match || right_match) ? 1 : 0;
}