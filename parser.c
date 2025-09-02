#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/// @brief Given a regular expression. Translate the expression into a readable form. (ex. [a-zA-Z]@gmail.com = heLLo@gmail.com)
/// @param regex an array of char (a string) containing the regular expression to be decoded
Graph* parse_regex(char *regex) {
    if (!regex) {
        return NULL;
    }
    

    Graph *parser = graph(); // can be 16 if needed 
    // for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    //     parser[i] = graph();
    // }
    char character;
    // int num_capture_groups = 0;

    do {
        character = regex[0];

        // if (character == '\n') continue;

        if (character == '.') {
            regex++;
            continue;
        }
        else if (character == '|') {
            split(parser, regex++);
        }
        else if (character == '?') {
            // zero_or_none(parser, regex++);
        }
        else if (character == '*') {
            // zero_or_more(parser, regex++);
            loop_to_start(parser);
        }
        else if (character == '+') {
            // one_or_more(parser, regex++);
            loop_node(parser);
        }
        else {
            add_node_left(parser, (int)character);
        }

        // // Collect capture groups
        // if (character == '[') {

        // }

        regex++;
    } while (regex[0] != '\0');

    // Create goal nodes when completed parsers
    return parser;
}

void split(Graph *parser, char *regex) {
    char character;
    while (regex[0] != '\0') {
        character = regex[0];
        if (character == ']' || character == ')') {
            break;
        }
        add_node_right(parser, (int)character);
        regex++;
    }
    return;
}

void deconstruct(Graph *parser) {
    // for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    //     free_nodes(&parser[i]);
    // }
    free_nodes(parser);

    free(parser);
    return;
}