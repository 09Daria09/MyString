
#pragma once
#include<iostream>
using namespace std;
class BasicExemption
{
protected:
	char str[100];
public:
	BasicExemption() {};
	BasicExemption(const char* s)
	{
		strcpy_s(str, strlen(s) + 1, s);
	}
	virtual void Print()
	{
		cout << str << endl;
	}

};
class SymboolException : public BasicExemption
{
public:
	SymboolException() {}
	SymboolException(const char* s) :BasicExemption(s)
	{}
	void Print()
	{
		cout << "�������� �� ������� -1\n";
	}
};
class SameException : public BasicExemption
{
public:
	SameException() { }
	SameException(const char* s) :BasicExemption(s)
	{}
	void Print()
	{
		cout << "���� ����� ��������\n";
	}
};