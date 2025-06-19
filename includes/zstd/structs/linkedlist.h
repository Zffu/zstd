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
    typedef struct typeName { \
        __VA_ARGS__ \
        struct typeName* next; \
    } typeName; \
