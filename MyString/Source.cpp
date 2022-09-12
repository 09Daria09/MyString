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
	MyString(const char* st,int l);
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

	static int GetNumberOfobj()
	{
		return numberOfobjects;
	}
	~MyString();
};
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
MyString::MyString(const char* st,int l)
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
	cout << "Значение не найдено -1";
	return -1;
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
int main()
{
	setlocale(LC_ALL, "ru");
	/*MyString str("Daria");
	MyString str2(" Kukuruza");
	str.Print();
	cout << endl;
	str2.Print();
	cout << endl;
	str.MyStrcpy(str2);
	str.Print();
	cout << endl;
	cout<<str.MyStrStr("ku");
	cout << endl;
	cout << str.MyChr('K');
	cout << endl;
	cout << str.MyStrLen();
	cout << endl;
	str.MyStrCat(str2);
	str.Print();
	cout << endl;
	str.MyDelChr('a');
	str.Print();
	cout << endl;
	cout<<str.MyStrCmp(str2);
	cout << endl;
	MyString str3;
	str3.SetStr();
	str3.Print();
	cout << endl;
    cout << "Count " << MyString::GetNumberOfobj();*/
	//////////////
	MyString obj("Vasya",5);
	MyString obj1(obj);
	obj.Print();
	cout << endl;
	obj1.Print();
}
