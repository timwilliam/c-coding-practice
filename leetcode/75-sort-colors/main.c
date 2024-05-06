#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArr(int *arr, int n) {
	int i;

	printf("{ ");
	for(i = 0; i < n; i++) {
		printf("%2d", arr[i]);

		if(i < n - 1) {
			printf(", ");
		}
		else {
			printf(" }\n");
		}
	}
}

void sortColors(int* nums, int numsSize) {
	int i, anchor, temp;

	// insertion sort
	for(i = 1; i < numsSize; i++) {
		temp = nums[i];
		anchor = i;
		while(anchor > 0 && nums[anchor-1] > temp) {
			nums[anchor] = nums[anchor-1];
			anchor--;
		}
		nums[anchor] = temp;
	}

}

int main(void) {
	int nums[] = {2,0,2,1,1,0};
	
	int n = sizeof(nums) / sizeof(nums[0]);

	printArr(nums, n);
	sortColors(nums, n);
	printArr(nums, n);

	return 0;
}
