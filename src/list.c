#include "list.h"
#include <stdio.h>
#include <stdint.h>

list list_init(int init_capacity, int element_size) {
	list l = {0};
	l.capacity = init_capacity;
	l.element_size = element_size;

	uint8_t* tmp = malloc(element_size * init_capacity);

	if (tmp == NULL) exit(0); // TODO: Implement sufficient error handling.

	l.arr = tmp;

	return l;	
}

void list_append(list* l, void* val) {
	uint8_t* byte_ptr = (uint8_t*) val; // Little-edian, LSB first!
	
	if (l->size >= l->capacity) { 
		// Should if clause will be turned into a function and used in list_pop, list_insert? Or will they use list_append?
		uint8_t* tmp = realloc(l->arr, l->element_size * l->capacity << 1);

		if (tmp == NULL) exit(0); // TODO: Implement sufficient error handling.

		l->arr = tmp;
		l->capacity <<= 1;
	}
	for (int i = 0; i < l->element_size; ++i) {
		l->arr[l->size * l->element_size + i] = byte_ptr[i];
	}
	l->size++;

}

bool list_pop(list* l, void* val); // TODO

void list_insert(list* l, void* val, int index); // TODO

void list_remove(list* l, int index); // TODO

void list_foreach(list* l, uint8_t*(*byte_op)(uint8_t*, uint8_t*)); // TODO
																	//

void list_print(list* l, char* pntf_format) {
	printf("{");
	for (int i = 0; i < l->size; ++i) {
		uint64_t val = 0;

		// Shifting each lesser byte into val. 
		// (Reverse for loop because of little-edian)
		for (int j = l->element_size - 1; j >= 0; --j) {
			val <<= 8;
			val |= l->arr[i*l->element_size + j];
		}
		if (i > 0) printf(", ");
		printf(pntf_format, val);
	}
	printf("}\n");
}


void print_binary(uint8_t c) {
	
	for (int i = 7; i >= 0; --i) {
		if ((c >> i) & 1) printf("1");
		else printf("0");
	}
}

void list_print_bin(list* l) {
	printf("{");
	for (int i = 0; i < l->size; ++i) {
		for (int j = l->element_size - 1; j >= 0; --j) {
			print_binary(l->arr[i*l->element_size + j]);
		}
		if(i < l->size - 1) printf(", ");
	}
	printf("}\n");
}


// Test function
int main() {
	
	list boolean_list = list_init(4, 1);
	list_append(&boolean_list, &(int){1});
	list_append(&boolean_list, &(int){0});
	list_print_bin(&boolean_list);
	list_print(&boolean_list, "%lld");

	list int32_list = list_init(4, 4);
	list_append(&int32_list, &(uint32_t){1});
	list_append(&int32_list, &(uint32_t){99999});

	list_print_bin(&int32_list);
	list_print(&int32_list, "%b");


}
