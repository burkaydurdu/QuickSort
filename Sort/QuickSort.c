#include<stdio.h>
#include<stdlib.h>

/*
*
*	@Quick sort,
*	@Pivot value is medium value
*
*/
void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int * quickSort(int array[], int left, int right){
	int pivot, i, j;
	pivot = array[(left + right) / 2];
	i = left;
	j = right;
	do{
		while(array[i] < pivot && i < right)
			i++;

		while(array[j] > pivot && j > left)
			j--;

		if(i <= j){
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	} while(i <= j);
	
	if(left < j) quickSort(array, left, j);
	if(right > i) quickSort(array, i, right);
	
	return array; 
}

int main(){
	int i;
	int  array[] = {12,45,4,7,2,34,56,22,3};
	int *sortArray = quickSort(array, 0, 8);
	int arrayLength = sizeof(array) / sizeof(array[0]);
	for(i = 0; i < arrayLength; i++)
		printf("%d\n", sortArray[i]);
	return 0;	
}

