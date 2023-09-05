#include "common.h"

#pragma once
ASSUME_NONNULL_BEGIN

#ifndef ARRAY_H_

void *reallocate(void *pointer, usize old_size, usize new_size);

#define ALLOCATE(type, count)                                                  \
  (type *)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

//< Strings allocate
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, old_count, new_count)                        \
  (type *)reallocate(pointer, sizeof(type) * (old_count),                      \
                     sizeof(type) * (new_count))

#define FREE_ARRAY(type, pointer, old_count)                                   \
  reallocate(pointer, sizeof(type) * (old_count), 0)

#define ARRAY_H_

ASSUME_NONNULL_END

#endif // ARRAY_H_