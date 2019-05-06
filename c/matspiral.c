#include <stdio.h>

void spir(int arr[5][5], int rownum, int colnum)
{
	int i, j;
	int srow=0, scol=0;
	int erow=rownum-1, ecol=colnum-1;

	while (srow<=erow && scol<=ecol) {

		if (srow==erow && scol==ecol) {
			printf("%d ", arr[srow][scol]);
		}

		for (i=srow,j=scol; j<ecol; j++) {
			printf("%d ", arr[i][j]);
		}
		for (i=srow,j=ecol; i<erow; i++) {
			printf("%d ", arr[i][j]);
		}
		for (i=erow,j=ecol; j>scol; j--) {
			printf("%d ", arr[i][j]);
		}
		for (i=erow,j=scol; i>srow; i--) {
			printf("%d ", arr[i][j]);
		}
		srow++;
		scol++;
		erow--;
		ecol--;
	}

}

int main()
{
	/* 1 2 3 4 5 5 5 5 5 4 3 2 1 1 1 1 2 3 4 4 4 3 2 2 */
	int arr[5][5] = {
			{1, 2, 3, 4, 5},
			{1, 2, 3, 4, 5},
			{1, 2, 3, 4, 5},
			{1, 2, 3, 4, 5},
			{1, 2, 3, 4, 5}
			};
	spir(arr, 5, 5);
}
