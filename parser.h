#if !defined(Parser)
#define Parser

#define MAX_ARRAY_LENGTH 8

#define void parser_regex(char *regex);
#define void split(Graph *parser, char *regex);

// Not used, will need to change goal Node approach
#define void zero_or_none(Graph *parser, char *regex);
#define void zero_or_more(Graph *parser, char *regex);
#define void one_or_more(Graph *parser, char *regex);

#endif // Parser
