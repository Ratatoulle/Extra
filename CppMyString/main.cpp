#include <iostream>
#include <string>
#include "mystring.h"

int main()
{
	MyString a, b;
	a.input();
	b.input();
	bool isEqual = a.is_equals(b);
	//std::swap(a, b);
	//int isFind = a.rfind('i');
	//a = a.substr(1, 3);
	//a = a.append('s');
	//a.pushBack('O');
	//a = a.append(b);
	//a.output();
	std::cout << std::endl;
	std::cout << isEqual << std::endl;
	return 0;
}