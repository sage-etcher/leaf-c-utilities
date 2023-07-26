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
typedef struct
{
	void   *key;
	size_t  key_size;
	
	void   *value;
	size_t  value_size;
} keyValuePair;

/* hashmap */
typedef struct 
{
	keyValuePair **list;
	int    count;
	int    alloc_len;
} hashMap;


/* prototypes */

/* keyValuePair based */
/* constructor & destructor */
keyValuePair * keyValuePair_new  (void *key, size_t key_size, void *value, size_t value_size);
void           keyValuePair_free (keyValuePair *s);
/*operations */
void keyValuePair_get_key        (keyValuePair *s, void *key_return);
void keyValuePair_get_value      (keyValuePair *s, void *value_return);
void keyValuePair_set_key        (keyValuePair *s, void *new_key,   size_t new_size);
void keyValuePair_set_value      (keyValuePair *s, void *new_value, size_t new_size);

/* hashMap based */
/* constructor & destructor */
hashMap * hashMap_new  (void);
void      hashMap_free (hashMap *s); 
/* operations */
void hashMap_set         (hashMap *s, void *key, size_t key_size, void *value, size_t value_size);
void hashMap_remove      (hashMap *s, void *key, size_t key_size);
int  hashMap_lookup      (hashMap *s, void *key, size_t key_size, void *value_return);
int  hashMap_lookup_size (hashMap *s, void *key, size_t key_size, size_t *size_return);
void hashMap_extend      (hashMap *s);


/* C++ support */
#if defined(__cplusplus)
} /* extern "C" */ 
#endif

#endif /* run once */
