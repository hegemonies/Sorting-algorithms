#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int array[], int size)
{
	int i, j, min_idx;
	for(i = 0; i < size - 1; i++){
		min_idx = i;
		for(j = i + 1; j < size; j++){
			if(array[j] < array[min_idx]){
				min_idx = j;
			}
		}
		if(min_idx != i){
			swap(&array[i], &array[min_idx]);
		}
	}
}

int main()
{
	int n = 10;
	int array[] = {9, 1, 3, 6, 7, 5, 2, 4, 8, 0};
	selection_sort(array, n);
	for(int i = 0; i < n; i++){
		printf("%d:%d\n", i, array[i]);
	}
	return 0;
}
