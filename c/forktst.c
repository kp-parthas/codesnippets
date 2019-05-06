#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i = 10;
	int *p = &i;

	int chld = fork();
	if (!chld) {
		i = 11;
	}

	printf("i is %d\n", *p);

}

