#include <stdio.h>

void print_arr(int *arr, int num)
{
	int i;

	for (i=0;i<num;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int part(int *arr, int low, int high)
{
	int i, j, pi;

	i = low-1;
	pi = high;
	for (j=low;j<high;j++)
	{
		if (arr[j] <= pi) {
			i++;
			swap(arr+i, arr+j);
		}
	}
	swap(arr+i+1,arr+pi); 
	return pi;
}

void qsort(int *arr, int low, int high)
{
	int pi;
	if (low>=high)
		return;

	pi = part(arr, low, high);
	qsort(arr, low, pi-1);
	qsort(arr, pi+1, high);
}

void msort(int *arr, int num)
{
	print_arr(arr, num);
}

void bsort(int *arr, int num)
{
	int i,j;
	for (i=0;i<num-1;i++) {
		for (j=i+1;j<num;j++) {
			if (arr[i] > arr[j]) {
				swap(arr+i, arr+j);
			}
		}
	}
	print_arr(arr, num);
}

int main()
{
	int arr[] = {8, 9, 1, 2, 4, 6, 7, 3, 5};
	//bsort(arr, sizeof(arr)/sizeof(int));
	qsort(arr, 0, sizeof(arr)/sizeof(int)-1);
	print_arr(arr, sizeof(arr)/sizeof(int));
}
