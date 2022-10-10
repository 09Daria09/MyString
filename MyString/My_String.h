#pragma once
#include<iostream>
using namespace std;
class MyString
{
private:
	char* str; // указатель на строку
	int length; // длина строки
	static const int amountOfLetters;
	static int numberOfobjects;
	void Delete()
	{
		if (this->str != nullptr)
		{
			delete[]str;
		}
	}
public:
	MyString();
	MyString(int length);
	MyString(const char* str);
	MyString(const char* st, int l);
	MyString(const MyString& st);
	void MyStrcpy(MyString& other);
	bool MyStrStr(const char* s);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	void SetStr();
	void Print();
	MyString& operator=(const MyString& obj);
	void operator()();
	char operator[](int index);
	operator int();
	operator char* ();
	static int GetNumberOfobj()
	{
		return numberOfobjects;
	}
	MyString(MyString&& obj2);
	MyString& operator=(MyString&& obj2);
	MyString(initializer_list<char>str_);
	~MyString();
};
