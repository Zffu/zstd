/**
 * ZSTD's LinkedList definitions
 */

#pragma once

#define LinkedListCreateFunction(funcName, list, ...); \
    list##* funcName() { \
        list##* l = malloc(sizeof(list)); \
        l->tree = NULL; \
        l->curr = NULL; \
        \
        __VA_ARGS__ \
        \
    };



/**
 * Creates a linked list structure (an ordered set of data elements, each containing a link to its successor).
 * @param typeName the name of the structure / type
 * @param ... the inline elements of the structure
 */
#define LinkedList(typeName, ...) \
    typedef struct typeName##_tree { \
        __VA_ARGS__ \
        struct typeName##_tree* next; \
    } typeName##_tree; \
    \
    typedef struct typeName { \
        typeName##_tree* tree; \
        typeName##_tree* curr; \
    } typeName; \
    LinkedListCreateFunction(typeName##_create, typeName);

/**
 * Creates a dual linked list structure with both a next and previous indicator (an ordered set of data elements, each containing a link to its successor and its predecessor).
 * @param typeName the name of the structure / type
 * @param ... the inline elements of the structure
 */
#define DualLinkedList(typeName, ...) \
    typedef struct typeName##_tree { \
        __VA_ARGS__ \
        struct typeName##_tree* prev; \
        struct typeName##_tree* next; \
    } typeName##_tree; \
    \
    typedef struct typeName { \
        typeName##_tree* tree; \
        typeName##_tree* next; \
    } typeName \

        

