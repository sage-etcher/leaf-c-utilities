# Leaf C Utilities (hashMap)
This module implements a simple Generic (void * based) hashMap typedef and functions. All interactions with the hashMap type is recomended to be done through the provided functions.

## Adding to a Project
How to add this module to a new C/C++ project.

First, you must copy `src/hashmap/hashmap.*` files into your program's path. Then, add `#include "hashmap.h"` in your source files. Finaly make sure that you have `hashmap.h` in the INCLUDE path, and `hashmap.c` must be compiled (and linked with) with the rest of the program sources.

## hashMap Documentation
A quick description of how to use the module, datatypes, and functions

### typedef _keyValuePair

### typedef hashMap

### hashMap_new()
  Creates a new hashMap Object, used as an initializer for the datatype. 

  `hashMap_new()` allocates a new hashMap and returns a hashMap pointer, this hashMap must be freed useing the `hashMap_free()` function.

```
  hashMap * hashMap_new (void)
```

  This function takes no parameters and returns a new hashMap object

### hashMap_free()
  Destroys hashMap Objects, used as a destructor for the datatype.

  `hashMap_free()` deallocates/frees all memory allocated in the hashMap Element. This function must be run after you are done using the hashMap element. For instructions on how to create a new hashMap please refer to `hashMap_new()`.

```
  void hashMap_free (hashMap *self)
```

  Takes a hashMap pointer, free's the allocated variables and sets values to 0/NULL incase of use after free.


### hashMap_set()

### hashMap_remove()

### hashMap_lookup()

### hashMap_lookup_size()
