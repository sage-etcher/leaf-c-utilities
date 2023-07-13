/*
    This file is a part of Leaf C Utilities.
    Copyright (C) 2023  Sage I. Hendricks

    Leaf C Utilities is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Leaf C Utilities is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


/* run once */
#pragma once
#ifndef _LCU_HASHMAP_H_
#define _LCU_HASHMAP_H_

/* C++ support */
#if defined(__cplusplus)
extern "C" {
#endif

/* cstd includes */
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


/* high-level data type declarations */
/* key value pair */
struct _keyValuePair 
{
	void   *_key;
	size_t  _key_size;
	
	void   *_value;
	size_t  _value_size;
};
typedef struct _keyValuePair _keyValuePair;

/* hashmap */
struct _hashMap 
{
	_keyValuePair **_list;
	int    _count;
	int    _alloc_len;
};
typedef struct _hashMap hashMap;


/* prototypes */
/* constructor & destructor */
hashMap * hashMap_new  (void);
void      hashMap_free (hashMap *s); 
/* operations */
void hashMap_set         (hashMap *s, void *key, size_t key_size, void *value, size_t value_size);
void hashMap_remove      (hashMap *s, void *key, size_t key_size);
int  hashMap_lookup      (hashMap *s, void *key, size_t key_size, void *value_return);
int  hashMap_lookup_size (hashMap *s, void *key, size_t key_size, size_t *size_return);


/* C++ support */
#if defined(__cplusplus)
} /* extern "C" */ 
#endif

#endif /* run once */