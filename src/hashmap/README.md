# Leaf C Utilities (hashMap)
This module implements a simple Generic (void * based) hashMap typedef and functions. All interactions with the hashMap type is recomended to be done through the provided functions.

## Adding to a Project
How to add this module to a new C/C++ project.

First, you must copy `src/hashmap/hashmap.*` files into your program's path. Then, add `#include "hashmap.h"` in your source files. Finaly make sure that you have `hashmap.h` in the INCLUDE path, and `hashmap.c` must be compiled (and linked with) with the rest of the program sources.

---
# hashMap Documentation

[//]: <> (Win32API inspired Documentation)
## hashMap_new function (hashmap.h)
**In this section**
> [Syntax]()

> [Parameters]()

> [Return value]()

> [Requirements]()

> [See also]()

Creates a hashMap* object.

### Syntax
C code
```
hashMap* hashMap_new(void);
```

### Parameters
None

### Return value
Newly created hashMap* object.

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[hashMap]()**

**[hashMap_free]()**

**[hashMap_set]()**

**[hashMap_remove]()**

**[hashMap_lookup]()**

**[hashMap_lookup_size]()**

---


[//]: <> (Win32API inspired Documentation)
## hashMap_free function (hashmap.h)
**In this section**
> [Syntax]()

> [Parameters]()

> [Return value]()

> [Requirements]()

> [See also]()

Frees the allocated memory stored in a hashMap* object.

### Syntax
C code
```
void hashMap_free(
	hashMap* self
);
```

### Parameters
`self`

Type: **hashMap***

Pointer to a hashMap that was created using [hashMap_new]().

### Return value
None

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[hashMap]()**

**[hashMap_new]()**

---

[//]: <> (Win32API inspired Documentation)
## None (hashmap.h)
**In this section**
> [Syntax]()

> [Parameters]()

> [Return value]()

> [Requirements]()

> [See also]()

None

### Syntax
C code
```

```

### Parameters
None

### Return value
None

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[hashMap]()**

**[hashMap_new]()**

**[hashMap_free]()**

**[hashMap_set]()**

**[hashMap_remove]()**

**[hashMap_lookup]()**

**[hashMap_lookup_size]()**

---

<br>
<br>
<br>
<br>
<br>
<br>

This section contains information about the programming elements used with 

<details>
<summary> <b> typedef _keyValuePair </b> </summary>

> keyValuePair element
> ```
> typedef struct 
> {
>     void  *key;
>     size_t key_size;
>     void  *value;
>     size_t value_size;
> } _keyValuePair;
> ```
</details>

<details>
<summary> <b> typedef hashMap </b> </summary>

> hashMap element 
> ```
> typedef struct 
> {
>     _keyValuePair **_list;
>     int _count;
>     int _alloc_len;
> } hashMap;
> ```
</details>

<details>
<summary> <b> hashMap_new </b> </summary>

> Creates a new hashMap Object, used as an initializer for the datatype. 
> ```
> hashMap * hashMap_new (void);
> ```
> This function takes no parameters and returns a new hashMap object
> `hashMap_new()` allocates a new hashMap and returns a hashMap pointer, this hashMap must be freed useing the `hashMap_free()` function.
</details>

<details>
<summary> <b> hashMap_free </b> </summary>

> Destroys hashMap Objects, used as a destructor for the datatype.
> ```
> void hashMap_free (hashMap *self);
> ```
> `hashMap_free()` deallocates/frees all memory allocated in the hashMap Element. This function must be run after you are done using the hashMap element. For instructions on how to create a new hashMap please refer to `hashMap_new()`.
</details>

<details>
<summary> <b> hashMap_set </b> </summary>

> desctiprion
> ```
> void hashMap_set (hashMap *self, void *key_ptr, size_t key_size, void *value_ptr, size_t value_size);
> ```
</details>

<details>
<summary> <b> hashMap_remove </b> </summary>

> desc
> ```
> void hashMap_remove (hashMap *self, void *key_ptr, size_t key_size);
> ```
</details>


<details>
<summary> <b> hashMap_lookup</b> </summary>

> desc
> ```
> int hashMap_lookup (hashMap *self, void *key_ptr, size_t key_size, void *value_return);
> ```
</details>


<details>
<summary> <b> hashMap_lookup_size</b> </summary>

> desc
> ```
> int hashMap_lookup_size (hashMap *self, void *key_ptr, size_t key_size, size_t *value_size_return); 
> ```

</details>
