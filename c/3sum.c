/**
 * Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n
 * that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 * <p>
 * For example, given nums = [-2, 0, 1, 3], and target = 2.
 * Return 2. Because there are two triplets which sums are less than 2:
 * <p>
 * [-2, 0, 1]
 * [-2, 0, 3]
 */

#include <stdio.h>


int thrsum(int *arr, int num, int tgt)
{
	int i=0, th, sec;
	int count = 0;

	while (i<num) {
		sec = i+1;
		th = num-1;

		while (sec<th) {
			if (tgt > (arr[i]+arr[sec]+arr[th])) {
				count += (th-sec);
				sec++;
			} else {
				th--;
			}
		}
		i++;
	}
	return count;
}

int main()
{
	int arr[] = {-2, 0, 1, 3};
	printf("%d\n", thrsum(arr, 4, 2));
}
