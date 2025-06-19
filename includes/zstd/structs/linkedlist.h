/**
 * ZSTD's LinkedList definitions
 */

#pragma once

/**
 * Creates a linked list structure (an ordered set of data elements, each containing a link to its successor).
 * @param typeName the name of the structure / type
 * @param ... the inline elements of the structure
 */
#define LinkedList(typeName, ...) \
    typedef struct typeName_tree { \
        __VA_ARGS__ \
        struct typeName_tree* next; \
    } typeName_tree; \
    \
    typedef struct typeName { \
        typeName_tree* tree; \
        typeName_tree* curr; \
    } typeName; 

/**
 * Creates a dual linked list structure with both a next and previous indicator (an ordered set of data elements, each containing a link to its successor and its predecessor).
 * @param typeName the name of the structure / type
 * @param ... the inline elements of the structure
 */
#define DualLinkedList(typeName, ...) \
    typedef struct typeName_tree { \
        __VA_ARGS__ \
        struct typeName_tree* prev; \
        struct typeName_tree* next; \
    } typeName_tree; \
    \
    typedef struct typeName { \
        typeName_tree* tree; \
        typeName_tree* next; \
    }; typeName 

        

