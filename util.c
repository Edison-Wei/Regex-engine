#include <stdio.h>
#include <stdlib.h>
#include "util.h"

struct Node{
    int character;
    struct Node *left; // output
    struct Node *right; //output2
    // int lastlist; Maybe

};

struct Graph{
    Node *nodes;
    int length_of_nodes; // Counts number of nodes excluding goal node

    void (*free_nodes)(Graph *);
    void (*add_node_left)(Graph *, int character);
    void (*add_node_right)(Graph *, int character);
    void (*loop_to_start)(Graph *);
    void (*loop_node)(Graph *);
};

// Node constructor
Node* node() {
    Node *new_node = malloc(sizeof(Node));
    new_node->character = EMPTY;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

Node *add_goal_nodes() {
    Node *head_node = node();
    Node *left_goal_node = node();
    Node *right_goal_node = node();

    left_goal_node->character = GOAL;
    right_goal_node->character = GOAL;
    
    head_node->left = left_goal_node;
    head_node->right = right_goal_node;

    return head_node;
}

Graph *graph() {
    Graph *graph = malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->length_of_nodes = 0;

    graph->add_node_left = add_node_left;
    graph->add_node_right = add_node_right;
    graph->free_nodes = free_nodes;
    graph->loop_to_start = loop_to_start;
    graph->loop_node = loop_node;
}

void add_node_left(Graph *self, int character) {
    Node *curr_node = self->nodes;
    Node *new_node = node();
    new_node->character = character;

    if (curr_node == NULL) {
        self->nodes = add_goal_nodes();

        new_node->left = curr_node->left;
        curr_node->left = new_node;

        self->length_of_nodes = 1;
        return;
    }

    while (curr_node->left->character != GOAL) {
        curr_node = curr_node->left;
    }
    new_node->left = curr_node->left;
    curr_node->left = new_node;
    self->length_of_nodes++;
    return;
}

void add_node_right(Graph *self, int character) {
    Node *curr_node = self->nodes;
    Node *new_node = node();
    new_node->character = character;

    if (curr_node == NULL) {
        self->nodes = add_goal_nodes();

        new_node->right = curr_node->right;
        curr_node->right = new_node;
        
        self->length_of_nodes = 1;
        return;
    }

    while (curr_node->right->character != GOAL) {
        curr_node = curr_node->right;
    }
    new_node->right = curr_node->right;
    curr_node->right = new_node;
    self->length_of_nodes++;
    return;
}

void free_node_repeat(Node *node) {
    if (node == NULL)
        return;
    if (node->character == EMPTY)
        return;

    free_node_repeat(node->left);
    free_node_repeat(node->right);

    free(node);
    return;
}

// Fix recursive free
void free_nodes(Graph *self) {
    if (self == NULL)
        return NULL;

    free_node_repeat(self->nodes->left);
    free_node_repeat(self->nodes->right);

    free(self->nodes);
    self->nodes = NULL;
    self->length_of_nodes = 0;

    return self;
}

void loop_to_start(Graph *self) {
    Node *head_node = self->nodes;
    Node *curr_node = self->nodes;

    while(curr_node->left->character != GOAL) {
        curr_node = curr_node->left;
    }
    Node *destroy_node = curr_node->left;
    curr_node->left = head_node;

    free_node_repeat(destroy_node);
    destroy_node = NULL;
    return;
}

void loop_node(Graph *self) {
    Node *curr_node = self->nodes;

    while(curr_node->left->character != GOAL) {
        curr_node = curr_node->left;
    }

    Node *new_node = node();
    new_node->left = curr_node->left; // Goal node
    new_node->right = curr_node; // current node

    curr_node->left = new_node;
    return;
}