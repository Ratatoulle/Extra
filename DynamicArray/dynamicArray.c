#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"

dArray_t* create(int capacity)
{
	dArray_t* array = (dArray_t*)malloc(sizeof(dArray_t));
	array->size = 0;
	array->capacity = capacity;
	array->array = (int*)calloc(capacity, sizeof(int));
	return array;
}

void delete(dArray_t* arr)
{
	free(arr->array);
	arr->size = 0;
	arr->capacity = 0;
}

void add(dArray_t* arr, int num)
{
	if (arr->size != arr->capacity)
	{
		arr->array[arr->size] = num;
		arr->size++;
	}
	int* newArr = (int*)realloc(arr->array, arr->capacity * 2);
	if (newArr)
	{
		arr->array = newArr;
		arr->capacity *= 2;
	}
	if (arr->size > arr->capacity)
		arr->size = arr->capacity;
}

int at(dArray_t* arr, int index)
{
	if (index >= 0 && index < arr->size)
	{
		return arr->array[index];
	}
}

void removeElem(dArray_t* arr, int index)
{
	if (index >= 0 && index < arr->size)
	{
		for (int i = index + 1; i < arr->size; i++)
		{
			arr->array[i - 1] = arr->array[i];
		}
		arr->size--;
	}
}

void removeAll(dArray_t* arr)
{
	arr->size = 0;
}

void print(dArray_t* arr)
{
	if (arr->size == 0)
		printf("There are no elements in array");
	for (int i = 0; i < arr->size; i++)
		printf("%d ", arr->array[i]);
	printf("\n");
}

static int compare(int* n, int* m)
{
	return *n - *m;
}

void sort(dArray_t* arr)
{
	qsort(arr->array, arr->size, sizeof(int), compare);
}

int find(dArray_t* arr, int number, int startInd, int endInd)
{
	if (startInd<0 || endInd>arr->size)
	{
		startInd = 0;
		endInd = arr->size;
	}

	for (int i = startInd; i < endInd; i++)
	{
		if (arr->array[i] == number)
		{
			return i;
		}
	}
	return -1;
}

int count(dArray_t* arr, int number)
{
	int index = -1;
	int count = -1;
	do
	{
		index = find(arr, number, index + 1, arr->size);
		count++;
	} while (index != -1);
	return count;
}

int unique(dArray_t* arr) 
{
	int counter = 0;
	for (int i = 0; i < arr->size; i++) 
	{
		if (count(arr, arr->array[i]) == 1) 
			counter++;
	}
	return counter;
}