#include <stdio.h>

#include <stdlib.h>
#include <malloc.h>

#include "hashmap.h"

int main (void)
{
	size_t   buffer;
	hashMap *dict;

	/* key value pairs */
	/* keys */
	int    key_one    = 1;
	char   key_two    = '2';
	double key_three  = 3.1;
	char  *key_four   = "key four";
	char   key_five[] = "key four";
	/* key sizes */
	size_t key_four_size;


	/* values */
	char   value_one    = '1';
	char  *value_two    = "value two";
	int    value_three  = 3;
	double value_four   = 4.20;
	double value_five   = 5.18;
	/* value sizes */
	size_t value_two_size;


	/* return values */
	char   char_ret;
	char  *charptr_ret;
	int    int_ret;
	double double_ret;

	/* initializations */
	/* char_size * ( key.length + null_term ) */
	charptr_ret = malloc (0);
	key_four_size  = sizeof (char) * (strlen (key_four) + 1);
	value_two_size = sizeof (char) * (strlen (value_two) + 1);
	/* hashmap initialization */
	dict = hashMap_new ();

	/* define keyvaluepairs in dict */
	hashMap_set (dict, &key_one,   sizeof (key_one),   &value_one,   sizeof (value_one));
	hashMap_set (dict, &key_two,   sizeof (key_two),   value_two,    value_two_size);
	hashMap_set (dict, &key_three, sizeof (key_three), &value_three, sizeof (value_three));
	hashMap_set (dict, key_four,   key_four_size,      &value_four,  sizeof (value_four));
	hashMap_set (dict, &key_five,  sizeof (key_five),  &value_five,  sizeof (value_five));

	/* remove the key_three element */
	hashMap_remove (dict, &key_three, sizeof (key_three));

	/* instructions */
	
	/* <int> : <char> */
	if (hashMap_lookup (dict, &key_one, sizeof (key_one), &char_ret) == 0)
		printf ("key_one:   '%c'\n", char_ret);

	/* <char> : <char*> */
	if (hashMap_lookup_size (dict, &key_two, sizeof (key_two), &buffer) == 0)
		{
		charptr_ret = realloc (charptr_ret, buffer);
		(void)hashMap_lookup (dict, &key_two, sizeof (key_two), charptr_ret);
		printf ("key_two:   \"%s\"\n", charptr_ret);
		}

	/* <double> : <int>			was removed, shouldnt print anything */
	if (hashMap_lookup (dict, &key_three, sizeof (key_three), &int_ret) == 0)
		printf ("key_three: %d\n", int_ret);
	
	/* <char*> : <double> 		should match next*/
	if (hashMap_lookup (dict, key_four, key_four_size, &double_ret) == 0)
		printf ("key_four:  %.4f\n", double_ret);

	/* <char[]> : <double> 		should match with the top one, both have identical key*/
	if (hashMap_lookup (dict, &key_five, sizeof (key_five), &double_ret) == 0)
		printf ("key_five:  %.4f\n", double_ret);
		

	/* exit gracefully */
	/* free allocated memory */
	free (charptr_ret);
	hashMap_free (dict);
	return 0;
}