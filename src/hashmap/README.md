# Leaf C Utilities (hashMap)
This module implements a simple Generic (void * based) hashMap typedef and functions. All interactions with the hashMap type is recomended to be done through the provided functions.

## Adding to a Project
How to add this module to a new C/C++ project.

First, you must copy `src/hashmap/hashmap.*` files into your program's path. Then, add `#include "hashmap.h"` in your source files. Finaly make sure that you have `hashmap.h` in the INCLUDE path, and `hashmap.c` must be compiled (and linked with) with the rest of the program sources.

---
# hashMap Documentation
> <details open><summary>Structures</summary>
>
> > [keyValuePair Struct](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyValuePair-structure-hashmaph) <br>
> > [hashMap Struct](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph) <br>
> </details>
> <details open><summary>Functions</summary>
>
> > [hashMap_new](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_new-function-hashmaph) <br>
> > [hashMap_free](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_free-function-hashmaph) <br>
> > [hashMap_set](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_set-function-hashmaph) <br>
> > [hashMap_remove](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_remove-function-hashmaph) <br>
> > [hashMap_lookup](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_lookup-function-hashmaph) <br>
> > [hashMap_lookup_size](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_lookup_size-function-hashmaph) <br>
> > [hashMap_extend](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashMap_extend-function-hashmaph) <br>
> > [keyValuePair_new](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyValuePair_new-function-hashmaph) <br>
> > [keyValuePair_free](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyValuePair_free-functions-hashmaph) <br>
> > [keyValuePair_set_value](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyvaluepair_set_value-function-hashmaph) <br>
> > [keyValuePair_set_key](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyvaluepair_set_key-function-hashmaph) <br>
> > [keyValuePair_get_value](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyvaluepair_get_value-function-hashmaph) <br>
> > [keyValuePair_get_key](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#keyvaluepair_get_key-function-hashmaph) <br>
> > 
> </details>

---

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair Structure (hashmap.h)</b></summary>

<h1>keyValuePair Structure (hashmap.h)</h1>
<b>In this section</b><br>

> [Syntax](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#syntax) <br>
> [Parameters](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#parameters) <br>
> [Return value](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#return-value)<br>
> [Requirements](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#requirements) <br>
> [See also](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#see-also) <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap Structure (hashmap.h)</b></summary>

<h2>hashMap Structure (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_new function (hashmap.h)</b></summary>

<h2>hashMap_new function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_free function (hashmap.h)</b></summary>

<h2>hashMap_free function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_set function (hashmap.h)</b></summary>

<h2>hashMap_set function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_remove function (hashmap.h)</b></summary>

<h2>hashMap_remove function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_lookup function (hashmap.h)</b></summary>

<h2>hashMap_lookup function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_loopup_size function (hashmap.h)</b></summary>

<h2>hashMap_loopup_size function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>hashMap_extend function (hashmap.h)</b></summary>

<h2>hashMap_extend function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair_new function (hashmap.h)</b></summary>

<h2>keyValuePair_new function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair_free function (hashmap.h)</b></summary>

<h2>keyValuePair_free function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keuValuePair_set_value function (hashmap.h)</b></summary>

<h2>keuValuePair_set_value function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair_set_key function (hashmap.h)</b></summary>

<h2>keyValuePair_set_key function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair_get_value function (hashmap.h)</b></summary>

<h2>keyValuePair_get_value function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

---

</details>

[//]: <> (Win32API inspired Documentation)
<details><summary><b>keyValuePair_get_key function (hashmap.h)</b></summary>

<h2>keyValuePair_get_key function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax]() <br>
> [Parameters]() <br>
> [Return value]() <br>
> [Requirements]() <br>
> [See also]() <br>

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
**[hashMap](https://github.com/sage-etcher/leaf-c-utilities/tree/add-hashmap/src/hashmap#hashmap-structure-hashmaph)** <br>
**[hashMap_new]()** <br>
**[hashMap_free]()** <br>
**[hashMap_set]()** <br>
**[hashMap_remove]()** <br>
**[hashMap_lookup]()** <br>
**[hashMap_lookup_size]()** <br>

</details>

# OLD
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
