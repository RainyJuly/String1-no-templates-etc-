#include <iostream>
#include <conio.h>
using std::ostream;
using std::istream;
#pragma warning(disable : 4996)

class string
{
    char* _str;
	unsigned _size;
public:

	string(const char* str = "") {
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
	};
	string(const string& rhs)
	{
		_size = strlen(rhs._str);
		_str = new char[_size + 1];
		strcpy(_str, rhs._str);
	}
	
	int Get_size()
	{
		return _size;
	};
	char* Get_str()
	{
		return _str;
	};
	char& operator[](unsigned index)
	{
		if ((index > _size - 1) || (index < 0) || (_size == 0))throw "Incorrect index!";
		return _str[index];
	};
	string operator+(const string& rhs)
	{
		string _tmp("");
        delete[] _tmp._str;
		_tmp._size = _size + rhs._size;
		_tmp._str = new char[_tmp._size + 1];
		unsigned i = 0;
		for (i; i < _size; i++)
		{
			_tmp._str[i] = _str[i];
		}
		for (unsigned j = 0; j < rhs._size; j++)
		{
			_tmp._str[i] = rhs._str[j];
			i++;
		}
		_tmp._str[_tmp._size] = 0;
		return _tmp;
	};
	string operator*(const unsigned n)
	{
		string _tmp("");
		delete[] _tmp._str;
		_tmp._size = _size * n;
		_tmp._str = new char[_tmp._size + 1];
        for (unsigned j = 0; j < n; j++)
		{
			for (unsigned i = 0; i < _size; i++)
			{
				_tmp._str[j * _size + i] = _str[i];
			}
		}
		_tmp._str[_size * n] = 0;
		return _tmp;
	};
	string GetSubstring(unsigned index, unsigned size, const string& rhs)
	{
		string _tmp;
		delete _tmp._str;
		_tmp._size = size;
		_tmp._str = new char[_tmp._size + 1];
		for (unsigned i = 0; i < size; i++)
		{
			_tmp._str[i] = rhs._str[index + i - 1];
		}
		_tmp._str[size] = 0;
		return _tmp;
	};
	string& operator=(const char* s)
	{
		delete[] _str;
		_size = std::strlen(s);
		_str = new char[_size + 1];
		std::strcpy(_str, s);
		return *this;
	}
	friend ostream& operator << (std::ostream& os, const string& s1)
	{
		os << s1._str;
		return os;
	};
};
char* newstroke()
{
	char str[100];
	gets_s(str);
	char* newstr = new char(strlen(str) + 1);
	strcpy(newstr, str);
	return newstr;
}

int main()
{
	string A;
	string B;
	string C;
	unsigned Menu;
	unsigned index;
	unsigned num;
	std::cout << "Laboratory work 1. Class:String\n";
	system("pause");
	for (;;)
	{
		system("cls");
		std::cout << "1.Get a symbol by index\n2.Write a symbol by index\n3.Concatenate two strings\n4.Multiplicate the string\n5.Change/write a string\n6.Get a substring\nEsc.Exit\n"; 
		std::cout << "First string:" << A << "\n";
		std::cout << "Second string:" << B << "\n";
		std::cout << "Result of the last operation:" << C << "\n";
		Menu = _getch();
		if (Menu == 27) break;
		switch (Menu)
		{
		case 49: 
			for (;;)
			{
				system("cls");
				std::cout << "Select string to get a symbol:" << "\n";
				std::cout << "1. " << A << "\n";
				std::cout << "2. " << B << "\n";
				std::cout << "Esc.Back to main menu" << "\n";
				Menu = _getch();
				if (Menu == 27) break;
				switch (Menu)
				{
				case 49: 
				{
					system("cls");
					std::cout << "Select index:" << "\n";
					std::cout << "1. " << A << "\n";
					std::cout << "Your index:";
					std::cin >> index;
					std::cout << "\n";
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					try {
						std::cout << "The symbol is:" << A[index - 1] << "\n";
					}
					catch (const char* err)
					{
						std::cerr << err << "\n";
						system("pause");
						break;
					}
					system("pause");
					break;
				}
				case 50: 
				{
					system("cls");
					std::cout << "Select index:" << "\n";
					std::cout << "2. " << B << "\n";
					std::cout << "Your index:";
					std::cin >> index;
					std::cout << "\n";
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					try {
						std::cout << "The symbol is:" << B[index - 1] << "\n";
					}
					catch (const char* err)
					{
						std::cerr << err << "\n";
						system("pause");
						break;
					}
					system("pause");
					break;
				}
				}
			}
			break;
		case 50: 
			for (;;)
			{
				system("cls");
				std::cout << "Select string" << "\n";
				std::cout << "1. " << A << "\n";
				std::cout << "2. " << B << "\n";
				std::cout << "Esc.Back to main menu" << "\n";
				Menu = _getch();
				if (Menu == 27) break;
				switch (Menu)
				{
				case 49: 
				{
					system("cls");
					std::cout << "Select index" << "\n";
					std::cout << "1. " << A << "\n";
					std::cout << "Your index:";
					std::cin >> index;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					try {
						char character;
						std::cout << "Your symbol:";
						std::cin >> character;
						A[index - 1] = character;
					}
					catch (const char* err)
					{
						std::cerr << err << "\n";
						system("pause");
						break;
					}
					std::cout << "New string: " << A << "\n";
					system("pause");
					break;
				}
				case 50: 
				{
					system("cls");
					std::cout << "Select index" << "\n";
					std::cout << "2. " << B << "\n";
					std::cout << "Your index:";
					std::cin >> index;
					std::cout << "\n";
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					try {
						char character;
						std::cout << "Your symbol:";
						std::cin >> character;
						B[index - 1] = character;
					}
					catch (const char* err)
					{
						std::cerr << err << "\n";
						system("pause");
						break;
					}
					std::cout << "New string: " << B << "\n";
					system("pause");
					break;
				}
				}
			}
			break;
		case 51: 
			for (;;)
			{
				system("cls");
				std::cout << "First string:" << A << "\n";
				std::cout << "Second string:" << B << "\n";
				std::cout << "Select an order to concatenate these strings" << "\n";
				std::cout << "1. 1+2" << "\n"; 
				std::cout << "2. 2+1" << "\n"; 
				std::cout << "Esc.Exit" << "\n";  
				Menu = _getch();
				if (Menu == 27) break;
				switch (Menu)
				{
				case 49:
					C = A + B;
					break;
				case 50:
					C = B + A;
					break;
				}
			}
			break;
		case 52:
			for (;;)
			{
				system("cls");
				std::cout << "Select string" << "\n";
				std::cout << "1. " << A << "\n";
				std::cout << "2. " << B << "\n";
				std::cout << "Esc.Back to main menu" << "\n";
				Menu = _getch();

				if (Menu == 27) break;
				switch (Menu)
				{
				case 49:
					std::cout << "Your coefficient:";
					std::cin >> index;
					std::cout << "\n";
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					C = A * index;
					break;
				case 50:
					std::cout << "Your coefficient:";
					std::cin >> index;
					std::cout << "\n";
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Enter the integer number!" << "\n";
						system("pause");
						break;
					}
					C = B * index;
					break;
				}
			}
			break;
		case 53: 
			for (;;)
			{
				system("cls");
				std::cout << "Select string" << "\n";
				std::cout << "1." << A << "\n";
				std::cout << "2." << B << "\n";
				std::cout << "Esc.Exit" << "\n";
				Menu = _getch();
				if (Menu == 27) break;
				switch (Menu)
				{
				case 49:
					std::cout << "Your string:";
					A = newstroke();
					break;
				case 50:
					std::cout << "Your string:";
					B = newstroke();
					break;
				}
			}
			break;
		case 54:
			for (;;)
			{
				system("cls");
				std::cout << "Select string" << "\n";
				std::cout << "1." << A << "\n";
				std::cout << "2." << B << "\n";
				std::cout << "Esc.Exit" << "\n";
				Menu = _getch();
				if (Menu == 27) break;
				switch (Menu)
				{
				case 49:
					std::cout << "Select index:";
					std::cin >> index;
					std::cout << "Select number of symbols:";
					std::cin >> num;
					C = C.GetSubstring(index, num, A);
					break;
				case 50:
					std::cout << "Select index:";
					std::cin >> index;
					std::cout << "Select number of symbols:";
					std::cin >> num;
					C = C.GetSubstring(index, num, B);
					break;
				}
			}
			break;
		}
	}
	return 0;
}