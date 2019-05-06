#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void comb(char *str, int start, int end, int grp)
{
	int i, j;
	for (i=start; i<=end-grp;i++) {
		for (j=i+1; j<=end-grp+1; j++) {
			printf("%c%c%c\n", *(str+i), *(str+j), *(str+j+1));
		}
	}
}

int main()
{
	char str[]="abcde";
	comb(str, 0, strlen(str), 3);
}
