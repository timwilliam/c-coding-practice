#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArr(int *arr, int n) {
	int i;

	printf("{ ");
	for(i = 0; i < n; i++) {
		printf("%3d", arr[i]);

		if(i < n - 1) {
			printf(", ");
		}
		else {
			printf(" }\n");
		}
	}
}

int sortAscendingly(const void* x, const void* y) {
	return *((int*)x) - *((int*)y);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	// copy nums2 to empty slot of nums1
	memcpy(nums1+m, nums2, n*sizeof(int));
	qsort(nums1, nums1Size, sizeof(int), &sortAscendingly);

	return;
}

int main() {
	int nums1[] = {1, 2, 3, 0, 0, 0};
	int m = 3;
	int nums2[] = {2, 5, 6};
	int n = 3;

	printArr(nums1, m+n);
	merge(nums1, m+n, m, nums2, n, n);
	printArr(nums1, m+n);

	return 0;
}
