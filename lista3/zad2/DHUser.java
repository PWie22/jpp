//package zad2;

import java.util.Random;

public class DHUser<T extends Operations<T>> {
    private T privateKey;
    private boolean isKeySet = false;
    private long secretPower;
    private DHSetup<T> dhs;

    public DHUser(DHSetup<T> dhs, int characteristics) {
        this.dhs = dhs;
        Random rand = new Random();
        secretPower = rand.nextInt(characteristics - 1);
    }

    public T getPublicKey() {
        return dhs.power(dhs.getGenerator(), secretPower);
    }

    public void setKey(T a) {
        privateKey = dhs.power(a, secretPower);
        isKeySet = true;
    }

    public T encrypt(T m) throws Exception {
        if (!isKeySet) {
            throw new Exception("You have not set the private key yet.");
        }
        return m.multiply(privateKey.getValue());
    }

    public T decrypt(T c) throws Exception {
        if (!isKeySet) {
            throw new Exception("You have not set the private key yet.");
        }
        return c.divide(privateKey.getValue());
    }
}