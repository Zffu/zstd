/**
 * ZSTD's LinkedList definitions
 */

#pragma once

#include <zstd.h>

/**
 * Creates a function to create the specified linked list type
 */
#define LinkedListCreateFunction(funcName, list, ...) \
    list##* funcName() { \
        list##* l = malloc(sizeof(list)); \
        l->tree = NULL; \
        l->curr = NULL; \
        \
        __VA_ARGS__ \
        \
    }

/**
 * Creates a function to initialize a pointer of the specified linked list type
 */
#define LinkedListInitFunction(funcName, list, ...) \
    void funcName(list##* ptr) { \
        ptr->tree = NULL; \
        ptr->curr = NULL; \
        \
        __VA_ARGS__ \
        \
    }

/**
 * Creates a function to create the specified dual linked list type
 */
#define DualLinkedListCreateFunction(funcName, list, ...) LinkedListCreateFunction(funcName, list, 
    l->prev = NULL; \
    \
    __VA_ARGS__ \
    \
)

/**
 * Creates a function to initialize a pointer of the specified dual linked list type
 */
#define DualLinkedListInitFunction(funcName, list, ...) DualLinkedListInitFunction(funcName, list, 
    ptr->prev = NULL; \
    \
    __VA_ARGS__ \
    \
)


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
    ZSTDAppendStructHelpFunc(LinkedListCreateFunction(typeName##_create, typeName)) \
    ZSTDAppendStructHelpFunc(LinkedListInitFunction(typeName##_init, typeName))

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
    ZSTDAppendStructHelpFunc(DualLinkedListCreateFunction(typeName##_create, typeName)) \
    ZSTDAppendStructHelpFunc(LinkedListInitFunction(typeName##_init, typeName))

    