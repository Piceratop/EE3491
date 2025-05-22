#include<stdio.h>
#include<stdlib.h>

struct Addend {
	double coefficient;
	int exponent;
	struct Addend *next;
};

struct Addend* insert_after(struct Addend *item, double coe, int exp) {
	struct Addend* new_node = (struct Addend*)malloc(sizeof(struct Addend));
	
	if (new_node == NULL) {
		return NULL; /* Failed Allocation */
	}
	
	/* Add data to the new node */
	new_node->coefficient = coe;
	new_node->exponent = exp;
	new_node->next = item->next;

	/* Reassignment to the next item */
	item->next = new_node;
	
	return new_node;
}

int main() {
	
}
