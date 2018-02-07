#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rational
{
private:
	int numerator = 0;
	int denominator = 1;

	friend ostream& operator<<(ostream& os, const Rational& rhs);

	friend istream& operator>>(istream& is, const Rational& rhs);
	
	friend bool operator==(const Rational& rhs, const Rational& comp);
	
	

public:
	Rational(int numerator = 0, int denominator = 0): numerator(numerator), denominator(denominator){}

	Rational& operator+=(const Rational& adder)
	{
		int num1 = numerator;
		int dem1 = denominator;

		int num2 = adder.numerator;
		int dem2 = adder.denominator;

		int finalDem = dem1*dem2;

		num1 *= dem2;

		num2 *= dem1;

		int finalNum = num1 + num2;

		numerator = finalNum;
		denominator = finalDem;

		return *this;

	}

	Rational& operator=(const int assign)
	{
		this->numerator = assign;
		this->denominator = 1;

		return *this;
	}

	Rational& operator++()
	{
		numerator += denominator;
		return *this;
	}

	Rational operator++(int dummy)
	{
		Rational previous(*this);
		numerator += denominator;
		return previous;
	}

	int greatestCommonDivisor(int x, int y) const {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	double simplified() const 
	{
		int num = numerator;
		int den = denominator;

		if (den < 0)
		{
			den *= -1;
			num *= -1;
		}

		int div = greatestCommonDivisor(numerator, denominator);

		den = den / div;
		num = num / div;

		return (double)num / den;
	}

	int getDem() const
	{
		return denominator;
	}

	int getNum() const
	{
		return numerator;
	}

	void setNum(int n)
	{
		numerator = n;
	}

	void setDen(int n)
	{
		denominator = n;
	}
};

int greatestCommonDivisor(int x, int y) {
	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

double simplify(int x, int y)
{
	int num = x;
	int den = y;

	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}

	int div = greatestCommonDivisor(x, y);

	den = den / div;
	num = num / div;

	return (double)num / den;
}


ostream& operator<<(ostream& os, const Rational& rhs) {
	int num = rhs.numerator;
	int den = rhs.denominator;

	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}
	
	int div = greatestCommonDivisor(rhs.numerator, rhs.denominator);

	den = den / div;
	num = num / div;

	os << num << "/" << den << endl;
	return os;
}

istream& operator>>(istream& is, Rational& rhs)
{
	int num;
	char slash;
	int den;

	if (is >> num >> slash >> den)
	{
		rhs.setNum(num);
		rhs.setDen(den);

	}

	return is;
}



Rational operator+(const Rational& rhs, const Rational& adder)
{
	Rational result(rhs);
	result += adder;
	return result;
}

bool operator==(const Rational& rhs, const Rational& comp)
{
	return (simplify(rhs.numerator, rhs.denominator) == simplify(comp.numerator, comp.denominator));
}

bool operator!=(const Rational& rhs, const Rational& comp)
{
	return !(rhs.simplified() == comp.simplified());
}



Rational& operator--(Rational& rhs)
{
	
	rhs.setNum(rhs.getNum()-rhs.getDem());
	return rhs;
}

Rational operator--(Rational& rhs, int )
{
	Rational temp = rhs;
	rhs.setNum(rhs.getNum() - rhs.getDem());
	return temp;
}



int main()
{
	Rational a, b;
	cout << "Input two rational numbers.\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	Rational one = 1;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;
	cout << "a + one: " << (a + one) << endl;	// Implement as non-member, but not a friend
	cout << "a == one: " << boolalpha << (a == one) << endl;
	cout << "1 == one: " << boolalpha << (1 == one) << endl;  // How does this work?
	cout << "a != one: " << boolalpha << (a != one) << endl;  // Do not implement as friend.

	cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
	cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;
	system("pause");
}