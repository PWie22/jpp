#ifndef GALOISFIELD_HPP
#define GALOISFIELD_HPP

#include <ostream>

class GaloisField {
private:
    static int primeNumber; // liczba, która jest generatorem ciała
    int val;
    int number(int a);
    int extendedEuclideanAlgorithm(int a, int b, int& x, int& y);
    int invert(const int& a);
public:
    GaloisField(int val);
    ~GaloisField();

    static void setPrimeNumber(int prime) {
        primeNumber = prime;
    };

    static int getPrimeNumber() {
        return primeNumber;
    };

    int getValue();
    void setValue(int newVal);

    GaloisField operator +(const int& a);
    GaloisField operator -(const int& a);
    GaloisField operator *(const int& a);
    GaloisField operator /(const int& a);

    GaloisField operator =(const int& a);
    GaloisField operator +=(const int& a);
    GaloisField operator -=(const int& a);
    GaloisField operator *=(const int& a);
    GaloisField operator /=(const int& a);

    bool operator ==(const int& a);
    bool operator !=(const int& a);
    bool operator <=(const int& a);
    bool operator >=(const int& a);
    bool operator <(const int& a);
    bool operator >(const int& a);

};

std::ostream& operator <<(std::ostream& os, GaloisField gs);
std::istream& operator >>(std::istream& is, GaloisField& gs);

#endif // GALOISFIELD_HPP