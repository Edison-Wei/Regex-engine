#if !defined(PARSER)
#define PARSER
#include "util.h"

#define MAX_ARRAY_LENGTH 8

Graph* parse_regex(Graph* parser, char *regex);
int split(Graph *parser, char *regex);
void deconstruct(Graph *parser);

// Not used, will need to change goal Node approach
void zero_or_none(Graph *parser, char *regex);
void zero_or_more(Graph *parser, char *regex);
void one_or_more(Graph *parser, char *regex);

#endif // PARSER
