#include <stdio.h>

#define MAX_SIZE	10
typedef struct heap_s {
	int size;
	int arr[MAX_SIZE];
} heap_t;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_parent(i) {
	return (i-1)/2;
}
int get_left(i) {
	return (2*i+1);
}
int get_right(i) {
	return (2*i+2);
}

void add_minheap(heap_t *h, int i) {
}

void del_minheap(
int main()
{
	
}
