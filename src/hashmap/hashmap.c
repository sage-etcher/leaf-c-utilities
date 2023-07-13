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


#include "hashmap.h"
/* standard libraries */
#include <stddef.h>		/* size_t */
#include <malloc.h>		/* free, malloc, realloc */
#include <string.h>		/* memcpy, memcmp */
#include <assert.h>		/* assert */


/* static prototypes */
/* keyValuePair */
static _keyValuePair * _keyValuePair_new  (void *key, size_t key_size, void *value, size_t value_size);
static void            _keyValuePair_free (_keyValuePair *s);
static void _keyValuePair_get_key         (_keyValuePair *s, void *key_return);
static void _keyValuePair_get_value       (_keyValuePair *s, void *value_return);
static void _keyValuePair_set_key         (_keyValuePair *s, void *new_key,   size_t new_size);
static void _keyValuePair_set_value       (_keyValuePair *s, void *new_value, size_t new_size);
/* hashMap */
static void _hashMap_extend       (hashMap *s);
static int  _hashMap_lookup_index (hashMap *s, void *key, size_t key_size);
static void _hashMap_append       (hashMap *s, void *key, size_t key_size, void *value, size_t value_size);


/* static functions */
/* keyValuePair */
static _keyValuePair *
_keyValuePair_new (void *key, size_t key_size, void *value, size_t value_size)
	{
	/* return value */
	_keyValuePair *s;
	
	/* allocate keyValuePair */
	s = malloc (sizeof (_keyValuePair));

	/* set the key + value sizes */	
	s->_key_size   = key_size;
	s->_value_size = value_size;	

	/* allocate key + value */
	s->_key   = malloc (key_size);
	s->_value = malloc (value_size);

	/* check that malloc worked */
	assert ((unsigned char *)s->_key   != NULL);
	assert ((unsigned char *)s->_value != NULL);

	/* copy key + value over */
	memcpy (s->_key,   key,   key_size);
	memcpy (s->_value, value, value_size);

	/* return */
	return s;
	}

static void
_keyValuePair_free (_keyValuePair *s)
	{
	/* dont free the same thing twise */
	assert ((unsigned char *)s->_key   != NULL && 
	        (unsigned char *)s->_value != NULL);
	
	/* free key and value */
	free (s->_key);
	free (s->_value);

	/* set things to NULL and 0 incase of use after free */	
	s->_key   = NULL;
	s->_value = NULL;
	s->_key_size   = 0;
	s->_value_size = 0;
	
	/* free the whole keyValuePair* */
	free (s);
	}

static void 
_keyValuePair_get_key (_keyValuePair *s, void *key_return)
	{
	/* if keyValuePair has been freed, yell at the programmer */
	assert ((unsigned char *)s->_key != NULL);

	/* copy key to return ptr, 
	 * return ptr should have been allocated prior to call */
	memcpy (key_return, s->_key, s->_key_size);
	}

static void
_keyValuePair_get_value (_keyValuePair *s, void *value_return)
	{
	/* if keyValuePair has been freed, yell at the programmer */
	assert ((unsigned char *)s->_value != NULL);

	/* copy value to return ptr, 
	 * return ptr should have been allocated prior to call */
	memcpy (value_return, s->_value, s->_value_size);
	}

static void 
_keyValuePair_set_key (_keyValuePair *s, void *new_key, size_t new_size)
	{
	/* set the new size */
	s->_key_size = new_size;
	
	/* realloc the key to new size, then copy the new key over */
	s->_key = realloc (s->_key, new_size);
	assert ((unsigned char *)s->_key != NULL);
	memcpy (s->_key, new_key, new_size);
	}

static void 
_keyValuePair_set_value (_keyValuePair *s, void *new_value, size_t new_size)
	{
	/* set the new size */
	s->_value_size = new_size;
	
	/* realloc the value to new size, then copy the new value over */
	s->_value = realloc (s->_value, new_size);
	assert ((unsigned char *)s->_value != NULL);
	memcpy (s->_value, new_value, new_size);
	}

/* hashMap */
static void 
_hashMap_extend (hashMap *s)
	{
	/* double the allocated space */
	s->_alloc_len *= 2;
	s->_list = realloc (s->_list, s->_alloc_len * sizeof (_keyValuePair *));

	/* check that the list reallocated successfully */
	assert (s->_list != NULL);
	}

static int
_hashMap_lookup_index (hashMap *s, void *key, size_t key_size)
	{
	int i;					/* forloop iterator */
	_keyValuePair *c_pair;	/* curretn keyValuePair */
	int index = -1;			/* if no match is found return -1 */ 

	/* loop through each item in the hashmap */
	for (i = 0; i < s->_count; i ++)
		{
		/* set current pair */
		c_pair = s->_list[i];
	
		/* if current pair and param key_size dont match, goto next element */
		if (c_pair->_key_size != key_size)
			continue;
			
		/* if sizes match then compare the 2 keys */
		if (memcmp (c_pair->_key, key, key_size) == 0)
			{
			/* on a match, set the index to the current item's index */
			index = i;
			/* then break from the loop */
			break;
			}

		}
	
	/* return the index. if none found then -1 */
	return index;
	}

static void
_hashMap_append (hashMap *s, void *key, size_t key_size, void *value, size_t value_size)
	{
	/* make sure that the alloc_size isn't 0 */
	assert (s->_alloc_len != 0);

	/* extend hashmap's allocated space if needed */
	if (s->_alloc_len == s->_count)
		_hashMap_extend (s);
		
	/* add the new keyValuePair in the next open spot */
	s->_list[s->_count] = _keyValuePair_new (key, key_size, value, value_size);

	/* increment count to reflect the new item */
	s->_count ++;
	}


/* extern functions */
/* hashMap functions */
hashMap *
hashMap_new (void)
	{
	/* return value */
	hashMap *s;

	/* allocate the hashmap */
	s = malloc (sizeof (hashMap));
	assert (s != NULL);

	/* set default sizing values */
	s->_count = 0;
	s->_alloc_len  = 2;
	
	/* allocate the list */
	s->_list = malloc (s->_alloc_len * sizeof (_keyValuePair *));

	/* return */
	return s;
	}

void
hashMap_free (hashMap *s)
	{
	int i;

	/* dont let this function run on the same item twise */
	assert (s->_list != NULL);

	/* free the list */
	/* free each element in the list */
	for (i = 0; i < s->_count; i ++)
		{
		_keyValuePair_free (s->_list[i]);
		}
	/* free the list itself */
	free (s->_list);

	/* set things to 0 and NULL incase of use after free */
	s->_list       = NULL;
	s->_count      = 0;
	s->_alloc_len  = 0;
	
	/* free the hashmap* itself */
	free (s);
	}

void
hashMap_set (hashMap *s, void *key, size_t key_size, void *value, size_t value_size)
	{
	int item_index = _hashMap_lookup_index (s, key, key_size);

	/* if no item with that key exist, create a new pair then exit */
	if (item_index == -1)
		{
		_hashMap_append (s, key, key_size, value, value_size);
		return;
		}
	
	/* if the item already exists, just update the pair's value */
	_keyValuePair_set_value (s->_list[item_index], value, value_size);
	}

void
hashMap_remove (hashMap *s, void *key, size_t key_size)
	{
	int item_index = _hashMap_lookup_index (s, key, key_size);

	/* if no item with that key exist, exit early, and do nothing */
	if (item_index == -1)
		return;
	
	/* if item exists, first destroy the pair */
	_keyValuePair_free (s->_list[item_index]);

	/* shrink count by 1 element */
	s->_count --;
	
	/* move the current pair at the end of the list into the empty space */
	s->_list[item_index] = s->_list[s->_count];

	}

int
hashMap_lookup (hashMap *s, void *key, size_t key_size, void *value_return)
	{
	int item_index = _hashMap_lookup_index (s, key, key_size);
	_keyValuePair *c_pair;	
	
	/* if that key doesn't exist, return -1 for failure */
	if (item_index == -1)
		return -1;

	/* if item does exist, copy the items value over to value_return */
	c_pair = s->_list[item_index];
	memcpy (value_return, c_pair->_value, c_pair->_value_size);
	
	/* return succesfully */
	return 0;
	}

int
hashMap_lookup_size (hashMap *s, void *key, size_t key_size, size_t *size_return)
	{
	int item_index = _hashMap_lookup_index (s, key, key_size);
	_keyValuePair *c_pair;	
	
	/* if that key doesn't exist, return -1 for failure */
	if (item_index == -1)
		return -1;

	/* if item does exist, copy the items value over to value_return */
	c_pair = s->_list[item_index];
	*size_return = c_pair->_value_size;

	/* return succesfully */
	return 0;
	}
