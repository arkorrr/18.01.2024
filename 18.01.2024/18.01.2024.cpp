#include <iostream>

using namespace std;

class Drob {
private:
    int numerator;
    int denominator;
    friend Drob operator*(const int& i, const Drob& other);
public:
    Drob(int num, int dem) {
        if (dem == 0) {
            cout << "ERROR: zero detected!";
            exit(1);
        }
        numerator = num;
        denominator = dem;
    }

    Drob operator+(const Drob& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int dem = denominator * other.denominator;
        return Drob(num, dem);
    }

    Drob operator-(const Drob& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int dem = denominator * other.denominator;
        return Drob(num, dem);
    }

    Drob operator*(const Drob& other) const {
        int num = numerator * other.numerator;
        int dem = denominator * other.denominator;
        return Drob(num, dem);
    }
    Drob operator*(const int& i) const
    {
        int num = numerator * i;
        int dem = denominator;
        return Drob(num, dem);
    }
    Drob operator/(const Drob& other) const {
        if (other.numerator == 0) {
            cout << "ERROR: zero detected!";
            exit(1);
        }
        int num = numerator * other.denominator;
        int dem = denominator * other.numerator;
        return Drob(num, dem);
    }
    Drob operator++()
    {
        numerator++;
        denominator++;
        return *this;
    }
    Drob operator++ (int)
    {
        Drob temp(*this);
        ++(*this);
        return temp;
    }
    operator double()
    {
        return double(numerator) / double(denominator);
    }
    friend istream& operator>>(istream& is, Drob& P);
    friend ostream& operator<<(ostream& os, const Drob& P);
};

Drob operator*(const int& i, const Drob& other)
{
    int num = other.numerator * i;
    int dem = other.denominator;
    return Drob(num, dem);
}

istream& operator>>(istream& is, Drob& P) {
    cout << "Numerator: \t";
    is >> P.numerator;
    cout << "Denominator: \t";
    is >> P.denominator;
    return is;
}

ostream& operator<<(ostream& os, const Drob& P)
{
    os << "Numerator = " << P.numerator << '\t';
    os << "Denominator = " << P.denominator << '\n';
    return os;
}

class MyString
{
	char* str;
	static int count;
	int field = 80;
public:
	MyString()
	{
		str = new char[field];
		count++;
	}
	MyString(const char* text)
	{
		str = new char[strlen(text) + 1];
		strcpy_s(str, strlen(text) + 1, text);
		count++;
	}
	MyString(const MyString& other)
	{
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
		count++;
	}
	~MyString()
	{
		delete[] str;
		count--;
	}

	MyString& operator++()
	{
		int len = strlen(str);
		char* newStr = new char[len + 2];
		strcpy_s(newStr, len + 2, str);
		newStr[len] = 'x';
		newStr[len + 1] = '\0';
		delete[] str;
		str = newStr;
		return *this;
	}

	MyString operator++(int)
	{
		MyString temp = *this;
		++(*this);
		return temp;
	}
    MyString operator+(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        char* temp = new char[overload + n + 1];
        for (int i = 0; i < n; ++i)
        {
            temp[i] = 'x';
        }
        int j = 0;
        for (int i = n; i < overload + n; i++)
        {
            temp[i] = result.str[j];
            j++;
        }
        temp[overload + n] = '\0';
        delete[] result.str;
        result.str = temp;
        return result;
    }
    friend MyString operator+(int n, const MyString& Str)
    {
        return Str + n;
    }
	MyString& operator--()
	{
		int len = strlen(str);
		if (len > 0)
		{
			char* newStr = new char[len];
			strncpy_s(newStr, len, str, len - 1);
			newStr[len - 1] = '\0';
			delete[] str;
			str = newStr;
		}
		return *this;
	}
	MyString operator--(int)
	{
		MyString temp = *this;
		--(*this);
		return temp;
	}
    MyString operator-(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        if (n < overload)
        {
            char* temp = new char[overload - n + 1];
            strncpy_s(temp, overload - n + 1, result.str, overload - n);
            temp[overload - n] = '\0';
            delete[] result.str;
            result.str = temp;
        }
        else
        {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
        }
        return result;
    }
    friend MyString operator-(int n, const MyString& Str)
    {
        return Str - n;
    }
	MyString& operator=(const MyString& other)
	{
		if (this != &other)
		{
			delete[] str;
			str = new char[strlen(other.str) + 1];
			strcpy_s(str, strlen(other.str) + 1, other.str);
		}
		return *this;
	}
	void input()
	{
		char buffer[256];
		cin.getline(buffer, 256);
		str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer) + 1, buffer);
	}

	void output() const
	{
		cout << "String: " << str << endl;
	}

	static int getCount()
	{
		return count;
	}
};

int MyString::count = 0;

int main()
{
    //Task1
    /*Drob obj(1, 1);
    cout << obj * 3;*/

    //Task2
    MyString str("Hello");
    MyString sum = 8 + str;
    sum.output();

    return 0;
}

