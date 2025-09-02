#include "util.c"
#include "parser.h"

/// @brief Given a regular expression. Translate the expression into a readable form. (ex. [a-zA-Z]@gmail.com = heLLo@.com , )
/// @param regex an array of char (a string) containing the regular expression to be decoded
Graph* parse_regex(char *regex) {
    Graph parser[MAX_ARRAY_LENGTH]; // can be 16 if needed 
    // for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
    //     parser[i] = graph();
    // }
    char character;
    int num_capture_groups = 0;

    do {
        character = regex[0];

        if (character == '.') {
            regex++;
            continue;
        }
        else if (character == '|') {
            split(&parser[num_capture_groups], regex++);
        }
        else if (character == '?') {
            // zero_or_none(&parser[num_capture_groups], regex++);
        }
        else if (character == '*') {
            // zero_or_more(&parser[num_capture_groups], regex++);
            loop_to_start(&parser[num_capture_groups]);
        }
        else if (character == '+') {
            // one_or_more(&parser[num_capture_groups], regex++);
            loop_node(&parser[num_capture_groups]);
        }
        else {
            add_node_left(&parser[num_capture_groups], (int)character);
        }

        // // Collect capture groups
        // if (character == '[') {

        // }

        regex++;
    } while (regex[0] != '\0');

    // Create goal nodes when completed parsers
    return &parser;
}

void split(Graph *parser, char *regex) {
    char character;
    while (regex[0] != '\0') {
        character = regex[0];
        if (character == ']' || character == ')') {
            break;
        }
        add_node_right(&parser, (int)character);
        regex++;
    }
    return;
}