#include "complex.h"
#include <iostream>

ostream& operator<<(ostream& os, const Complex& rhs){
	if (rhs.im > 0) {
		os << to_string(rhs.re) << "+i" << to_string(rhs.im);
	}
	else {
		os << to_string(rhs.re) + "-i" + to_string(-rhs.im);
	}
	return os;
}

Complex operator+(double lhs, const Complex& rhs) {
	return Complex(lhs + rhs.re, rhs.im);
}

Complex operator-(double lhs, const Complex& rhs) {
	return Complex(lhs - rhs.re, rhs.im);
}

Complex operator*(double lhs, const Complex& rhs) {
	return Complex(lhs * rhs.re, lhs*rhs.im);
}

Complex operator/(double lhs, const Complex& rhs) {
	double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
	double newRe = lhs * rhs.re / (denominator * denominator);
	double newIm = -lhs * rhs.im / (denominator * denominator); 
	return Complex(newRe, newIm);
}

Complex Complex:: operator+(double lhs) {
	return Complex(re + lhs, im);
}

Complex Complex:: operator-(double lhs) {
	return Complex(re - lhs, im);
}

Complex Complex:: operator*(double lhs) {
	return Complex(re * lhs, im*lhs);
}

Complex Complex:: operator/(double lhs) {
	double newRe = re / lhs;
	double newIm = im / lhs;
	return Complex(newRe, newIm);
}

Complex Complex::conjugate()const {
	Complex res = Complex(re, -im);
	return res;
}

void Complex::setIm(double im) {
	this->im = im;
}

void Complex::setRe(double re) {
	this->re = re;
}

double Complex::magnitude()const {
	return sqrt(re * re + im * im);
}

Complex Complex::operator+(const Complex& rhs) const{
	return Complex(re + rhs.re, im+rhs.im);
}

Complex Complex::operator-(const Complex& rhs) const {
	return Complex(re- rhs.re, im-rhs.im);
}

Complex Complex::operator*(const Complex& rhs) const {
	return Complex(re * rhs.re-im*rhs.im, im * rhs.im+re*rhs.im);
}

Complex Complex::operator/(const Complex& rhs) const {
	double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
	double newRe = (re * rhs.re + im *rhs.im) / denominator;
	double newIm = (im * rhs.re - re * rhs.im) / denominator;
	return Complex(newRe, newIm);
}

