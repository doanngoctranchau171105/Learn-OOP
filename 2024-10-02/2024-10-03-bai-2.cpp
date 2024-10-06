#include <bits/stdc++.h>
using namespace std;
class COMPLEX {
	double real;
	double img;
	public:
		COMPLEX();
		COMPLEX(double r, double i);
		COMPLEX(const COMPLEX &comp);
		double getReal();
		double getImg();
		void print();
		double modulus() const;
		COMPLEX conjugate() const;
		COMPLEX operator + (const COMPLEX &comp) const;
		COMPLEX operator - (const COMPLEX &comp) const;
		COMPLEX operator * (const COMPLEX &comp) const;
		COMPLEX operator / (const COMPLEX &comp) const;
		COMPLEX operator += (const COMPLEX &comp);
		COMPLEX operator -= (const COMPLEX &comp);
		COMPLEX operator *= (const COMPLEX &comp);
		COMPLEX operator /= (const COMPLEX &comp);
		bool operator == (const COMPLEX &comp) const;
		bool operator != (const COMPLEX &comp) const;
};
COMPLEX::COMPLEX() {
	real = 0;
	img = 0;
}
COMPLEX::COMPLEX(double r, double i) {
	real = r;
	img = i;
}
COMPLEX::COMPLEX(const COMPLEX &comp) {
	real = comp.real;
	img = comp.img;
}
double COMPLEX::getReal() {
	return real;
}
double COMPLEX::getImg() {
	return img;
}
void COMPLEX::print() {
	if (img < 0) {
		cout << real << " - " << -img << "i";
	}
	else {
		cout << real << " + " << img << "i";
	}
}
double COMPLEX::modulus() const {
	return sqrt(real * real + img * img);
}
COMPLEX COMPLEX::conjugate() const{
	return COMPLEX(real, -img);
}
bool COMPLEX::operator == (const COMPLEX &comp) const {
	if (real == comp.real and img == comp.img) return true;
	return false;
}
bool COMPLEX::operator != (const COMPLEX &comp) const {
	if (real != comp.real or img != comp.img) return true;
	return false;
}
COMPLEX COMPLEX::operator + (const COMPLEX &comp) const {
	COMPLEX sum (real + comp.real, img + comp.img);
	return sum;
}
COMPLEX COMPLEX::operator - (const COMPLEX &comp) const {
	COMPLEX difference (real - comp.real, img - comp.img);
	return difference;
}
COMPLEX COMPLEX::operator * (const COMPLEX &comp) const {
	COMPLEX product (real * comp.real - img * comp.img, real * comp.img + img * comp.real);
	return product;
}
COMPLEX COMPLEX::operator / (const COMPLEX &comp) const {
	COMPLEX quotient ((real * comp.real + img * comp.img) / (comp.real * comp.real + comp.img * comp.img), (real * comp.img - img * comp.real) / (comp.real * comp.real + comp.img * comp.img));
	return quotient;
}
COMPLEX COMPLEX::operator += (const COMPLEX &comp) {
	real = real + comp.real;
	img = img + comp.img;
	return *this;
}
COMPLEX COMPLEX::operator -= (const COMPLEX &comp) {
	real = real - comp.real;
	img = img - comp.img;
	return *this;
}
COMPLEX COMPLEX::operator *= (const COMPLEX &comp) {
	real = real * comp.real - img * comp.img;
	img = real * comp.img + img * comp.real;
	return *this;
}
COMPLEX COMPLEX::operator /= (const COMPLEX &comp) {
	real = (real * comp.real + img * comp.img) / (comp.real * comp.real + comp.img * comp.img);
	img = (real * comp.img - img * comp.real) / (comp.real * comp.real + comp.img * comp.img);
	return *this;
}
int main() {
	double r, i;
	cin >> r >> i;
	COMPLEX comp1(r, i);
	COMPLEX comp2(comp1);
	cout << comp1.getReal() << " " << comp1.getImg() << endl;
	cout << comp1.modulus() << endl;
	comp1 = comp1.conjugate();
	comp1.print();
	cout << endl;
	COMPLEX sum, difference, product, quotient;
	sum = comp1 + comp2;
	difference = comp1 - comp2;
	product = comp1 * comp2;
	quotient = comp1 / comp2;
	sum.print();
	cout << endl;
	difference.print();
	cout << endl;
	product.print();
	cout << endl;
	quotient.print();
	cout << endl;
	comp1 += comp2;
	comp1 -= comp2;
	comp1 *= comp2;
	comp1 /= comp2;
	comp1.print();
	cout << endl;
	if (comp1 == comp2) {
		comp1.print();
		cout << " == ";
		comp2.print();
	}
	else {
		comp1.print();
		cout << " != ";
		comp2.print();
	}
	return 0;
}
