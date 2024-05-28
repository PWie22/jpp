//package zad2;

import java.util.ArrayList;
import java.util.Random;

public class DHSetup<T extends Operations<T>> {
    private T generator;
    private T instanceOfT;
    
    private boolean checkIfCanBeGenerator(int characteristics, T candidate, ArrayList<Integer> primes) {
        for (int p : primes) {
            long exp = (characteristics - 1) / p;
            T res = power(candidate, exp);
            if (res.checkIfEqual(1)) {
                return false;
            }
        }
        return true;
    }

    private ArrayList<Integer> factorIntoPrimes(int a) {
        ArrayList<Integer> primes = new ArrayList<>();
        int i = 2;
        while (a > 1) {
            if (a % i == 0) {
                primes.add(i);
                while (a % i == 0) {
                    a /= i;
                }
            }
            i += 1;
        }
        return primes;
    }

    private T generateGenerator(int characteristics) {
        ArrayList<Integer> primes = factorIntoPrimes(characteristics - 1);
        Random rand = new Random();
        while (true) {
            instanceOfT.subst(rand.nextInt(characteristics - 1) + 1);
            if (checkIfCanBeGenerator(characteristics, instanceOfT.copy(), primes)) {
                break;
            }
        }
        return instanceOfT.copy();
    }

    public DHSetup(int characteristics, T t) {
        instanceOfT = t;
        generator = generateGenerator(characteristics);
    }

    public T getGenerator() {
        return generator.copy();
    }

    public T power(T a, long b) {
        instanceOfT.subst(1);
        while (b > 0) {
            if (b % 2 == 1) {
                instanceOfT.multiplyAndSubst(a.getValue());
            }
            a.multiplyAndSubst(a.getValue());
            b /= 2;
        }
        return instanceOfT.copy();
    }
}
