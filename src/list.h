#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint8_t* arr;
	int size;
	int capacity; 
	int element_size;
} list;


/** 
 * @brief Initializes a list (dynamic array) from a
 * a initial capacity and an element size in bytes.
*/
list list_init(int init_capacity, int element_size);

/** @brief Adds a specified value to the specifed list. */
void list_append(list* l, void* val);

/** 
 * @brief Removes a specified value to the specifed list. Returns
 * false if the element was not in the list, otherwise true.
*/
bool list_pop(list* l, void* val);

/** 
 * @brief Inserts a specified value at a specifed index
 * to the specifed list.
*/
void list_insert(list* l, void* val, int index);

/** 
 * @brief Removes a value at a specifed index from 
 * the specified list.
*/
void list_remove(list* l, int index);


void list_foreach(list* l, uint8_t*(*byte_op)(uint8_t*, uint8_t*));

void list_print(list* l);

#endif
