/**
 * ZSTD Structure definitions. 
 * This header doesn't contain any code and is merely here for quick including multiple structures
 */

#pragma once

#ifdef ZSTD_DISABLE_STRUCTURE_FUNCHELPERS
#define ZSTDAppendStructHelpFunc(inst)
#else
#define ZSTDAppendStructHelpFunc(inst) inst 
#endif

#include <zstd/structs/linkedlist.h>