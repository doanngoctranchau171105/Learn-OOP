#include <bits/stdc++.h>
using namespace std;
class FRACTION {
	int numerator;
	int denominator;
	public:
		FRACTION();
		FRACTION(int n, int d);
		FRACTION(const FRACTION &frac);
		void setNumerator(int n);
		void setDenominator(int d);
		int getNumerator();
		int getDenominator();
		bool isValid();
		void normalize();
		void set(int n, int d);
		void reduce();
		void print() const;
		FRACTION operator + (const FRACTION &frac) const;
		FRACTION operator - (const FRACTION &frac) const;
		FRACTION operator * (const FRACTION &frac) const;
		FRACTION operator / (const FRACTION &frac) const;
		FRACTION operator += (const FRACTION &frac);
		FRACTION operator -= (const FRACTION &frac);
		FRACTION operator *= (const FRACTION &frac);
		FRACTION operator /= (const FRACTION &frac);
		bool operator > (const FRACTION &frac) const;
		bool operator >= (const FRACTION &frac) const;
		bool operator < (const FRACTION &frac) const;
		bool operator <= (const FRACTION &frac) const;
		bool operator == (const FRACTION &frac) const;
		bool operator != (const FRACTION &frac) const;
};
FRACTION::FRACTION() {
	numerator = 0;
	denominator = 1;
}
FRACTION::FRACTION(int n, int d) {
	numerator = n;
	denominator = d;
}
FRACTION::FRACTION(const FRACTION &frac) {
	numerator = frac.numerator;
	denominator = frac.denominator;
}
void FRACTION::setNumerator(int n) {
	numerator = n;
}
void FRACTION::setDenominator(int d) {
	if (d != 0) {
		denominator = d;
	}
	else denominator = 1;
}
int FRACTION::getNumerator() {
	return numerator;
}
int FRACTION::getDenominator() {
	return denominator;
}
bool FRACTION::isValid() {
	if (denominator == 0) return false;
	return true;
}
void FRACTION::normalize() {
	if (denominator < 0) {
		numerator = - numerator;
		denominator = - denominator;
	}
}
void FRACTION::set(int n, int d) {
	numerator = n;
	denominator = d;
	normalize();
}
void FRACTION::reduce() {
	int n, d;
	if (!isValid()) {
		return;
	}
	n = abs(numerator);
	d = abs(denominator);
	while(n != d) {
		if (n > d) {
			n = n - d;
		}
		else {
			d = d - n;
		}
	}
	numerator = numerator / n;
	denominator = denominator / n;
}
void FRACTION::print() const {
	if (denominator == 1) {
		cout << numerator;
	}
	else {
		cout << numerator << "/" << denominator;
	}
}
FRACTION FRACTION::operator + (const FRACTION &frac) const {
	FRACTION sum (numerator * frac.denominator + frac.numerator * denominator, denominator * frac.denominator);
	sum.reduce();
	return sum;
}
FRACTION FRACTION::operator - (const FRACTION &frac) const {
	FRACTION difference (numerator * frac.denominator - frac.numerator * denominator, denominator * frac.denominator);
	difference.reduce();
	return difference;
}
FRACTION FRACTION::operator * (const FRACTION &frac) const {
	FRACTION product (numerator * frac.numerator, denominator * frac.denominator);
	product.reduce();
	return product;
}
FRACTION FRACTION::operator / (const FRACTION &frac) const {
	FRACTION quotient (numerator * frac.denominator, denominator * frac.numerator);
	quotient.reduce();
	return quotient;
}
FRACTION FRACTION::operator += (const FRACTION &frac) {
	numerator = numerator * frac.denominator + frac.numerator * denominator;
	denominator = denominator * frac.denominator;
	reduce();
	return *this;
}
FRACTION FRACTION::operator -= (const FRACTION &frac) {
	numerator = numerator * frac.denominator - frac.numerator * denominator;
	denominator = denominator * frac.denominator;
	reduce();
	return *this;
}
FRACTION FRACTION::operator *= (const FRACTION &frac) {
	numerator = numerator * frac.numerator;
	denominator = denominator * frac.denominator;
	reduce();
	return *this;
}
FRACTION FRACTION::operator /= (const FRACTION &frac) {
	numerator = numerator * frac.denominator;
	denominator = denominator * frac.numerator;
	reduce();
	return *this;
}
bool FRACTION::operator > (const FRACTION &frac) const {
	return (float(numerator / denominator) > float(frac.numerator / frac.denominator));
}
bool FRACTION::operator >= (const FRACTION &frac) const {
	return (float(numerator / denominator) >= float(frac.numerator / frac.denominator));
}
bool FRACTION::operator < (const FRACTION &frac) const {
	return (float(numerator / denominator) < float(frac.numerator / frac.denominator));
}
bool FRACTION::operator <= (const FRACTION &frac) const {
	return (float(numerator / denominator) <= float(frac.numerator / frac.denominator));
}
bool FRACTION::operator == (const FRACTION &frac) const {
	return (float(numerator / denominator) == float(frac.numerator / frac.denominator));
}
bool FRACTION::operator != (const FRACTION &frac) const {
	return (float(numerator / denominator) != float(frac.numerator / frac.denominator));
}
int main() {
	int n, d;
	cin >> n >> d;
	FRACTION frac1 (n, d);
	FRACTION frac3(frac1);
	frac1.setNumerator(n);
	frac1.setDenominator(d);
	frac1.print();
	cout << endl;
	cout << frac1.getNumerator() << endl;
	cout << frac1.getDenominator() << endl;
	if (frac1.isValid()) {
		cout << "Valid" << endl;
	}
	else cout << "Not Valid" << endl;
	frac1.normalize();
	frac1.print();
	cout << endl;
	frac1.set(n, d);
	frac1.reduce();
	frac1.print();
	cout << endl;
	FRACTION frac2(3, 4);
	FRACTION sum = frac1 + frac2;
	sum.print();
	cout << endl;
	FRACTION difference = frac1 - frac2;
	difference.print();
	cout << endl;
	FRACTION product = frac1 * frac2;
	product.print();
	cout << endl;
	FRACTION quotient = frac1 / frac2;
	quotient.print();
	cout << endl;
	frac1 += frac2;
	frac1.print();
	cout << endl;
	frac1 -= frac2;
	frac1.print();
	cout << endl;
	frac1 *= frac2;
	frac1.print();
	cout << endl;
	frac1 /= frac2;
	frac1.print();
	cout << endl;
	if (frac1 > frac2) {
		frac1.print();
		cout << " > ";
		frac2.print();
	}
	else if (frac1 >= frac2) {
		frac1.print();
		cout << " >= ";
		frac2.print();
	}
	else if (frac1 < frac2) {
		frac1.print();
		cout << " < ";
		frac2.print();
	}
	else if (frac1 <= frac2) {
		frac1.print();
		cout << " <= ";
		frac2.print();
	}
	else if (frac1 == frac2) {
		frac1.print();
		cout << " == ";
		frac2.print();
	}
	else {
		frac1.print();
		cout << " != ";
		frac2.print();
	}
	return 0;
}
