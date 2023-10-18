//
// Created by sziha on 16/10/2023.
//

#ifndef NHF_INI_READER_H
#define NHF_INI_READER_H

/**
 * ini reader types
 */
//////////////////////////////////////////////////////////
#include <SDL_pixels.h>

/**
 * enum for ini file context
 */
typedef enum {
    function,
    structs,
    variable,
    conditional,
    loop,
    main_
} context_e;
/**
 * enum for ini file sub_context
 * (in ini documentation is named value, but i use it like another context so it doesnt matter)
 */
typedef enum {
    background,
    text
} sub_context_e;

/**
 * colouring struct for theme
 */
typedef struct {
    SDL_Colour background;
    SDL_Colour text;
} colour_t;

/**
 * struct for theme
 */
typedef struct {
    colour_t functions;
    colour_t structs;
    colour_t variables;
    colour_t conditionals;
    colour_t loops;
    colour_t main_;
} theme_t;

/**
 * hash-map like struct for mapping strings to enums
 */
typedef struct {
    const char *name;
    union {
        context_e context;
        sub_context_e sub_context;
    };
} mapping_t;


/**
 * mappings for context
 */
extern mapping_t mappings_c[];
/**
 * mappings for subcontext
 */
extern mapping_t mappings_sc[];

/**
 * reads the theme ini file for custom themes
 * @param filename name of the ini file (including the .ini)
 * @param theme pointer to the theme variable
 * @return 0 if ok, 1 if error
 */
int read_ini(char *filename, theme_t *theme);
/**
 * turns a string to lowercase
 * @param str string
 */
void stoLower(char *str);
#endif //NHF_INI_READER_H
