//
// Created by sziha on 16/10/2023.
//

#include "ini_reader.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

mapping_t mappings_c[] = {
        {"functions", function},
        {"structs", structs},
        {"vars", variable},
        {"conds", conditional},
        {"loops", loop},
        {"main",main_},
};

mapping_t mappings_sc[] = {
        {"background", .sub_context=background},
        {"text", .sub_context=text},
};

int read_ini(char *filename, theme_t *theme) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr,"Couldn't open file");
        return -1;
    }
    //printf("file open\n") ;
    char line[256]; //if context == -1 go to next line else chaeck subcontxt and add to theme
    context_e context = -1;
    sub_context_e subContext = -1;
    while (fgets(line, 256, fp) != NULL) {
        //printf("%s", line);
        if (line[0] == '[') {
            char *name = line + 1;
            name = strtok(name, "]");
            stoLower(name);
            printf("%s\n", name);
            for (int i = 0; i < 6; i++) {
                if (strcmp(name, mappings_c[i].name) == 0) {
                    context = mappings_c[i].context;
                    break;
                }
            }
            if (context == -1) {
                fprintf(stderr, "Unknown context: %s\n", name);
            }
            continue;
        }
        else if (line[0] != ';' && context != -1)
        {
            char *value = strtok(line, "=");
            int val_len = strlen(value);
            printf("%s", value);
            char *valend = value+val_len-1;
            while (isspace(*valend)){
                *valend = '\0';
                valend--;
            }
            for (int i = 0; i < 2; i++) {
                if (strcmp(value, mappings_sc[i].name) == 0) {
                    subContext = mappings_sc[i].sub_context;
                    break;
                }
            }
            if (subContext == -1) {
                fprintf(stderr, "Unknown sub context: %s\n", value);
            }
            value = strtok(NULL, "=");
            while (isspace(*value))
                value++;
            char rgba[3] = {value[1], value[2],'\0'};
            switch (context) {
                case function:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->functions.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->functions.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->functions.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->functions.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->functions.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->functions.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->functions.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->functions.text.a);
                    }
                    break;
                case structs:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->structs.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->structs.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->structs.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->structs.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->structs.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->structs.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->structs.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->structs.text.a);
                    }
                    break;
                case variable:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->variables.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->variables.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->variables.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->variables.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->variables.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->variables.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->variables.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->variables.text.a);
                    }
                    break;
                case conditional:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->conditionals.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->conditionals.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->conditionals.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->conditionals.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->conditionals.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->conditionals.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->conditionals.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->conditionals.text.a);
                    }
                    break;
                case loop:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->loops.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->loops.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->loops.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->loops.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->loops.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->loops.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->loops.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->loops.text.a);
                    }
                    break;
                case main_:
                    if (subContext == background) {
                        sscanf(rgba, "%x", &theme->main_.background.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->main_.background.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->main_.background.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->main_.background.a);
                    } else {
                        sscanf(rgba, "%x", &theme->main_.text.r);
                        rgba[0] = value[3]; rgba[1] = value[4];
                        sscanf(rgba, "%x", &theme->main_.text.g);
                        rgba[0] = value[5]; rgba[1] = value[6];
                        sscanf(rgba, "%x", &theme->main_.text.b);
                        rgba[0] = value[7]; rgba[1] = value[8];
                        sscanf(rgba, "%x", &theme->main_.text.a);
                    }
                    break;
            }
        }
    }
    fclose(fp);
    return 0;
}

void stoLower(char *str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}