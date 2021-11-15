#include <iostream>
#include <math.h>
using namespace std;

class Fraction
{
	int numerator;
	int denumerator;

	void NOD()
	{

		int n = numerator;
		int d = denumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n = n % d;
			}
			else
			{
				d = d % n;
			}
		}
		numerator = numerator / (n + d);
		denumerator = denumerator / (n + d);

	}
public:

	Fraction(int numerator = 0, int denumerator = 1)
	{
		this->numerator = numerator;
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
		{
			this->denumerator = 1;
		}
		NOD();
	}
	void SetDenumerator(int denumerator)
	{
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
		{
			this->denumerator = 1;
		}
	}

	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	int GetDenumerator()
	{
		return this->denumerator;
	}

	int GetNumerator()
	{
		return this->numerator;
	}

	void print()
	{
		cout << this->numerator << "/" << this->denumerator << "\n";
	}

	static Fraction add(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator + fodj2.numerator * fodj1.denumerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction sub(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction((fodj1.numerator * fodj2.denumerator) - (fodj2.numerator * fodj1.denumerator), fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction mult(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.numerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction div(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator, fodj2.numerator * fodj1.denumerator);
	}

	static bool ravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) == (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolse(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) > (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool menche(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) < (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolseiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) >= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool mencheiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) <= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static Fraction plusplus(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator + fodj1.denumerator;
		return fodj1;
	}

	static Fraction minysminys(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator - fodj1.denumerator;
		return fodj1;
	}

	static Fraction pow(Fraction& fodj1)
	{
		return fodj1 * fodj1;
	}

	static Fraction sqrt(Fraction& fodj1)
	{
		return Fraction(fodj1.numerator %2, fodj1.denumerator /2);
	}


	friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2)
	{
		return add(fraction1, fraction2);
	}

	friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
	{
		return sub(fraction1, fraction2);
	}

	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
	{
		return mult(fraction1, fraction2);
	}

	friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2)
	{
		return div(fraction1, fraction2);
	}

	friend ostream& operator<<(ostream& output, const Fraction& fraction1)
	{
		output << fraction1.numerator<<"/"<<fraction1.denumerator;
		return output;
	}

	friend bool operator== (const Fraction& fraction1, const Fraction& fraction2)
	{
		return ravni(fraction1, fraction2);
	}

	friend bool operator> (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolse(fraction1, fraction2);
	}

	friend bool operator< (const Fraction& fraction1, const Fraction& fraction2)
	{
		return menche(fraction1, fraction2);
	}

	friend bool operator>= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolseiliravni(fraction1, fraction2);
	}

	friend bool operator<= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return mencheiliravni(fraction1, fraction2);
	}

	friend Fraction operator++ (Fraction& fraction1)
	{
		return plusplus(fraction1);
	}

	friend Fraction operator-- (Fraction& fraction1)
	{
		return minysminys(fraction1);
	}

	friend Fraction pow (Fraction& fraction1)
	{
		return pow(fraction1);
	}

	friend Fraction sqrt(Fraction& fraction1)
	{
		return sqrt(fraction1);
	}


};



int main()
{
	setlocale(LC_ALL, "Rus");
	Fraction drob1(1,2);
	Fraction drob2(1,16);

	cout << drob1 + drob2 << "\n";
	cout << drob1 - drob2 << "\n";
	cout << drob1 * drob2 << "\n";
	cout << drob1 / drob2 << "\n";
	if (drob1 == drob2)
	{
		cout << "\nРавны\n";
	}

	if (drob1 > drob2)
	{
		cout << "\nБольше\n";
	}

	if (drob1 < drob2)
	{
		cout << "\nМеньше\n";
	}

	if (drob1 >= drob2)
	{
		cout << "\nБольше или равны\n";
	}

	if (drob1 <= drob2)
	{
		cout << "\nМеньше или равны\n";
	}

	//cout << "\n++drob1 " << ++drob1 << "\n";
	//cout << "\n--drob1 " << --drob2 << "\n";
	cout << "\ndrob1 в 2 " << pow(drob1) << "\n";
	cout << "\ndrob2 в корне " << sqrt(drob2);
	return 0;
}