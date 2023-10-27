//
// Created by sziha on 21/10/2023.
//

#include "source_reader.h"

node_t *read_source(char *filename){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }
    node_t *first_node = (node_t *) malloc(sizeof(node_t));
    node_t *current_node = first_node;
    current_node->type = -1;
    char *buffer = malloc(1000)
    int skip = 0;
    int c = 0;
    for (int i = 0; c != EOF; i = (i == 999) ? 0 : i + 1) {
        c = getc(fp);
        if (skip && c != '\n') continue;
        skip = 0;
        buffer[i] = (char) c;
        buffer[i + 1] = '\0';
        if (buffer[i] == '#' || buffer[i] == '\n' || (i > 1 && (buffer[i-1] == '/' && buffer[i] == '/'))) {
            i--;
            skip = 1;
            if (i > 1 && (buffer[i-1] == '/' && buffer[i] == '/')) i--;
            continue;
        } // reading and comments
        fprintf(stderr,"%s", buffer);
        if (strstr(buffer, "struct") !=-1)
        {
            if (strstr(buffer, "typedef") != -1)
            {
                if (c != ';') continue;
                sscanf(buffer, "%[^;]s", current_node->name)
            }
        }
        else if ()
        /*switch (current_node->type) {
            case structs:
                if (current_node->name[0] == '\0') {
                    while (current_node->struct_.args[i] != NULL ) {
                    }
                }
                break;
            default:
                if (strstr(buffer, "struct") != NULL) {
                    printf("test");
                    current_node->type = structs;
                    if (sscanf(buffer,"struct %s", current_node->name) != 1) {
                        current_node->name[0] = '\0';
                    }
                }
                break;

        }*/
    }
    fclose(fp);
    return first_node;
}
