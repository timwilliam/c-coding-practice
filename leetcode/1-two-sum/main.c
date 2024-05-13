#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *result = (int*) malloc(2 * sizeof(int));
	int i, j, current, flag;

	flag = 0;

	for(i = 0; i < numsSize && flag == 0; i++){
		current = 0;

		for(j = i + 1; j < numsSize; j++){
			current = nums[i] + nums[j];

			if(current == target){
				*result = i;
				*(result + 1) = j;

				flag = 1;
				break;
			}
		}
	}
	
	return result;
}

int main(){
	// int nums[] = {2, 7, 11, 15};
	// int nums[] = {0, 4, 3, 0};
	int nums[] = {-1, -2, -3, -4, -5};

	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize = 2;

	// int *result = twoSum(nums, numsSize, 9, &returnSize);
	// int *result = twoSum(nums, numsSize, 0, &returnSize);
	int *result = twoSum(nums, numsSize, -8, &returnSize);

	printf("%d %d\n", *result, *(result + 1));

	free(result);

	return 0;
}
