# C project template

Some common code starter code I use in C projects, curated into a project template.

Most of these are borrowed from rsms's [compis](https://github.com/rsms/compis/tree/main) project.

## Arrays

Heap-allocated and dynamically resizable. Internally is just a `ptr`, `len` and `cap`.

```C
#include "common.h"
#include "array.h"

typedef array_type(u32) u32array_t;

int main() {
    u32array_t arr = array_empty(u32_arrayt);

    array_push(u32, &arr, 420);
    u32 val = array_pop(u32, &arr);
    safecheck(val == 420);

    // Reserve capacity
    array_reserve(u32, &arr, 64);

    u32array_t second_arr = array_empty(u32_array_t);
    // Copy all elements from `arr` into `second_arr`
    array_concat(u32, second_arr, arr);
}
```

There are also array indexing macros that do bounds checking when compiled with -DDEBUG:

```C
void demonstate_array_macros(u32array_t *arr, u32array_t *arr2) {
    u32 val = array_index(u32, arr, 0);
    u32 *val = array_ref(u32, arr, 420);
}
```

There's also a `slice_t` type (just `ptr` and `len`) which is bidirectionall convertible to/from `array_t`:

```C
array_t my_arr = array_empty(array_t);
// array_t is actually a union, so you can get a slice like this:
slice_t my_slice = my_arr.slice;

// you can define slices like this:
typedef slice_type(float) float_slice_t;
// you can define an array with a slice type too:
typedef array_type_with_slice(float, float_slice_t) float_array_t;

float_array_t floats = array_empty(float_array_t);
float_slice_t float_slice = floats.slice;

```

All array macros that don't modify the array work on slices:

```C
void demonstate_slices(float_slice_t slice) {
    float val = array_index(float, &slice, 0);
    float *ref = array_ref(float, &slice, 0);
}
```

## Common

### Integer types

Contains shorter integer type names a la Zig/Rust:

```C
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t usize;
```

### `safecheck()`/`safefail()`

A nicer way to do assertions with formatted strings:

```C
// First argument is the condition, panics with backtrace
// if it is false
safecheckf(some_val == 420, "420 != %d\n", *some_val);
```

## Arena

A linear allocator.

### References

- gingerBill's [Memory Allocation Strategies: Linear/Arena Allocators](https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002/)
- PBR Book's chapter on [Arena-Based Allocation](https://www.pbr-book.org/3ed-2018/Utilities/Memory_Management#Arena-BasedAllocation)

##
