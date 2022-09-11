#include<iostream>
using namespace std;
class MyString
{
private:
	char* str; // указатель на строку
	int length; // длина строки
	static const int amountOfLetters;
	void Delete()
	{
		if (this->str != nullptr)
		{
			delete[]str;
		}
	}
public:
	MyString()
	{
		//this->str = nullptr;
		this->length = amountOfLetters;
		this->str = new char[this->length + 1];
		this->str[this->length] = '\0';
	}//конструктор по умолчанию, позволяющий создать строку длиной 80 символов
	MyString(int length)//конструктор, позволяющий создавать строку произвольного размера; 
	{
		this->length = length;
		this->str = new char[length + 1];
		this->str[length] = '\0';

	}//конструктор, позволяющий создавать строку произвольного размера
	MyString(const char* str)
	{
		this->length = strlen(str);
		this->str = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[this->length] = '\0';
	}
	void MyStrcpy(MyString& other)
	{
		this->length = strlen(other.str);
		this->str = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[this->length] = '\0';
	}
	bool MyStrStr(const char* s)
	{
		int index;
		int count = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] == s[0])
			{
				index = i;
				for (int j=0;j<strlen(s); index++,j++ )
				{
					if (str[index] == s[j])
					{
						count++;
					}
				}
			}
		}
		if (count == strlen(s))
		{
			return true;
		}
		else
		{
			return false;
		}
		

	}
	int  MyChr(char c)
	{
		this->length = strlen(this->str);
		cout << this->length << endl;
		int rez = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] == c)
			{
				rez++;
				cout << this->str[i];
				return this->str[i];
			}

		}
		cout << "Значение не найдено -1";
		return -1;
	}
	int MyStrLen()
	{
		int count = 0;
		while (this->str[count] != '\0')
		{
			count++;
		}
		cout << count;
		return count;
	}
	void MyStrCat(MyString& b)
	{
		MyString newObj;
		int LengOne = strlen(this->str);
		int LengTwo = strlen(b.str);
		newObj.str = new char[LengOne + LengTwo + 1];
		int i = 0;
		for (; i < LengOne; i++)
		{
			newObj.str[i] = this->str[i];
		}
		for (int j = 0; j < LengTwo; j++, i++)
		{
			newObj.str[i] = b.str[j];
		}
		newObj.str[LengOne + LengTwo] = '\0';
		this->str = new char[LengOne + LengTwo + 1];
		for (int k = 0; k < (LengOne + LengTwo); k++)
		{
			this->str[k] = newObj.str[k];
		}
		this->str[LengOne + LengTwo] = '\0';
	}
	void MyDelChr(char c)
	{
		int index = NULL;
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] == c)
			{
				index = i;
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
		this->str = new char[this->length + 1];
		for (int h = 0; h < this->length; h++)
		{
			this->str[h] = newobj.str[h];
		}
		this->str[this->length] = '\0';
	}
	int MyStrCmp(MyString& b)
	{
		if (strlen(this->str) == strlen(b.str))
		{
			cout << "Cтроки равны 0" << endl;
			return 0;
		}
		else if (strlen(this->str) > strlen(b.str))
		{
			cout << "Первая больше чем вторая 1" << endl;
			return 1;
		}
		else
		{
			cout << "Первая строка меньше чем вторая -1" << endl;
			return -1;
		}
	}
	void SetStr()
	{
		MyString newObj1;
		cout << "Введите строку: ";
		cin >> newObj1.str;
		length = strlen(newObj1.str);
		for (int i = 0; i<length; i++)
		{
			this->str[i] = newObj1.str[i];
		}
		this->str[length] = '\0';
	}
	void Print()
	{
		cout << this->str;
	}
	~MyString()
	{
		delete[]this->str;
	}
};
const int MyString::amountOfLetters = 80;
int main()
{
	setlocale(LC_ALL, "ru");
	MyString str("Daria");
	MyString str2("Kukuruza");
	str.Print();
	cout << endl;
	str2.Print();
	/*str.MyStrcpy(str2);
	cout << endl;
	str.Print();*/
	/*cout << endl;
	str.MyStrCat(str2);
	str.Print(); */
	/*cout << endl;
	str.MyStrCmp(str2);*/
	/*cout << endl;
	str.MyChr('a');*/
	/*str.MyDelChr('r');
	str.Print();*/
	//char b[2] = "ia";
	/*cout << endl;
	cout<<str2.MyStrStr("ku");*/
	cout << endl;
	str.SetStr();
	cout << endl;
	str.Print();
	cout << endl;
	str2.MyStrcpy(str);
	str2.Print();




}