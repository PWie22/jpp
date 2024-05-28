
from typing import TypeVar
import random
import copy

T = TypeVar('T')

class DHSetup:
    def __init__(self, characteristics: int, t: T):
        self.generator = self.__generateGenerator(characteristics, t)
    
    def __checkIfCanBeGenerator(self, characteristics: int, candidate: T, primes):
        for p in primes:
            exp = (characteristics - 1) // p            
            c = copy.copy(candidate)
            res = self.power(c, exp)
            if res == 1:
                return False
        return True

    def __factorIntoPrimes(self, a: int):
        primes = set()
        i = 2
        while a > 1:
            if a % i == 0:
                primes.add(i)
                while a % i == 0:
                    a //= i
            i += 1
        return primes

    # parametr t to jest 0, ale odpowiedniego typu, np. GaloisField(0), 0
    def __generateGenerator(self, characteristics: int, t: T) -> T:
        primes = self.__factorIntoPrimes(characteristics - 1)
        while True:
            randNumb = random.randint(1, characteristics-1)
            t += randNumb
            copyT = copy.copy(t)
            if self.__checkIfCanBeGenerator(characteristics, copyT, primes):
                break
            t -= randNumb
        return t

    def getGenerator(self) -> T:
        g = copy.copy(self.generator)
        return g

    def power(self, a: T, b: int) -> T:
        res: T = copy.copy(a)
        res -= a
        res += 1 # sztucznie wygenerowana jedynka typu T
        while b > 0:
            if b % 2 == 1:
                res *= a
            a *= a
            b //= 2
        return res