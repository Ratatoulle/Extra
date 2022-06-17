#pragma once

#define BUFF_SIZE 200
#define BAD_ALLOC -1

class MyString
{
private:
	int length;
	char* buffer;
public:
	MyString();
	MyString(int _length);
	MyString(int _length, char* _str);
	void alloc(int length);
	void input();
	void output();
	char getSymbol(int index);
	int find(char c);
	int rfind(char c);
	void erase(int leftInd, int rightInd);
	MyString substr(int leftInd, int rightInd);
	void pushBack(char c);
	void popBack();
	MyString append(char c);
	MyString append(MyString str);
	bool is_equals(MyString str);
	void clear();
};