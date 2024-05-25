#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void find_max(int* arr, int* max, int* index, int n)
{
	for (int i = 0; i < n; i++) {
		if (*arr > *max) *max = *arr, *index = i;
		arr++;
	}
}
void find_min(int* arr, int* min, int* index, int n)
{
	*min = 99999;
	for (int i = 0; i < n; i++) {
		if (*arr < *min) *min = *arr, * index = i;
		arr++;
	}
}
void main() // main은 수정하지 말 것
{
	int arr[10] = { 10, 30, 5, 20, 44, 13, 120, 88, 9, 101 };
	int max, min, index;

	find_max(arr, &max, &index, 10);
	printf("최대 : arr[%d]=%d\n", index, max);
	find_min(arr, &min, &index, 10);
	printf("최소 : arr[%d]=%d\n", index, min);
}