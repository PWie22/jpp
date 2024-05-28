
from galoisField import *
import pytest

def test_add():
    assert a + 0 == 1
    assert a + 1234577 == 1
    assert a + (-1) == 0
    assert a + 1234576 == 0
    assert a + 1234777 == 201
    assert a + 100 + 100 == 201
    assert a + (-101) == 1234477
    print("Tests for + : \033[32mPASSED\033[0m")

def test_subtract():
    assert a - 0 == 1
    assert a - 1234577 == 1
    assert a - 1 == 1234577
    assert a - 2 == 1234576
    assert a - (-1) == 2
    assert a - 1234576 == 2
    assert a - 1234578 == 0
    print("Tests for - : \033[32mPASSED\033[0m")

def test_multiply():
    global a
    assert a * 1234577 == 0
    assert a * 0 == 0
    assert a * (-1) == 1234576
    assert a * 10 == 10
    assert a * (-1234567) == 10
    a.substitute(-580978)
    assert a * 1 == 653599
    assert a * 2 == 72621
    assert a * 1234576 == 580978
    print("Tests for * : \033[32mPASSED\033[0m")

def test_divide():
    global a
    a.substitute(1)
    with pytest.raises(ValueError):
        a = a / 0
    with pytest.raises(ValueError):
        a = a / 1234577
    assert a == 1
    # poniższe dwa przykłady zaczerpnięte z listy 3 na jftt autorstwa dra gębali
    a.substitute(269164)
    assert a / 123456 == 567890
    assert a / 1 == 269164
    a.substitute(1)
    assert a / (-580978) == 123456
    assert a / 653599 == 123456
    assert a / (-1234576) == 1
    a.substitute(-4)
    assert a / 1234578 == 1234573
    assert a / 653599 == 740753
    print("Tests for / : \033[32mPASSED\033[0m")

def test_substitute():
    global a
    a.substitute(0)
    assert a == 0
    a.substitute(1234577)
    assert a == 0
    a.substitute(-1234577)
    assert a == 0
    a.substitute(1)
    assert a == 1
    a.substitute(-1)
    assert a == 1234576
    a.substitute(-580978)
    assert a == 653599
    print("Tests for substitute() : \033[32mPASSED\033[0m")

def test_addAndSubst():
    global a
    a.substitute(0)
    a += 1
    assert a == 1
    a += 1234576
    assert a == 0
    a += 1234577
    assert a == 0
    a += -580978
    assert a == 653599
    a += 12345770
    assert a == 653599
    print("Tests for += : \033[32mPASSED\033[0m")

def test_subtractAndSubst():
    global a
    a.substitute(0)
    a -= 1
    assert a == 1234576
    a -= -1
    assert a == 0
    a -= 1234577
    assert a == 0
    a -= 100
    assert a == 1234477
    print("Tests for -= : \033[32mPASSED\033[0m")

def test_multiplyAndSubst():
    global a
    a.substitute(1)
    a *= 1
    assert a == 1
    a *= -1234576
    assert a == 1
    a *= 1234577
    assert a == 0
    a *= 653599
    assert a == 0
    a.substitute(653599)
    a *= 123456
    assert a == 1
    a.substitute(1234576)
    a *= 1234576
    assert a == 1
    a.substitute(1234576)
    a *= 2469153 # 2469153 = 1234576 + 1234577
    assert a == 1
    print("Tests for *= : \033[32mPASSED\033[0m")

def test_divideAndSubst():
    global a
    a.substitute(1)
    with pytest.raises(ValueError): # sprawdzenie, czy funkcja wyrzuca błąd, kiedy chcemy podzielić przez zero
        a /= 0
    with pytest.raises(ValueError): # sprawdzenie, czy funkcja wyrzuca błąd, kiedy chcemy podzielić przez zero
        a /= 1234577
    assert a == 1
    a /= -580978
    assert a == 123456
    a.substitute(269164)
    a /= 123456
    assert a == 567890
    a.substitute(1)
    a /= -1234576
    assert a == 1
    print("Tests for /= : \033[32mPASSED\033[0m")

def test_checkIfEqual():
    global a
    a.substitute(0)
    assert a == 1234577
    assert a == -1234577
    assert not a == 1
    a.substitute(1234577)
    assert a == 0
    a.substitute(1)
    assert a == 1
    assert a == 1234578
    assert a == -1234576
    a.substitute(-1)
    assert a == 1234576
    assert a == -1234578
    print("Tests for == : \033[32mPASSED\033[0m")

def test_checkIfNotEqual():
    global a
    a.substitute(1234577)
    assert not a != 1234577
    assert not a != 0
    assert a != 1
    assert a != 1234578
    assert a != -5
    a.substitute(-1)
    assert not a != 1234576
    assert a != 1
    assert a != 1234575
    assert a != -5
    print("Tests for != : \033[32mPASSED\033[0m")

def test_checkIfThisGreater():
    global a
    a.substitute(1)
    assert a > 0
    assert a > 1234577
    assert not a > 1
    a.substitute(-1)
    assert a > 0
    assert a > 1
    assert a > -10
    assert not a > 1234576
    print("Tests for > : \033[32mPASSED\033[0m")

def test_checkIfThisGreaterEqual():
    global a
    a.substitute(1)
    assert a >= 1
    assert a >= 1234577
    assert not a >= -1234567
    a.substitute(-1)
    assert a >= 1234576
    assert a >= 0
    assert a >= 1
    assert a >= -10
    print("Tests for >= : \033[32mPASSED\033[0m")

def test_checkIfThisSmaller():
    a.substitute(1)
    assert a < -1234575
    assert not a < 1
    assert not a < 1234577
    a.substitute(-1)
    assert not a < -1234575
    assert not a < 1234576
    assert not a < -1
    print("Tests for < : \033[32mPASSED\033[0m")

def test_checkIfThisSmallerEqual():
    a.substitute(1)
    assert a <= -1234575
    assert a <= 1
    assert not a <= 1234577
    a.substitute(-1)
    assert not a <= -1234575
    assert a <= 1234576
    assert a <= -1
    print("Tests for <= : \033[32mPASSED\033[0m")

# próba utworzenia obiektu bez przypisania wartości do zmiennej primeNumber w klasie GaussField
# wyrzuci wyjątek
with pytest.raises(Exception):
    a = GaloisField(3)
print("Test for detecting not assigned variable 'primeNumber' : \033[32mPASSED\033[0m")

primeNumber = 1234577
GaloisField.setPrimeNumber(primeNumber)

assert GaloisField.getPrimeNumber() == primeNumber
print("Test for getPrimeNumber() : \033[32mPASSED\033[0m")

# początkowa wartość do testów
a = GaloisField(1)

test_add()
test_subtract()
test_multiply()
test_divide()
test_substitute()
test_addAndSubst()
test_subtractAndSubst()
test_multiplyAndSubst()
test_divideAndSubst()
test_checkIfEqual()
test_checkIfNotEqual()
test_checkIfThisGreater()
test_checkIfThisGreaterEqual()
test_checkIfThisSmaller()
test_checkIfThisSmallerEqual()