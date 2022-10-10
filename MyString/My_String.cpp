#include "My_String.h"
#include"BasicExemption.h"
const int MyString::amountOfLetters = 80;
int MyString::numberOfobjects = 0;
MyString::MyString()
{
	numberOfobjects++;
	this->length = amountOfLetters;
	this->str = new char[this->length + 1];
	this->str[this->length] = '\0';
}
MyString::MyString(int length)
{
	numberOfobjects++;
	this->length = length;
	this->str = new char[length + 1];
	this->str[length] = '\0';

}
MyString::MyString(const char* str)
{
	numberOfobjects++;
	this->length = strlen(str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[this->length] = '\0';
}
MyString::MyString(const char* st, int l)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);

}
MyString::MyString(const MyString& st)
{
	length = strlen(st.str);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st.str);
}
MyString::MyString(MyString&& obj2)
{
	numberOfobjects++;
	str = obj2.str;
	obj2.str = nullptr;
	length = obj2.length;
	obj2.length = 0;
}
MyString::MyString(initializer_list<char>str_)
{
	numberOfobjects++;
	length = str_.size();
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = *(str_.begin() + i);
	}
	str[length] = '\0';
}
MyString& MyString::operator=(MyString&& obj2)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	str = obj2.str;
	obj2.str = str;
	length = obj2.length;
	obj2.length = 0;
	obj2.str = nullptr;
	return *this;
}
MyString& MyString:: operator=(const MyString& obj)
{
	if (this == &obj)
	{
		throw new SameException();
	}
	if (str != nullptr)
	{
		this->~MyString();
	}
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	return *this;
}
void MyString::operator()()
{
	cout << this->str;
}
char MyString::operator[](int index)
{
	if (index >= 0 && index < strlen(str))
	{
		return str[index];
	}
	return '\0';
}
MyString::operator int()
{
	return length;
}
MyString::operator char* ()
{
	return str;
}
void MyString::MyStrcpy(MyString& other)
{
	Delete();
	this->length = strlen(other.str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[this->length] = '\0';
}
bool MyString::MyStrStr(const char* s)
{
	int index;
	int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == s[0])
		{
			index = i;
			for (int j = 0; j < strlen(s); index++, j++)
			{
				if (str[index] == s[j])
				{
					count++;
				}
				if (count == strlen(s))
				{
					return true;
				}
			}
		}
	}
	return false;
}
int  MyString::MyChr(char c)
{
	this->length = strlen(this->str);
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == c)
		{
			return i;
		}

	}
	throw new SymboolException();
}
int  MyString::MyStrLen()
{
	int count = 0;
	while (this->str[count] != '\0')
	{
		count++;
	}
	return count;
}
void MyString::MyStrCat(MyString& b)
{
	MyString newObj;
	int LengOne = strlen(this->str);
	int LengTwo = strlen(b.str);
	this->length = LengOne + LengTwo;
	newObj.str = new char[this->length + 1];
	int i = 0;
	for (; i < LengOne; i++)
	{
		newObj.str[i] = this->str[i];
	}
	for (int j = 0; j < LengTwo && i < length; j++, i++)
	{
		newObj.str[i] = b.str[j];
	}
	Delete();
	newObj.str[this->length] = '\0';
	this->str = new char[this->length + 1];
	for (int k = 0; k < this->length; k++)
	{
		this->str[k] = newObj.str[k];
	}
	this->str[this->length] = '\0';
}
void MyString::MyDelChr(char c)
{
	int index = NULL;
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == c)
		{
			index = i;
			break;
		}
	}
	MyString newobj;
	this->length = this->length - 1;
	newobj.str = new char[this->length + 1];
	for (int j = 0; j < index; j++)
	{
		newobj.str[j] = this->str[j];
	}
	for (int k = index; k < this->length; k++)
	{
		newobj.str[k] = this->str[k + 1];
	}
	newobj.str[this->length] = '\0';
	Delete();
	this->str = new char[this->length + 1];
	for (int h = 0; h < this->length; h++)
	{
		this->str[h] = newobj.str[h];
	}
	this->str[this->length] = '\0';
}
int MyString::MyStrCmp(MyString& b)
{
	if (strlen(this->str) == strlen(b.str))
	{
		cout << "Cтроки равны ";
		return 0;
	}
	else if (strlen(this->str) > strlen(b.str))
	{
		cout << "Первая больше чем вторая ";
		return 1;
	}
	else
	{
		cout << "Первая строка меньше чем вторая ";
		return -1;
	}
}
void MyString::SetStr()
{
	MyString newObj;
	cout << "Введите строку: ";
	cin >> newObj.str;
	Delete();
	this->length = strlen(newObj.str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = newObj.str[i];
	}
	this->str[this->length] = '\0';
}
void MyString::Print()
{
	cout << this->str;
}
MyString::~MyString()
{
	delete[]this->str;
}