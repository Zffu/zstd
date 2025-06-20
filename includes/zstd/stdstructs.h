/**
 * ZSTD Structure definitions. 
 * This header doesn't contain any code and is merely here for quick including multiple structures
 */

#pragma once

#if !defined(ZSTD_DISABLE_STRUCTHELPERSFUNC) || !defined(ZSTD_DISABLE_CREATEFUNCS)
#define ZSTDAppendCreateHelperFunc(inst) inst
#endif  

#if !defined(ZSTD_DISABLE_STRUCTHELPERSFUNC) || !defined(ZSTD_DISABLE_APPENDFUNCS)
#define ZSTDAppendAppendHelperFunc(inst) inst
#endif  

#if !defined(ZSTD_DISABLE_STRUCTHELPERSFUNC) || !defined(ZSTD_DISABLE_INITFUNCS)
#define ZSTDAppendInitHelperFunc(inst) inst
#endif  

#if !defined(ZSTD_DISABLE_STRUCTHELPERSFUNC) || !defined(ZSTD_DISABLE_REMOVEFUNCS)
#define ZSTDAppendRemoveHelperFunc(inst) inst
#endif  

#include <zstd/structs/linkedlist.h>