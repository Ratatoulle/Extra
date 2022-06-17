#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dynamicArray.h"

#define ARR_SIZE 10

int main()
{
	srand(time(NULL));

	int numberToFind = rand() % 100;
	int numberToCount = rand() % 100;
	int indexToFind = rand() % ARR_SIZE;
	int indexToRemove = rand() % ARR_SIZE;

	dArray_t* array = create(ARR_SIZE);

	for (int i = 0; i < ARR_SIZE; i++)
		add(array, rand() % 100);
	printf("Initial array:\n");
	print(array);
	//just to test the at, find and count functions 
	add(array, indexToFind);
	add(array, numberToFind);
	add(array, numberToCount);

	int number = at(array, indexToFind);
	int index = find(array, numberToFind, 0, array->size);
	int counter = count(array, numberToCount);
	int uniqueNumbers = unique(array);

	printf("After some additions:\n");
	print(array);

	printf("Amount of unique numbers: %d\n", uniqueNumbers);
	printf("Number on %d index is %d\n", indexToFind, number);
	if (index == -1)
		printf("Can't find %d number\n", numberToFind);
	else
		printf("Index of number %d is %d\n", numberToFind, index);
	printf("Number %d has encountered %d times\n", numberToCount, counter);
	print(array);

	removeElem(array, indexToRemove);
	printf("After removing element on %d index:\n", indexToRemove);
	print(array);

	//print(array);
	//int unique = uniqe(array);
	//printf_s("%d\n", unique);

	sort(array);
	printf("Sorted dynamic array:\n");
	print(array);

	removeAll(array);
	printf("After deleting all elements:\n");
	print(array);

	delete(array);
	return 0;
}
