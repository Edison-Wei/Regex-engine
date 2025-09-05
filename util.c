#include <stdio.h>
#include <stdlib.h>
#include "util.h"

// Node constructor
Node* node() {
    Node *new_node = malloc(sizeof(Node));
    new_node->character = EMPTY;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

Node *add_goal_node() {
    Node *goal_node = node();
    goal_node->character = GOAL;
    return goal_node;

    // Node *head_node = node();
    // Node *left_goal_node = node();
    // Node *right_goal_node = node();

    // left_goal_node->character = GOAL;
    // right_goal_node->character = GOAL;
    
    // head_node->left = left_goal_node;
    // head_node->right = right_goal_node;

    return goal_node;
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
    return graph;
}

void add_node_left(Graph *self, int character) {
    Node *curr_node = self->nodes;
    Node *new_node = node();
    new_node->character = character;

    if (curr_node == NULL) {
        Node *head_node = node();
        head_node->left = new_node;
        new_node->left = add_goal_node();

        self->nodes = head_node;
        // self->nodes = add_goal_node();

        // new_node->left = self->nodes->left;
        // self->nodes->left = new_node;

        self->length_of_nodes = 1;
        return;
    }
    if (curr_node->left == NULL) {
        curr_node->left = add_goal_node();
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
        Node *head_node = node();
        head_node->right = new_node;
        new_node->right = add_goal_node();

        self->nodes = head_node;


        // self->nodes = add_goal_node();

        // new_node->right = self->nodes->right;
        // self->nodes->right = new_node;
        
        self->length_of_nodes = 1;
        return;
    }
    if (curr_node->right == NULL) {
        curr_node->right = add_goal_node();
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

void free_nodes(Graph *self) {
    if (self == NULL)
        return;

    free_node_repeat(self->nodes->left);
    free_node_repeat(self->nodes->right);

    free(self->nodes);
    self->nodes = NULL;
    self->length_of_nodes = 0;

    return;
}

void alternative_path(Graph *self) {
    if (!self->nodes)
        return;

    Node *curr_node = self->nodes;
    if (curr_node->right == NULL) {
        curr_node->right = add_goal_node();
    }

    // while (curr_node->right->character != GOAL) {
    //     curr_node = curr_node->right;
    // }
    return;
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