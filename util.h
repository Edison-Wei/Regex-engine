#if !defined(UTILS)
#define UTILS

#define EMPTY 0
#define GOAL 1
typedef struct Graph Graph;
typedef struct Node Node;

struct Node{
    int character;
    Node *left; // output
    Node *right; //output2
    // int lastlist; Maybe

};

struct Graph{
    Node *nodes;
    int length_of_nodes; // Counts number of nodes excluding goal node

    void (*free_nodes)(Graph *);
    void (*add_node_left)(Graph *, int character);
    void (*add_node_right)(Graph *, int character);
    void (*alternative_path)(Graph *);
    void (*loop_to_start)(Graph *);
    void (*loop_node)(Graph *);
};


Node *node();
Node *add_goal_node();

Graph *graph();
void add_node_left(Graph *self, int character);
void add_node_right(Graph *self, int character);
void free_node_repeat(Node *node);
void free_nodes(Graph *self);
void alternative_path(Graph *self);
void loop_to_start(Graph *self);
void loop_node(Graph *self);

#endif // UTILS
