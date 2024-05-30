#ifndef GALOISFIELD_HPP
#define GALOISFIELD_HPP

#include <ostream>

class GaloisField {
private:
    static int primeNumber;
    int val; // value of the object
    int number(int a); // function to convert value of a into a value from the field range (from 0 to primeNumber-1)
    int extendedEuclideanAlgorithm(int a, int b, int& x, int& y);
    int invert(const int& a); // returns b for which a*b = 1 in this field
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

    operator int() const;

};

std::ostream& operator <<(std::ostream& os, GaloisField gs);
std::istream& operator >>(std::istream& is, GaloisField& gs);

#endif // GALOISFIELD_HPP