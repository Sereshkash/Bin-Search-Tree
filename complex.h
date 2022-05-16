#pragma once
#include <iostream>
#include <math.h>

class Complex
{
private:
	double Re, Im;
public:
	Complex(double x = 0.0, double y = 0.0) {
		this->Re = x;
		this->Im = y;
	}
    void SetRe(double x);
    void SetIm(double y);
	double GetRe();
	double GetIm();
	double GetAbs();
    Complex Squaring();
	void operator +=(Complex);
	void operator -=(Complex);
	void operator *=(Complex);
    void operator =(Complex);
	bool operator ==(Complex); 
	bool operator !=(Complex); 
    void Print();
};

double Complex::GetRe() {
	return this->Re;
}

double Complex::GetIm() {
	return this->Im;
}

double Complex::GetAbs() {
	return sqrt(pow(Im, 2) + pow(Re, 2));
}

Complex operator +(Complex c1, Complex c2) {
	return Complex(c1.GetRe() + c2.GetRe(), c1.GetIm() + c2.GetIm());
}

Complex operator -(Complex c1, Complex c2) {
	return Complex(c1.GetRe() - c2.GetRe(), c1.GetIm() - c2.GetIm());
}

Complex operator *(Complex c1, Complex c2) {
	return Complex(c1.GetRe() * c2.GetRe() - c1.GetIm() * c2.GetIm(), 
		c1.GetRe()* c2.GetIm() + c1.GetIm() * c2.GetRe());
}

std::ostream& operator <<(std::ostream & out, Complex c) {
	if (c.GetIm() >= 0) {
        out << c.GetRe() << "+" << c.GetIm() << "*i";
    } else {
        out << c.GetRe() << c.GetIm() << "*i";
    }
	return out;
}

void Complex::operator +=(Complex c) {
	this->Re = this->GetRe() + c.GetRe();
	this->Im = this->GetIm() + c.GetIm();
}

void Complex::operator -=(Complex c) {
	this->Re = this->GetRe() - c.GetRe();
	this->Im = this->GetIm() - c.GetIm();
}

void Complex::operator *=(Complex c) {
	this->Re = this->GetRe() * c.GetRe() - this->GetIm() * c.GetIm();
	this->Im = this->GetRe()* c.GetIm() + this->GetIm() * c.GetRe();
}

void Complex::operator =(Complex c) {
    this->Re = c.GetRe();
	this->Im = c.GetIm();
}

bool Complex::operator==(Complex c) {
	if (this->Re == c.Re && this->Im == c.Im) {
		return true;
	} else {
		return false;
	}
	
}

bool Complex::operator!=(Complex c) {
	return !(*this == c);
	
}

void Complex::Print() {
    if (Im >= 0) {
        std::cout << Re << "+" << Im << "*i\n";
    } else {
        std::cout << Re << Im << "*i\n";
    }
}

Complex Complex::Squaring() {
    return (*this) * (*this);
}

void Complex::SetRe(double x) {
    this->Re = x;
}

void Complex::SetIm(double y) {
    this->Im = y;
}