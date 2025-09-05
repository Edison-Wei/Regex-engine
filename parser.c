#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/// @brief Given a regular expression. Translate the expression into a readable form. (ex. [a-zA-Z]@gmail.com = heLLo@gmail.com)
/// @param regex an array of char (a string) containing the regular expression to be decoded
Graph* parse_regex(Graph *parser, char *regex) {
    if (!regex) {
        return NULL;
    }
    
    if (!parser) {
        parser = graph(); // can be 16 if needed 
    }
    char character;

    do {
        character = regex[0];

        if (character == '.') {
            ++regex;
            continue;
        }
        else if (character == '|') {
            int regex_index = split(parser, ++regex);
            regex += regex_index;

        }
        else if (character == '?') {
            // zero_or_none(parser, ++regex);
            alternative_path(parser);
        }
        else if (character == '*') {
            // zero_or_more(parser, ++regex);
            loop_to_start(parser);
            add_node_right(parser, (int)character);
        }
        else if (character == '+') {
            // one_or_more(parser, ++regex);
            loop_node(parser);
        }
        else {
            add_node_left(parser, (int)character);
        }

        // // Collect capture groups
        // if (character == '[') {

        // }

        ++regex;
    } while (regex[0] != '\0');

    // Create goal nodes when completed parsers
    return parser;
}

int split(Graph *parser, char *regex) {
    char character;
    int regex_index = -1; // Since '|' is already removed

    while (regex[0] != '\0') {
        character = regex[0];
        if (character == ']' || character == ')') {
            break;
        }
        add_node_right(parser, (int)character);
        ++regex;
        ++regex_index;
    }
    return regex_index;
}

void deconstruct(Graph *parser) {
    // for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    //     free_nodes(&parser[i]);
    // }
    free_nodes(parser);
    return;
}