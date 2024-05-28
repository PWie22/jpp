
#from typing import TypeVar
import random
import copy
from diffieHellman import DHSetup, T

class User:

    secretPower: int

    def __init__(self, dhs: DHSetup, characteristics: int):
        self.secretPower = random.randint(1, characteristics - 1)
        self.dhs = dhs
        self.privateKey: T = None

    def getPublicKey(self) -> T:
        b = copy.copy(self.secretPower)
        return self.dhs.power(self.dhs.getGenerator(), b)

    def setKey(self, a: T):
        b = copy.copy(self.secretPower)
        self.privateKey = self.dhs.power(a, b)

    def encrypt(self, m: T) -> T:
        if self.privateKey == None:
            raise Exception("You have not set the private key yet.")
        return m * self.privateKey

    def decrypt(self, c: T) -> T:
        if self.privateKey == None:
            raise Exception("You have not set the private key yet.")
        return c / self.privateKey