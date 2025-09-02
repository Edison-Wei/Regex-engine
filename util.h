#if !defined(utils)
#define utils

#define EMPTY 0
#define GOAL 1
typedef struct Graph Graph;
typedef struct Node Node;


Node* node();
Node *add_goal_nodes();

Graph *graph();
void add_node_left(Graph *self, int character);
void add_node_right(Graph *self, int character);
void free_node_repeat(Node *node);
void free_nodes(Graph *self);
void loop_to_start(Graph *self);
void loop_node(Graph *self);

#endif // utils
