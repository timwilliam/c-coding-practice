#include <stdio.h>

int arraySign(int* nums, int numsSize) {
	int i;
	int belowZero = 0;

	for(i = 0; i < numsSize; i++) {
		if(nums[i] == 0) {
			return 0;
		}
		else {
			if(nums[i] < 0) {
				belowZero++;
			}
		}
	}

	// 1 if negative numbers count are even, -1 if odd
	if(belowZero % 2 == 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int nums[] = {-1,-2,-3,-4,3,2,1};
	// int nums[] = {1,5,0,2,-3};
	// int nums[] = {-1,1,-1,1,-1};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	printf("%d\n", arraySign(nums, numsSize));

	return 0;
}
