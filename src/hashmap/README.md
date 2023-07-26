# Leaf C Utilities (hashMap)
This module implements a simple Generic (void * based) hashMap typedef and functions. All interactions with the hashMap type is recomended to be done through the provided functions.

## Adding to a Project
How to add this module to a new C/C++ project.

First, you must copy `src/hashmap/hashmap.*` files into your program's path. Then, add `#include "hashmap.h"` in your source files. Finaly make sure that you have `hashmap.h` in the INCLUDE path, and `hashmap.c` must be compiled (and linked with) with the rest of the program sources.

---
# hashMap Documentation
> <details open><summary>Structures</summary>
>
> > [keyValuePair Struct](#keyvaluepair-structure-hashmaph) <br>
> > [hashMap Struct](#hashmap-structure-hashmaph) <br>
> >
> </details>
> <details open><summary>Functions</summary>
>
> > [hashMap_new](#hashmap_new-function-hashmaph) <br>
> > [hashMap_free](#hashmap_free-function-hashmaph) <br>
> > [hashMap_set](#hashmap_set-function-hashmaph) <br>
> > [hashMap_remove](#hashmap_remove-function-hashmaph) <br>
> > [hashMap_lookup](#hashmap_lookup-function-hashmaph) <br>
> > [hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph) <br>
> > [hashMap_extend](#hashmap_extend-function-hashmaph) <br>
> > [keyValuePair_new](#keyvaluepair_new-function-hashmaph) <br>
> > [keyValuePair_free](#keyvaluepair_free-function-hashmaph) <br>
> > [keyValuePair_set_value](#keyvaluepair_set_value-function-hashmaph) <br>
> > [keyValuePair_set_key](#keyvaluepair_set_key-function-hashmaph) <br>
> > [keyValuePair_get_value](#keyvaluepair_get_value-function-hashmaph) <br>
> > [keyValuePair_get_key](#keyvaluepair_get_key-function-hashmaph) <br>
> > 
> </details>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair Structure (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax) <br>
> [Items](#items) <br>
> [Requirements](#requirements) <br>
> [See also](#see-also) <br>

<sup>An Object made to hold two generic values of any size and thier appropriate sizing information.</sup>

### Syntax
```C
typedef struct 
{
	void*  key_ptr;
	size_t key_size;
	void*  value_ptr;
	size_t value_ptr;
} keyValuePair;
```

### Items
`key_ptr` <br>
Type: **void\***<br>
A generic pointer to a peice of memory of unknown size, can hold an object of any type or size. Made to be used as the "key" of a hashmap/dictioray item. <br>
<br>

`key_size` <br>
Type: **size_t**<br>
Holds the size of `key_ptr`, allowing us to *safely* read and write to key_ptr, no matter what kind of data is stored in it. <br>
<br>

`value_ptr` <br>
Type: **void\***<br>
A generic pointer to a peice of memory of unknown size, can hold an object of any type or size. Made to be used as the "value" of a hashmap/dictionary item. <br>
<br>

`value_ptr` <br>
Type: **size_t**<br>
Holds the size of `value_ptr`, allowing us to *safely* read and write to value_ptr, no matter what kind of data is stored in it. <br>
<br>

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[keyValuePair_new](#keyvaluepair_new-function-hashmaph)**<br>
**[keyValuePair_free](#keyvaluepair_free-function-hashmaph)**<br>
**[keyValuePair_set_value](#keyvaluepair_set_value-function-hashmaph)**<br>
**[keyValuePair_set_key](#keyvaluepair_set_key-function-hashmaph)**<br>
**[keyValuePair_get_value](#keyvaluepair_get_value-function-hashmaph)**<br>
**[keyValuePair_get_key](#keyvaluepair_get_key-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap Structure (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-1) <br>
> [Items](#items-1) <br>
> [Requirements](#requirements-1) <br>
> [See also](#see-also-1) <br>

<sup>the main object used for hashMaps in this module. Holds a dynamicly allocated list of keyValuePairs, the allocated length of that list, and the actual count of items in the list.</sup>

### Syntax
```C
typedef struct 
{
	keyValuePair** list;
	int            count;
	int            alloc_len;
} hashMap;
```

### Items 
`list` <br>
Type: **keyValuePair\*\*** <br>
A dynamically allocated list of keyValuePairs, not to be used directly. Reading data in the list is done through `hashMap_lookup`, writing data to the list is done through `hashMap_set`, removing pairs from the list is done through `hashMap_remove`. <br>
<br>
`alloc_len` <br>
Type: **int** <br>
The max number of items able to be held in `list`, updated on each realloc using `hashMap_extend` <br>
<br>
`count`<br>
Type: **int**<br>
The current number of items actually being held in `list`<br>
<br>

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[keyValuePair](#keyvaluepair-structure-hashmaph)**<br>
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_new function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-2) <br>
> [Parameters](#parameters) <br>
> [Return value](#return-value)<br>
> [Requirements](#requirements-2) <br>
> [See also](#see-also-2) <br>

<sup>Creates a hashMap* object.</sup>

### Syntax
```C
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_free function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-3) <br>
> [Parameters](#parameters-1) <br>
> [Return value](#return-value-1)<br>
> [Requirements](#requirements-3) <br>
> [See also](#see-also-3) <br>

<sup>Frees the allocated memory stored in a hashMap* object.</sup>

### Syntax
```C
void hashMap_free(
	hashMap* self
);
```

### Parameters
`self`

Type: **hashMap\***

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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_set function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-4) <br>
> [Parameters](#parameters-2) <br>
> [Return value](#return-value-2) <br>
> [Requirements](#requirements-4) <br>
> [See also](#see-also-4) <br>

<sup>Sets a pre-defined value to be present at a similarly pre-defined key, inside of a hashMap object. If the pair already exists, this function overwrites the old value with the new. Otherwise, if the key is not found, creates a new pair. Please note that this must use predefined data, and as such does NOT work with constants. </sup>

### Syntax
```C
void hashMap_set(
	hashMap* self,
	void*    key_ptr,
	size_t   key_size,
	void*    value_ptr,
	size_t   value_size
);
```

### Parameters
`self`<br>
Type: **hashMap\*** <br>
Pointer to the hashMap you would like to operate on. <br>
<br>

`key_ptr`<br>
Type: **void\*** <br>
The location of/pointer to the key's source data. memcopies the key from the data at this location. <br>

`key_size`<br>
Type: **size_t** <br>
Defines how many bytes of data are to be memcopied from key_ptr. <br>

`value_ptr`<br>
Type: **void\*** <br>
The location of/pointer to the value's source data. memcopies the value from the data at this location. <br>

`value_size`<br>
Type: **size_t** <br>
Defines how many bytes of data are to be memcopied from value_ptr. <br>


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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_remove function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-5) <br>
> [Parameters](#parameters-3) <br>
> [Return value](#return-value-3) <br>
> [Requirements](#requirements-5) <br>
> [See also](#see-also-5) <br>



### Syntax
```C
void hashMap_remove(
	hashMap* self,
	void*    key_ptr,
	size_t   key_size
);
```

### Parameters
`self` <br>
Types: **hashMap\*** <br>
Pointer to the hashMap you would like to operate on. <br>
<br>

`key_ptr` <br>
Types: **void\*** <br>
The location of/pointer to a set of data, that is a 1 to 1 match with the key. memcmps the data at this location with that of each key in the hashMap. <br>
<br>

`key_size` <br>
Types: **size_t** <br>
The maximum number of bytes to compare past key_ptr <br>
<br>

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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_lookup function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-6) <br>
> [Parameters](#parameters-4) <br>
> [Return value](#return-value-4) <br>
> [Requirements](#requirements-6) <br>
> [See also](#see-also-6) <br>

<sup>Given a hashMap, Key, and return address/pointer, this function will search through the given hashMap for the supplied key. On finding a match, it will copy the Value into the return address. However, please note that this function does NOT allocate the given pointer first, rather, it opts for a raw memcpy. If the return address needs allocation to hold the value, this is to be done BEFORE calling this function, by the user/programmer. If no match for the given key is found the return value will be -1, signifying a failure. Otherwise, if a match is found, a 0 will be returned</sup>

### Syntax
```C
int hashMap_lookup(
	hashMap* self,
	void*    key_ptr,
	size_t   key_size,
	void*    value_ret_ptr
);
```

### Parameters
`self` <br>
Types: **hashMap\*** <br>
Pointer to the hashMap you would like to operate on. <br>
<br>

`key_ptr` <br>
Types: **void\*** <br>
The location of/pointer to a set of data, that is a 1 to 1 match with the key. memcmps the data at this location with that of each key in the hashMap. <br>
<br>

`key_size` <br>
Types: **size_t** <br>
The maximum number of bytes to compare past key_ptr <br>
<br>

`value_ret_ptr` <br>
Types: **void\*** <br>
Pointer to store the Value associated with the given Key. Please note that this function does NOT allocate any memory to the pointer, allocation and freeing of memory is on the user.<br>
<br>


### Return value
If no match is found return `-1`, this signifies a failure. If a match is found, the Value of the given keyValuePair will be copied into the provided return address arguement, and, the function will return a `0`, signifying a success.

### Requirements
| | |
|:--- |:--- |
| **Minimum supported C ver.** | C89 standard |
| **Target Platform** | Any |
| **Header** | hashmap.h |
| **Source File** | hashmap.c |

### See also
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_lookup_size function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-7) <br>
> [Parameters](#parameters-5) <br>
> [Return value](#return-value-5) <br>
> [Requirements](#requirements-7) <br>
> [See also](#see-also-7) <br>

<sup>None</sup>

### Syntax
```C
void hashMap_lookup_size(
	hashMap* self,
	void*    key_ptr,
	size_t   key_size,
	size_t*  value_size_ret_ptr
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>hashMap_extend function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-8) <br>
> [Parameters](#parameters-6) <br>
> [Return value](#return-value-6) <br>
> [Requirements](#requirements-8) <br>
> [See also](#see-also-8) <br>

<sup>None</sup>

### Syntax
```C
void hashMap_extend(
	hashMap* self
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_new function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-9) <br>
> [Parameters](#parameters-7) <br>
> [Return value](#return-value-7) <br>
> [Requirements](#requirements-9) <br>
> [See also](#see-also-9) <br>

<sup>None</sup>

### Syntax
```C
keyValuePair* keyValuePair_new(
	void*  key_ptr,
	size_t key_size,
	void*  value_ptr,
	size_t value_ptr
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_free function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-10) <br>
> [Parameters](#parameters-8) <br>
> [Return value](#return-value-8) <br>
> [Requirements](#requirements-10) <br>
> [See also](#see-also-10) <br>

<sup>None</sup>

### Syntax
```C
void keyValuePair_free(
	keyValuePair* self
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_set_value function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-11) <br>
> [Parameters](#parameters-9) <br>
> [Return value](#return-value-9) <br>
> [Requirements](#requirements-11) <br>
> [See also](#see-also-11) <br>

<sup>None</sup>

### Syntax
```C
void keyValuePair_set_value(
	keyValuePair* self,
	void*         new_value,
	size_t        new_value_size
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_set_key function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-12) <br>
> [Parameters](#parameters-10) <br>
> [Return value](#return-value-10) <br>
> [Requirements](#requirements-12) <br>
> [See also](#see-also-12) <br>

<sup>None</sup>

### Syntax
```C
void keyValuePair_set_key(
	keyValuePair* self,
	void*         new_key,
	size_t        new_key_size
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_get_value function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-13) <br>
> [Parameters](#parameters-11) <br>
> [Return value](#return-value-11) <br>
> [Requirements](#requirements-13) <br>
> [See also](#see-also-13) <br>

<sup>None</sup>

### Syntax
```C
void keyValuePair_get_value(
	keyValuePair* self,
	void*         value_ret_ptr
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

[//]: <> (Win32API inspired Documentation)
<h2>keyValuePair_get_key function (hashmap.h)</h2>
<b>In this section</b><br>

> [Syntax](#syntax-14) <br>
> [Parameters](#parameters-12) <br>
> [Return value](#return-value-12) <br>
> [Requirements](#requirements-14) <br>
> [See also](#see-also-14) <br>

<sup>None</sup>

### Syntax
```C
void keyValuePair_get_key(
	keyValuePair* self,
	void*         key_ret_ptr
);
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
**[hashMap](#hashmap-structure-hashmaph)**<br>
**[hashMap_new](#hashmap_new-function-hashmaph)**<br>
**[hashMap_free](#hashmap_free-function-hashmaph)**<br>
**[hashMap_set](#hashmap_set-function-hashmaph)**<br>
**[hashMap_remove](#hashmap_remove-function-hashmaph)**<br>
**[hashMap_lookup](#hashmap_lookup-function-hashmaph)**<br>
**[hashMap_lookup_size](#hashmap_lookup_size-function-hashmaph)**<br>
**[[back to index]](#hashmap-documentation)**<br>
**[[back to top]](#leaf-c-utilities-hashmap)**<br>

<br>

---

<br>
<br>
<br>
<br>
<br>

# OLD

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
