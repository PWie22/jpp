
#include "galoisField.hpp"
#include <iostream>
#include <ostream>

int GaloisField::primeNumber = 0;

GaloisField::GaloisField() {}

GaloisField::GaloisField(int val) {
    this->val = number(val);
}

GaloisField::~GaloisField() {}

int GaloisField::number(int a) {
    if (a < 0) {
        while (a < 0) {
            a += primeNumber;
        }
        return a;
    }
    return a % primeNumber;
}

int GaloisField::extendedEuclideanAlgorithm(int a, int b, int& x, int& y) {
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int c, temp, nextX, nextY;
    while (b != 0) {
        c = a / b;
        temp = b;
        b = a % b;
        a = temp;
        nextX = x0 - c * x1;
        nextY = y0 - c * y1;
        x0 = x1;
        y0 = y1;
        x1 = nextX;
        y1 = nextY;
    }

    x = x0;
    y = y0;

    return a;
}

int GaloisField::invert(const int& a) {
    int x, y;
    int extEuc = extendedEuclideanAlgorithm(a, primeNumber, x, y);
    if (extEuc == 1) {
        return (x % primeNumber + primeNumber) % primeNumber;
    }
    return -1;
}

int GaloisField::getValue() {
    return this->val;
}

void GaloisField::setValue(int newVal) {
    this->val = number(newVal);
}

GaloisField GaloisField::operator +(const int& a) {
    return GaloisField(this->val + a);
}

GaloisField GaloisField::operator -(const int& a) {
    return GaloisField(this->val - a);
}

GaloisField GaloisField::operator *(const int& a) {
    long long aa = number(a);
    int res = (this->val * aa) % primeNumber;
    return GaloisField(res % primeNumber);
}

GaloisField GaloisField::operator /(const int& a) {
    if (a == 0) {
        throw std::domain_error("You can't divide by zero.");
    }
    int inverted = invert(a);
    if (inverted == -1) {
        throw std::domain_error("Given value is not invertible.");
    }
    return operator*(inverted);
}

GaloisField GaloisField::operator =(const int& a) {
    this->val = number(a);
    return *this;
}

GaloisField GaloisField::operator +=(const int& a) {
    this->val = number(this->val + a);
    return *this;
}

GaloisField GaloisField::operator -=(const int& a) {
    this->val = number(this->val - a);
    return *this;
}

GaloisField GaloisField::operator *=(const int& a) {
    this->val = operator*(a).val;
    return *this;
}

GaloisField GaloisField::operator /=(const int& a) {
    this->val = operator/(a).val;
    return *this;
}

bool GaloisField::operator ==(const int& a) {
    if (this->val == number(a)) {
        return true;
    }
    return false;
}

bool GaloisField::operator !=(const int& a) {
    if (this->val != number(a)) {
        return true;
    }
    return false;
}

bool GaloisField::operator <=(const int& a) {
    if (this->val <= number(a)) {
        return true;
    }
    return false;
}

bool GaloisField::operator >=(const int& a) {
    if (this->val >= number(a)) {
        return true;
    }
    return false;
}

bool GaloisField::operator <(const int& a) {
    if (this->val < number(a)) {
        return true;
    }
    return false;
}

bool GaloisField::operator >(const int& a) {
    if (this->val > number(a)) {
        return true;
    }
    return false;
}

GaloisField::operator int() const {
    return this->val;
}

std::ostream& operator <<(std::ostream& os, GaloisField gs) {
    return os << gs.getValue();
}

std::istream& operator >>(std::istream& is, GaloisField& gs) {
    int a;
    is >> a;
    gs.setValue(a);
    return is;
}