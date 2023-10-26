//
// Created by sziha on 21/10/2023.
//

#ifndef NHF_SOURCE_READER_H
#define NHF_SOURCE_READER_H
#include <stdio.h>
#include <stdlib.h>
#include "ini_reader.h"
#include "debugmalloc.h"
typedef struct {
    char *return_type;
    char **args;
} func_type_t;

typedef struct {
    char **args;
} struct_type_t;

typedef struct {
    char *value;
} variable_type_t;

typedef struct {
    char *condition;
} conditional_type_t;

typedef struct {
    char *condition;
} loop_type_t;

typedef struct node{
    context_e type;
    char name[100];
    union {
        func_type_t func;
        struct_type_t struct_;
        variable_type_t variable;
        conditional_type_t conditional;
        loop_type_t loop;
    };
    int list_size;
    struct node **nextList;
} node_t;

node_t *read_source(char *filename);
#endif //NHF_SOURCE_READER_H
