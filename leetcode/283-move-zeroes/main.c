#include <stdlib.h>
#include <stdio.h>

void printArr(int* arr, int arrSize) {
	int i;

	printf("{ ");
	for(i = 0; i < arrSize; i++) {
		printf("%3d", arr[i]);

		if(i < arrSize-1) {
			printf(", ");
		}
		else {
			printf("}\n");
		}
	}

	return;
}

void swap(int* nums, int index) {
	nums[index] = nums[index + 1];
	nums[index + 1] = 0;

	return;
}

void moveZeroes(int* nums, int numsSize) {
	int i, j, end;

	end = numsSize - 1;

	// TODO: Optimize the algorithm and avoid nested loop
	for(i = 0; i < end; i++) {
		// if an element value is 0, keep moving it towards the end
		while(nums[i] == 0 && end > 0) {
			for(j = i; j < end; j++) {
				swap(nums, j);
			}
			end--;
		}	
	}

	return;
}

int main(void) {
	// int nums[] = {0, 1, 0, 3, 12};
	// int nums[] = {0};
	// int nums[] = {0, 0, 1};
	int nums[] = {0, 0};

	int numsSize = sizeof(nums) / sizeof(nums[0]);

	printArr(nums, numsSize);
	moveZeroes(nums, numsSize);
	printArr(nums, numsSize);

	return 0;
}
