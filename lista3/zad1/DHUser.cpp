
//#include "DHUser.hpp"
//#include <ctime>
//#include <random>

/*template <typename T>
User<T>::User(const DHSetup<T>& dhs) {
    this->dhs = dhs;
    // tu jeszcze musi być ustawiany losowy sekret - chyba trzeba wylosować jakąś liczbę, która będzie używana jako potęga
    // jeżeli tak ma być, to będzie zapisana w prywatnym polu secretPower
    std::mt19937 mt(time(nullptr));
    this->secretPower = mt(); // tutaj jeszcze jakoś trzeba dostać charakterystykę ciała, żeby zrobić modulo
}

template <typename T>
User<T>::~User() {}*/

/*template <typename T>
T User<T>::getSecret() {
    return this->secretPower;
}*/

/*template <typename T>
T User<T>::getPublicKey() {
    return dhs.power(dhs.getGenerator(), this->secretPower);
}

template <typename T>
void User<T>::setKey(T a) {
    this->privateKey = dhs.power(a, this->secretPower);
}

template <typename T>
T User<T>::encrypt(T m) {
    return m * this->privateKey;
}

template <typename T>
T User<T>::decrypt(T c) {
    return c / this->privateKey;
}*/