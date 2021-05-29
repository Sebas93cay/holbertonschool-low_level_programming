#include "hash_tables.h"

/**
 * hash_table_create - create hash table
 * @size: size of the table
 *
 * Return: pointer to hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->array = calloc(size, sizeof(hash_node_t **));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	table->size = size;
	return (table);
}
