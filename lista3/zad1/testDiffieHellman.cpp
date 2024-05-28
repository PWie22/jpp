
#include "galoisField.hpp"
#include "diffieHellman.hpp"
#include "DHUser.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char *args[]) {
    GaloisField::setPrimeNumber(1234567891);

    DHSetup<GaloisField> dhs(GaloisField::getPrimeNumber());

    User<GaloisField> user1(dhs, GaloisField::getPrimeNumber());
    User<GaloisField> user2(dhs, GaloisField::getPrimeNumber());

    try {
        user1.setKey(user2.getPublicKey());
        user2.setKey(user1.getPublicKey());

        GaloisField e = user1.encrypt(GaloisField(1003207));
        std::cout << user2.decrypt(e) << std::endl;
        e = user2.encrypt(GaloisField(372986001));
        std::cout << user1.decrypt(e) << std::endl;

    }
    catch (char const* e) {
        std::cout << "Error: " << e << std::endl;
    }

    
}