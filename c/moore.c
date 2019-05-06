#include <stdio.h>

int cand(int arr[10])
{
	int candidx = 0;
	int count = 1, i;
	for (int i=0; i<10; i++) {
		if (arr[candidx] == arr[i]) {
			count++;
		} else {
			count--;
		}
		if (count == 0) {
			candidx = i;
			count = 1;
		}
	}
	return arr[candidx];
}

int main()
{
	int arr[10] = {1, 2, 1, 2, 1, 2, 4, 2, 2, 3};

	printf("cand=%d\n", cand(arr));
}
