#include <stdio.h>

#define MAX_SIZE	10
typedef struct stack_s {
	int arr[MAX_SIZE];
	int pos;
} stack_t;

void print_stack(stack_t *st)
{
	printf("stack: ");
	for (int i=0; i < st->pos; i++) {
		printf("%d ", st->arr[i]);
	}
	printf("\n");
}

void push_stack(stack_t *st, int a)
{
	if (st->pos == MAX_SIZE) {
		return;
	}
	st->arr[st->pos] = a;
	st->pos++;
	print_stack(st);
}

int pop_stack(stack_t *st)
{
	int a;
	if (st->pos == 0) {
		return 0;
	}
	st->pos--;
	a = st->arr[st->pos];
	print_stack(st);
	return a;
}

int get_top_stack(stack_t *st)
{
	if (st->pos == 0) {
		return 0;
	}
	return st->arr[st->pos-1];
}

void push(stack_t *st, stack_t *minst, int a)
{
	push_stack(st, a);

	if ((get_top_stack(minst) == 0) ||
	    (get_top_stack(minst) > a)) {
		push_stack(minst, a);
	}
}

#if 1
int pop(stack_t *st, stack_t *minst)
{
	int a = pop_stack(st);

	if (get_top_stack(minst) == a) {
		pop_stack(minst);
	}
	return a;
}

int get_min(stack_t *minst)
{
	return get_top_stack(minst);
}
#endif
int main()
{
	stack_t	st, minst;

	st.pos = 0;
	minst.pos = 0;
//	print_stack(&st);
//	print_stack(&minst);
	push(&st, &minst, 8);
#if 1
	push(&st, &minst, 5);
	push(&st, &minst, 4);
	push(&st, &minst, 6);
	push(&st, &minst, 2);
	printf("min=%d\n", get_min(&minst));

	pop(&st, &minst);
	printf("min=%d\n", get_min(&minst));

	pop(&st, &minst);
	printf("min=%d\n", get_min(&minst));

	pop(&st, &minst);
	printf("min=%d\n", get_min(&minst));
#endif
}
