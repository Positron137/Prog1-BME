//
// Created by sziha on 16/10/2023.
//

#ifndef NHF_TYPES_H
#define NHF_TYPES_H
#endif//NHF_TYPES_H
/**
 * Input file enum
 */
typedef enum {
    file_type_h, /// <header file
    file_type_c, /// <c file
    file_type_jpg, /// <jpg file
    file_type_png, /// <png file
    //file_type_md, /// <markdown file
} file_type_e;

extern file_type_e DEFAULT_FILE_TYPE;

/**
 * flowchart drawing types
 */
///////////////////////////////////////////////////
#include <SDL_rect.h>

/*typedef struct {
    context_e type;
    SDL_Rect rect;
} node_t;*/


