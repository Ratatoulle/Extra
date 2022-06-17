#include <iostream>
#include <string>
#include "mystring.h"

MyString::MyString()
{
	this->alloc(0);
}

MyString::MyString(int _length)
{
	this->alloc(_length);
}

MyString::MyString(int _length, char* _str)
{
	this->alloc(_length);
	for (int i = 0; i < _length; ++i)
	{
		this->buffer[i] = _str[i];
	}
}

void MyString::alloc(int length)
{
	this->length = length;
	this->buffer = new char[this->length];
	if (!this->buffer)
	{
		delete[] this->buffer;
		exit(BAD_ALLOC);
	}
}

void MyString::input()
{
	std::cout << "Enter string:" << std::endl;
	char* buffer = new char[BUFF_SIZE + 1];
	int i = 0;
	do
	{
		buffer[i] = getc(stdin);
		++i;
	} while (buffer[i - 1] != EOF && buffer[i - 1] != '\n' && i < BUFF_SIZE);
	if (i != BUFF_SIZE)
		--i;
	this->alloc(i);
	for (i = 0; i < this->length; ++i)
	{
		this->buffer[i] = buffer[i];
	}
	delete[] buffer;
}

void MyString::output()
{
	for (int i = 0; i < this->length; ++i)
	{
		std::cout << this->buffer[i];
	}
}

char MyString::getSymbol(int index)
{
	return this->buffer[index];
}

int MyString::find(char c)
{
	int i = 0;
	while (i < this->length)
	{
		if (this->buffer[i] == c)
			return i;
		++i;
	}
	return -1;
}

int MyString::rfind(char c) //reverse
{
	int i = this->length;
	while (i >= 0)
	{
		if (this->buffer[i] == c)
			return i;
		--i;
	}
	return -1;
}

void MyString::erase(int leftInd, int rightInd)
{
	if (rightInd >= leftInd && leftInd >= 0 && rightInd < this->length)
	{
		char* tmp = new char[this->length - (rightInd - leftInd) - 1];
		for (int i = 0, j = 0; i < this->length; ++i)
		{
			if (i < leftInd || i > rightInd)
			{
				tmp[j] = this->buffer[i];
				++j;
			}
		}
		this->length = this->length - (rightInd - leftInd) - 1;
		std::swap(this->buffer, tmp);
		delete[] tmp;
	}
}

MyString MyString::substr(int leftInd, int rightInd)
{
	MyString newStr;
	if (rightInd >= leftInd && leftInd >= 0 && rightInd < this->length)
	{
		char* tmp = new char[rightInd - leftInd + 1];
		for (int i = leftInd; i <= rightInd; ++i)
		{
			tmp[i - leftInd] = this->buffer[i];
		}
		newStr.length = rightInd - leftInd + 1;
		std::swap(newStr.buffer, tmp);
	}
	return newStr;
}

void MyString::pushBack(char c)
{
	char* tmp = new char[this->length + 1];
	for (int i = 0; i < this->length; ++i)
	{
		tmp[i] = this->buffer[i];
	}
	tmp[this->length] = c;
	this->length += 1;
	std::swap(this->buffer, tmp);
	delete[] tmp;
}

void MyString::popBack()
{
	this->erase(this->length - 1, this->length - 1);
}

MyString MyString::append(char c)
{
	MyString newStr;
	newStr.alloc(this->length + 1);
	for (int i = 0; i < this->length; ++i)
	{
		newStr.buffer[i] = this->buffer[i];
	}
	newStr.buffer[newStr.length - 1] = c;
	return newStr;
}

MyString MyString::append(MyString str)
{
	MyString newStr;
	newStr.alloc(this->length + str.length);
	for (int i = 0; i < this->length; ++i)
	{
		newStr.buffer[i] = this->buffer[i];
	}
	for (int i = this->length; i < newStr.length; ++i)
	{
		newStr.buffer[i] = str.buffer[i - this->length];
	}
	return newStr;
}

bool MyString::is_equals(MyString str)
{
	if (this->length != str.length)
		return false;
	for (int i = 0; i < this->length; ++i)
		if (this->buffer[i] != str.buffer[i])
			return false;
	return true;
}

void MyString::clear()
{
	this->length = 0;
	delete[] this->buffer;
	this->buffer = new char[this->length];
}