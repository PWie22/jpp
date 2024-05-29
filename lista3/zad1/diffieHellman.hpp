
#ifndef DIFFIEHELLMAN_HPP
#define DIFFIEHELLMAN_HPP

#include <ctime>
#include <random>
#include <list>

std::mt19937 mt(time(nullptr));

template <typename T>
class DHSetup {
private:
    T generator;
    bool checkIfCanBeGenerator(int characteristics, T candidate, std::list<int> primes) {
        int res, exp;
        for (int p : primes) {
            exp = (characteristics - 1) / p;
            res = power(candidate, exp);
            if (res == 1)
                return false;
        }
        return true;
    };

    std::list<int> factorIntoPrimes(int a) {
        std::list<int> primes;
        int i = 2;
        while (a > 1) {
            if (a % i == 0) {
                primes.push_back(i);
                while (a % i == 0) {
                    a /= i;
                }
            }
            i += 1;
        }
        return primes;
    }

    T generateGenerator(int characteristics) {
        int i = 2;
        std::list<int> primes = factorIntoPrimes(characteristics - 1);
        std::uniform_int_distribution<> dis(1, characteristics - 1);
        bool generatorFound = false;
        T randNumb;
        while (!generatorFound) {
            randNumb = dis(mt);
            generatorFound = checkIfCanBeGenerator(characteristics, randNumb, primes);
        }
        return randNumb;
    };
public:
    DHSetup(int characteristics) {
        this->generator = generateGenerator(characteristics);
    };

    ~DHSetup() {};

    T getGenerator() {
        return this->generator;
    };

    T power(T a, unsigned long b) {
        T res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res *= a;
            }
            a *= a;
            b /= 2;
        }
        return res;
    };
};

#endif // DIFFIEHELLMAN_HPP