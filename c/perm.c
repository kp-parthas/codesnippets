#include <stdio.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(char *str, int start, int end)
{
	int i;
	if (start == end) {
		printf("str=%s\n", str);
	} else {
		for (i=start; i<=end;i++) {
			swap(str+start, str+i);
			perm(str, start+1, end);
			swap(str+start, str+i);
		}
	}
}

int main()
{
	char str[]="abcd";
	perm(str, 0, 3);
}
