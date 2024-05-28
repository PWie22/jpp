
/*#include "diffieHellman.hpp"
#include <set>
#include <ctime>
#include <random>

template <typename T>
bool DHSetup<T>::checkIfCanBeGenerator(int characteristics, int candidate, std::set<int> primes) {
    // czy nie lepiej w metodzie zamiast int zrobić T, bo wtedy chyba możnaby podać GaloisField i też powinno działać
    for (int p : primes) {
        int res = (characteristics - 1) / p;
        res *= candidate;
        if (res == 1) // zastanowić się, czy tutaj nie wyjdzie poza zakres
            return false;
    }
    return true;
}

template <typename T>
int DHSetup<T>::generateGenerator(int characteristics) {
    int a = characteristics - 1;
    int i = 2;
    std::set<int> primes; // zbiór z liczbami pierwszymi, które dzielą a
    while(a > 1) {
        if (a % i == 0)
            primes.insert(i);
        // jeżeli dana liczba pierwsza występuje w rozkładzie więcej niż raz, to w pętli
        // ten problem zostanie rozwiązany - zrobione, żeby bez sensu nie wywoływać metody add
        // kilka razy dla tego samego elementu (i tak zostałby dodany tylko raz)
        while (a % i == 0) {
            a /= i;
        }
        i++;
    }
    // teraz trzeba wylosować liczbę i sprawdzić, czy jest ona generatorem
    std::mt19937 mt(time(nullptr));
    bool generatorFound = false;
    int randNumb;
    while(!generatorFound) {
        randNumb = mt() % characteristics;
        generatorFound = checkIfCanBeGenerator(characteristics, randNumb, primes);
    }
    return randNumb;
}

template <typename T>
DHSetup<T>::DHSetup(T characteristics) {
    //this->characteristics = characteristics;
    this->generator = generateGenerator(characteristics);
}

template <typename T>
DHSetup<T>::~DHSetup() {}

template <typename T>
T DHSetup<T>::getGenerator() {
    return this->generator;
}

// a to jest chyba klucz publiczny, który znają wszyscy, a b to jest sekret (potęga do której podnosimy a)
// wynik tej funkcji, czyli a^b, jest potrzebny do szyfrowania wiadomości w metodzie encrypt() w klasie User
template <typename T>
T DHSetup<T>::power(T a, unsigned long b) {
    T res = 1; // ewentualnie typ może być long long
    while(b > 0) {
        if (b%2 == 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}*/
