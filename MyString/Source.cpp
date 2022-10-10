#include<iostream>
#include"My_String.h"
#include"BasicExemption.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	MyString str1("Daria");
	try 
	{
		str1.MyChr('s');
	}
	catch (BasicExemption* Exemption)
	{
		Exemption->Print();
	}
	try
	{
		str1 = str1;
	}
	catch(BasicExemption* Exemption)
	{
		Exemption->Print();
	}
}
