
from galoisField import *
from diffieHellman import *
from DHUser import *
import pytest

GaloisField.setPrimeNumber(1234567891)
dhs = DHSetup(GaloisField.getPrimeNumber(), GaloisField(0))

user1 = User(dhs, GaloisField.getPrimeNumber())
user2 = User(dhs, GaloisField.getPrimeNumber())

# próba zakodowania bez ustawionego klucza
with pytest.raises(Exception):
    e1 = user1.encrypt(GaloisField(1114367))
with pytest.raises(Exception):
    d2 = user2.encrypt(GaloisField(1114367))

user1.setKey(user2.getPublicKey())
e1 = user1.encrypt(GaloisField(1114367))

# próba zdekodowania bez ustawionego klucza
with pytest.raises(Exception):
    d2 = user2.decrypt(e1)

user2.setKey(user1.getPublicKey())
assert user2.decrypt(e1) == 1114367

e1 = user2.encrypt(GaloisField(0))
assert user1.decrypt(e1) == 0

print("All tests passed.")