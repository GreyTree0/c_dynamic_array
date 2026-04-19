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
 * @brief Removes a specified value in the specifed list. Returns
 * true if the element is in the list, otherwise false.
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

/**
 * @brief Executes a specfied operation (function pointer) 
 * for each byte in specifed list.
*/
void list_foreach(list* l, uint8_t*(*byte_op)(uint8_t*, uint8_t*));

/** 
 * @brief Prints the specifed list onto stdout in
 * the form of 'format specifier' from stdio printf. 
*/
void list_print(list* l, char* format_specifier);

/**
 * @brief Prints the specifed list onto stdout in
 * binary form. 
 * Note, in newer versions of stdio, printf can format 
 * binary with '%b'. Therefore, can list_print be 
 * used instead of this function.
*/
void list_print_bin(list* l);


#endif
