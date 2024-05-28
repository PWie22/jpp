#ifndef DHUSER_HPP
#define DHUSER_HPP

#include "diffieHellman.hpp"

template <typename T>
class User {
    private:
        T privateKey;
        bool isKeySet = false;
        T secretPower;
        DHSetup<T> dhs;
    public:
        User(DHSetup<T> dhs, int characteristics) : dhs(dhs) {
            std::uniform_int_distribution<> dis(1, characteristics-1);
            this->secretPower = dis(mt);
        };
        ~User() {};
        
        T getPublicKey() {
            return dhs.power(dhs.getGenerator(), this->secretPower);
        };

        void setKey(T a) {
            this->privateKey = dhs.power(a, this->secretPower);
            this->isKeySet = true;
        };

        T encrypt(T m) {
            if (!isKeySet)
                throw "You have not set the key yet.";
            return m * this->privateKey;
        };

        T decrypt(T c) {
            if (!isKeySet)
                throw "You have not set the key yet.";
            return c / this->privateKey;
        };
};

#endif // DHUSER_HPP