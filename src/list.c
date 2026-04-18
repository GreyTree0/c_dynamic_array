#include "list.h"
#include <stdio.h>
#include <stdint.h>

list list_init(int init_capacity, int element_size) {
	list l = {0};
	l.capacity = init_capacity;
	l.element_size = element_size;

	uint8_t* tmp = malloc(element_size * init_capacity);

	if (tmp == NULL) exit(0);

	l.arr = tmp;

	return l;	
}

void list_append(list* l, void* val) {
	uint8_t* byte_ptr = (uint8_t*) val;
	
	if (l->size >= l->capacity) {
		uint8_t* tmp = realloc(l->arr, l->element_size * l->capacity << 1);

		if (tmp == NULL) exit(0);

		l->arr = tmp;
		l->capacity <<= 1;
	}

	for (int i = 0; i < l->element_size; ++i) {
		l->arr[l->size - 1] = byte_ptr[i];
	}
	l->size++;

}

bool list_pop(list* l, void* val);

void list_insert(list* l, void* val, int index);

void list_remove(list* l, int index);

void list_foreach(list* l, uint8_t*(*byte_op)(uint8_t*, uint8_t*));

void list_print(list* l) {
	printf("%d", l->element_size);
	printf("{");
	for (int i = 0; i < l->size; ++i) {
		uint64_t val = 0;
		for (int j = 0; j < l->element_size; ++j) {
			val += l->arr[i*l->element_size + j];
		}
		if (i > 0) printf(", ");
		printf("%ld", val);
	}
	printf("}\n");
}


int main() {
	
	list boolean_list = list_init(4, 1);
	list_append(&boolean_list, &(int){1});
	list_append(&boolean_list, &(int){0});
	
	printf("%d, %d", boolean_list.size, boolean_list.capacity);
	list_print(&boolean_list);

	list int32_list = list_init(4, 4);
	list_append(&int32_list, &(uint32_t){10});
	list_append(&int32_list, &(uint32_t){99999});

	list_print(&int32_list);

}
