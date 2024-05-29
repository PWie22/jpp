
class GaloisField:

    primeNumber = None

    @staticmethod
    def setPrimeNumber(val):
        GaloisField.primeNumber = val

    @staticmethod
    def getPrimeNumber():
        return GaloisField.primeNumber

    def __init__(self, value):
        self.value = self.__number(value)

    def __number(self, b):
        if self.primeNumber == None:
            raise Exception("You have not assigned value to variable 'primeNumber'.")
        if isinstance(b, GaloisField):
            bb = b.value
            if bb < 0:
                while bb < 0:
                    bb += self.primeNumber
                return bb
            return bb % self.primeNumber
        elif isinstance(b, int):
            if b < 0:
                while b < 0:
                    b += self.primeNumber
                return b
            return b % self.primeNumber

    def __add__(self, b):
        return GaloisField(self.value + self.__number(b))

    def __sub__(self, b):
        return GaloisField(self.value - self.__number(b))

    def __mul__(self, b):
        return GaloisField(self.value * self.__number(b))

    def __extendedEuclideanAlgorithm(self, a, b):
        aa = int(a)
        bb = int(b)
        x0 = 1
        x1 = 0
        y0 = 0
        y1 = 1
        while bb != 0:
            c = aa//bb
            temp = bb
            bb = aa%bb
            aa = temp
            nextX = x0 - c*x1
            nextY = y0 - c*y1
            x0 = x1
            y0 = y1
            x1 = nextX
            y1 = nextY
        #return (aa, x0, y0) - y0 niepotrzebne w dalszych obliczeniach
        return aa, x0, y0

    def __invert(self, b):
        '''
        temp = self.value
        self.value = self.__number(b)
        for i in range(self.primeNumber):
            if self.__mul__(i).value == 1:
                self.value = temp
                return i
        self.value = temp
        # w ciele GF1234577 wszystkie elementy są odwracalne, ale, jeżeli zamiast liczby pierwszej zostanie podana liczba złożona, to pojawią się elementy nieodwracalne
        # wtedy zostanie zwrócone -1
        return -1
        '''
        gcd, x0, _ = self.__extendedEuclideanAlgorithm(b, self.primeNumber)
        '''if extEuc[0] == 1:
            return (extEuc[1]%self.primeNumber + self.primeNumber) % self.primeNumber'''
        if gcd == 1:
            return (x0 % self.primeNumber + self.primeNumber) % self.primeNumber # zwracany jest int, ale przekonwertowany tak, żeby miał wartość z ciała
        return -1

    def __truediv__(self, b):
        if b == 0:
            raise ValueError("You can't divide by zero.\n")
        inverted = self.__invert(b)
        # w ciele nie ma elementów nieodwracalnych, ale gdyby nie podano liczby, która jest pierwsza
        # to takie by się pojawiły
        if inverted == -1:
            raise ValueError("Cannot invert {}\n".format(b))
        return self.__mul__(inverted)

    def substitute(self, b):
        self.value = self.__number(b)

    def __iadd__(self, b):
        self.value = self.__add__(b)
        return GaloisField(self.value)

    def __isub__(self, b):
        self.value = self.__sub__(b)
        return GaloisField(self.value)

    def __imul__(self, b):
        self.value = self.__mul__(b)
        return GaloisField(self.value)

    def __itruediv__(self, b):
        self.value = self.__truediv__(b)
        return GaloisField(self.value)

    def __eq__(self, b):
        return self.value == self.__number(b)

    def __ne__(self, b):
        return self.value != self.__number(b)

    def __gt__(self, b):
        return self.value > self.__number(b)

    def __lt__(self, b):
        return self.value < self.__number(b)

    def __ge__(self, b):
        return self.value >= self.__number(b)

    def __le__(self, b):
        return self.value <= self.__number(b)

    '''def print(self):
        print(self.value)'''

    def __int__(self):
        '''if isinstance(a, int):
            return a
        if isinstance(a, GaloisField):
            return a.value'''
        return self.value

    def __str__(self):
        return f'{self.value}'