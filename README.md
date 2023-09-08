# C project template

Some common code starter code I use in C projects, curated into a project template.

## Arrays

Heap-allocated and dynamically resizable. Internally is just a `ptr`, `len` and `cap`.

```C
#include "common.h"
#include "array.h"

typedef array_type(u32) u32array_t;

int main() {
    u32array_t arr = array_empty(u32t_arrayt);

    array_push(u32, &arr, 420);
    u32 val = array_pop(u32, &arr);
    safecheck(val == 420);

    // Reserve capacity
    array_reserve(u32, &arr, 64);
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
