from galoisField import *

GaloisField.setPrimeNumber(23)
v1 = GaloisField(22)
v2 = GaloisField(11)

'''res = v1 + v2
print(res.value)

v1 += 5
print(v1.value)

v1 += GaussField(1234577, 1234577)
v1 += v2
print(v1.value)

v1.substitute(1234577)

v1.print()

v1 = v1 + 1234577
if isinstance(v1, int):
    print("to jest int")
    print(v1)

v4 = v2 / 2
v4.print()
#v3 = v1 + v2
#print(v3)'''

'''v1 = v1 / v2
print(v1)

v1 *= v2
print(v1)'''

a = GaloisField(11)
# 5, 7, 10, 11, 14, 15, 16, 17, 19, 20, 21, 

v3 = a * (v1/v2)
print(v3)

#v3.substitute(2)

v4 = GaloisField(a)

i = 1
while i < 23:
    #print(v4)
    a = GaloisField(i)
    v4.substitute(a)
    j = 1
    print(v4, " ", end='')
    while j <= 1:
        v4 *= a
        print(v4, " ", end='')
        j += 1
    #v4 = v4 * v4
    print()
    i += 1