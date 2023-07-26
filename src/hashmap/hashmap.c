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
/* hashMap */
static int  hashMap_lookup_index (hashMap *s, void *key, size_t key_size);
static void hashMap_append       (hashMap *s, void *key, size_t key_size, void *value, size_t value_size);


/* static functions */
/* hashMap */
static int
hashMap_lookup_index (hashMap *s, void *key, size_t key_size)
	{
	int i;					/* forloop iterator */
	keyValuePair *c_pair;	/* curretn keyValuePair */
	int index = -1;			/* if no match is found return -1 */ 

	/* loop through each item in the hashmap */
	for (i = 0; i < s->count; i ++)
		{
		/* set current pair */
		c_pair = s->list[i];
	
		/* if current pair and param key_size dont match, goto next element */
		if (c_pair->key_size != key_size)
			continue;
			
		/* if sizes match then compare the 2 keys */
		if (memcmp (c_pair->key, key, key_size) == 0)
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
hashMap_append (hashMap *s, void *key, size_t key_size, void *value, size_t value_size)
	{
	/* make sure that the alloc_size isn't 0 */
	assert (s->alloc_len != 0);

	/* extend hashmap's allocated space if needed */
	if (s->alloc_len == s->count)
		hashMap_extend (s);
		
	/* add the new keyValuePair in the next open spot */
	s->list[s->count] = keyValuePair_new (key, key_size, value, value_size);

	/* increment count to reflect the new item */
	s->count ++;
	}


/* extern functions */
/* keyValuePair Functions */
keyValuePair *
keyValuePair_new (void *key, size_t key_size, void *value, size_t value_size)
	{
	/* return value */
	keyValuePair *s;
	
	/* allocate keyValuePair */
	s = malloc (sizeof (keyValuePair));

	/* set the key + value sizes */	
	s->key_size   = key_size;
	s->value_size = value_size;	

	/* allocate key + value */
	s->key   = malloc (key_size);
	s->value = malloc (value_size);

	/* check that malloc worked */
	assert ((unsigned char *)s->key   != NULL);
	assert ((unsigned char *)s->value != NULL);

	/* copy key + value over */
	memcpy (s->key,   key,   key_size);
	memcpy (s->value, value, value_size);

	/* return */
	return s;
	}

void
keyValuePair_free (keyValuePair *s)
	{
	/* dont free the same thing twise */
	assert ((unsigned char *)s->key   != NULL && 
	        (unsigned char *)s->value != NULL);
	
	/* free key and value */
	free (s->key);
	free (s->value);

	/* set things to NULL and 0 incase of use after free */	
	s->key   = NULL;
	s->value = NULL;
	s->key_size   = 0;
	s->value_size = 0;
	
	/* free the whole keyValuePair* */
	free (s);
	}

void 
keyValuePair_get_key (keyValuePair *s, void *key_return)
	{
	/* if keyValuePair has been freed, yell at the programmer */
	assert ((unsigned char *)s->key != NULL);

	/* copy key to return ptr, 
	 * return ptr should have been allocated prior to call */
	memcpy (key_return, s->key, s->key_size);
	}

void
keyValuePair_get_value (keyValuePair *s, void *value_return)
	{
	/* if keyValuePair has been freed, yell at the programmer */
	assert ((unsigned char *)s->value != NULL);

	/* copy value to return ptr, 
	 * return ptr should have been allocated prior to call */
	memcpy (value_return, s->value, s->value_size);
	}

void 
keyValuePair_set_key (keyValuePair *s, void *new_key, size_t new_size)
	{
	/* set the new size */
	s->key_size = new_size;
	
	/* realloc the key to new size, then copy the new key over */
	s->key = realloc (s->key, new_size);
	assert ((unsigned char *)s->key != NULL);
	memcpy (s->key, new_key, new_size);
	}

void 
keyValuePair_set_value (keyValuePair *s, void *new_value, size_t new_size)
	{
	/* set the new size */
	s->value_size = new_size;
	
	/* realloc the value to new size, then copy the new value over */
	s->value = realloc (s->value, new_size);
	assert ((unsigned char *)s->value != NULL);
	memcpy (s->value, new_value, new_size);
	}


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
	s->count = 0;
	s->alloc_len  = 2;
	
	/* allocate the list */
	s->list = malloc (s->alloc_len * sizeof (keyValuePair *));

	/* return */
	return s;
	}

void
hashMap_free (hashMap *s)
	{
	int i;

	/* dont let this function run on the same item twise */
	assert (s->list != NULL);

	/* free the list */
	/* free each element in the list */
	for (i = 0; i < s->count; i ++)
		{
		keyValuePair_free (s->list[i]);
		}
	/* free the list itself */
	free (s->list);

	/* set things to 0 and NULL incase of use after free */
	s->list       = NULL;
	s->count      = 0;
	s->alloc_len  = 0;
	
	/* free the hashmap* itself */
	free (s);
	}

void
hashMap_set (hashMap *s, void *key, size_t key_size, void *value, size_t value_size)
	{
	int item_index = hashMap_lookup_index (s, key, key_size);

	/* if no item with that key exist, create a new pair then exit */
	if (item_index == -1)
		{
		hashMap_append (s, key, key_size, value, value_size);
		return;
		}
	
	/* if the item already exists, just update the pair's value */
	keyValuePair_set_value (s->list[item_index], value, value_size);
	}

void
hashMap_remove (hashMap *s, void *key, size_t key_size)
	{
	int item_index = hashMap_lookup_index (s, key, key_size);

	/* if no item with that key exist, exit early, and do nothing */
	if (item_index == -1)
		return;
	
	/* if item exists, first destroy the pair */
	keyValuePair_free (s->list[item_index]);

	/* shrink count by 1 element */
	s->count --;
	
	/* move the current pair at the end of the list into the empty space */
	s->list[item_index] = s->list[s->count];

	}

int
hashMap_lookup (hashMap *s, void *key, size_t key_size, void *value_return)
	{
	int item_index = hashMap_lookup_index (s, key, key_size);
	keyValuePair *c_pair;	
	
	/* if that key doesn't exist, return -1 for failure */
	if (item_index == -1)
		return -1;

	/* if item does exist, copy the items value over to value_return */
	c_pair = s->list[item_index];
	memcpy (value_return, c_pair->value, c_pair->value_size);
	
	/* return succesfully */
	return 0;
	}

int
hashMap_lookup_size (hashMap *s, void *key, size_t key_size, size_t *size_return)
	{
	int item_index = hashMap_lookup_index (s, key, key_size);
	keyValuePair *c_pair;	
	
	/* if that key doesn't exist, return -1 for failure */
	if (item_index == -1)
		return -1;

	/* if item does exist, copy the items value over to value_return */
	c_pair = s->list[item_index];
	*size_return = c_pair->value_size;

	/* return succesfully */
	return 0;
	}

void 
hashMap_extend (hashMap *s)
	{
	/* double the allocated space */
	s->alloc_len *= 2;
	s->list = realloc (s->list, s->alloc_len * sizeof (keyValuePair *));

	/* check that the list reallocated successfully */
	assert (s->list != NULL);
	}

