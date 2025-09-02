#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "match.h"

#define MAX_INPUT_LENGTH 256

// gcc -Wall -o regex main.c match.c parser.c util.c
int main() {
    char regex[MAX_INPUT_LENGTH];
    char string[MAX_INPUT_LENGTH];
    
    printf("Enter a Regex formula: ");
    // scanf("%s", regex);
    fgets(regex, MAX_INPUT_LENGTH, stdin);
    regex[strlen(regex)-1] = '\0';

    // Parse regex to their node placements
    Graph *parsed_regex = parse_regex(regex);

    do {
        printf("\nEnter a String to match, current regex %s: ", regex);
        fgets(string, MAX_INPUT_LENGTH, stdin);
        string[strlen(string)-1] = '\0';        

        if (strcmp(string, "change") == 0) {
            printf("Enter a new Regex: ");
            fgets(regex, MAX_INPUT_LENGTH, stdin);
            regex[strlen(regex)-1] = '\0';

            // Parse with new regex
            parsed_regex = parse_regex(regex);
            continue;
        }
        
        int matched = match(parsed_regex, string);
        // match the regex with the given string
        // print results
        if (matched == 1)
            printf("The string (%s) matches\n", string);
        else
            printf("The string (%s) does not match\n", string);

        
    } while(strcmp(string, "end") != 0);

    deconstruct(parsed_regex);

    return 0;
}