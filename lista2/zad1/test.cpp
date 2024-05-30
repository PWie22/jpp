#include "galoisField.hpp"
#include <iostream>
#include <cassert>

#define GREEN "\033[32m"
#define WHITE "\033[0m"

int main(int argc, char* argv[]) {
    const int primeNumber = 1234577;

    GaloisField::setPrimeNumber(primeNumber);

    GaloisField gs(1);

    assert(gs + 1234577 == 1);
    assert(gs + 0 == 1);
    assert(gs + (-1) == 0);
    assert(gs + 1234576 == 0);
    assert(gs + 100 == 101);
    assert(gs + 1234977 == 401);
    assert(gs + gs == 2);
    std::cout << "Tests for + : " << GREEN << "PASSED" << WHITE << std::endl;

    assert(gs - 1234577 == 1);
    assert(gs - 0 == 1);
    assert(gs - 1 == 0);
    assert(gs - 1234578 == 0);
    assert(gs - (-1) == 2);
    assert(gs - 1234576 == 2);
    assert(gs - 2 == 1234576);
    std::cout << "Tests for - : " << GREEN << "PASSED" << WHITE << std::endl;

    assert(gs * 1234577 == 0);
    assert(gs * 0 == 0);
    assert(gs * (-1) == 1234576);
    assert(gs * 10 == 10);
    assert(gs * (-1234567) == 10);
    gs = -580978;
    assert(gs * 1 == 653599);
    assert(gs * 2 == 72621);
    assert(gs * 1234576 == 580978);
    std::cout << "Tests for * : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    try {
        gs = gs / 0;
    }
    catch (const std::domain_error& e) {
        std::cout << "Test for exception for dividing by zero for / " << GREEN << "PASSED." << WHITE << std::endl;
        assert(gs.getValue() == 1);
    }
    assert(gs / 1 == 1);
    assert(gs / (-1234576) == 1);
    assert(gs / 1234576 == 1234576);
    assert(gs / 653599 == 123456);
    assert(gs / (-580978) == 123456);
    gs = -4;
    assert(gs / 1234578 == 1234573);
    assert(gs / 653599 == 740753); // 1234573 / 653599 = 1234573 * 123456
    std::cout << "Tests for / : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 0;
    assert(gs.getValue() == 0);
    gs = 1234577;
    assert(gs.getValue() == 0);
    gs = -1234577;
    assert(gs.getValue() == 0);
    gs = 1234578;
    assert(gs.getValue() == 1);
    gs = -1;
    assert(gs.getValue() == 1234576);
    gs = -580978;
    assert(gs.getValue() == 653599);
    std::cout << "Tests for = : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 0;
    gs += 1;
    assert(gs.getValue() == 1);
    gs += 1234576;
    assert(gs.getValue() == 0);
    gs += 1234577;
    assert(gs.getValue() == 0);
    gs += -580978;
    assert(gs.getValue() == 653599);
    gs += 12345770;
    assert(gs.getValue() == 653599);
    std::cout << "Tests for += : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 0;
    gs -= 1;
    assert(gs.getValue() == 1234576);
    gs -= -1;
    assert(gs.getValue() == 0);
    gs -= 1234577;
    assert(gs.getValue() == 0);
    gs -= 100;
    assert(gs.getValue() == 1234477);
    std::cout << "Tests for -= : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    gs *= 1;
    assert(gs.getValue() == 1);
    gs *= -1234576;
    assert(gs.getValue() == 1);
    gs *= 1234577;
    assert(gs.getValue() == 0);
    gs *= 653599;
    assert(gs.getValue() == 0);
    gs = 653599;
    gs *= 123456;
    assert(gs.getValue() == 1);
    gs = 1234576;
    gs *= 1234576;
    assert(gs.getValue() == 1);
    gs = 1234576;
    gs *= 2469153; // 2469153 = 1234576 + 1234577
    assert(gs.getValue() == 1);
    std::cout << "Tests for *= : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    try {
        gs /= 0;
    }
    catch (const std::domain_error& e) {
        std::cout << "Test 1 for exception for dividing by zero for /= " << GREEN << "PASSED." << WHITE << std::endl;
        assert(gs.getValue() == 1);
    }
    try {
        gs /= 1234577;
    }
    catch (const std::domain_error& e) {
        std::cout << "Test 2 for exception for dividing by zero for /= " << GREEN << "PASSED." << WHITE << std::endl;
        assert(gs.getValue() == 1);
    }
    gs /= -1234576;
    assert(gs.getValue() == 1);
    gs /= 1234576;
    assert(gs.getValue() == 1234576);
    gs = 1;
    gs /= 653599;
    assert(gs.getValue() == 123456);
    gs = 1;
    gs /= -580978;
    assert(gs.getValue() == 123456);
    gs = -4;
    gs /= 1234578;
    assert(gs.getValue() == 1234573);
    std::cout << "Tests for /= : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 0;
    assert(gs == 1234577);
    assert(gs == -1234577);
    assert(gs == 1 == false);
    gs = 1234577;
    assert(gs == 0);
    gs = 1;
    assert(gs == 1);
    assert(gs == 1234578);
    assert(gs == -1234576);
    gs = -1;
    assert(gs == 1234576);
    assert(gs == -1234578);
    std::cout << "Tests for == : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1234577;
    assert(gs != 1234577 == false);
    assert(gs != 1);
    assert(gs != 1234578);
    assert(gs != -5);
    gs = -1;
    assert(gs != 1234576 == false);
    assert(gs != 1);
    assert(gs != 1234575);
    assert(gs != -5);
    std::cout << "Tests for != : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    assert(gs > 0);
    assert(gs > 1234577);
    assert(gs > 1 == false);
    gs = -1;
    assert(gs > 0);
    assert(gs > 1);
    assert(gs > -10);
    assert(gs > 1234576 == false);
    std::cout << "Tests for > : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    assert(gs >= 1);
    assert(gs >= 1234577);
    assert(gs >= -1234567 == false);
    gs = -1;
    assert(gs >= 1234576);
    assert(gs >= 0);
    assert(gs >= 1);
    assert(gs >= -10);
    std::cout << "Tests for >= : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    assert(gs < -1234575);
    assert(gs < 1 == false);
    assert(gs < 1234577 == false);
    gs = -1;
    assert(gs < -1234575 == false);
    assert(gs < 1234576 == false);
    assert(gs < -1 == false);
    std::cout << "Tests for < : " << GREEN << "PASSED" << WHITE << std::endl;

    gs = 1;
    assert(gs <= -1234575);
    assert(gs <= 1);
    assert(gs <= 1234577 == false);
    gs = -1;
    assert(gs <= -1234575 == false);
    assert(gs <= 1234576);
    assert(gs <= -1);
    std::cout << "Tests for <= : " << GREEN << "PASSED" << WHITE << std::endl;

    return 0;
}