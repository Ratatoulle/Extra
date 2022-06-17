#pragma once

typedef struct DynamicArray
{
	int* array;
	int size;
	int capacity;
}dArray_t;

dArray_t* create(int capacity);
int unique(dArray_t* arr);
void delete(dArray_t* arr);
void add(dArray_t* arr, int num);
int at(dArray_t* arr, int index);
void removeElem(dArray_t* arr, int index);
void removeAll(dArray_t* arr);
void print(dArray_t* arr);
void sort(dArray_t* arr);
int find(dArray_t* arr, int number, int startInd, int endInd);
int count(dArray_t* arr, int number);
