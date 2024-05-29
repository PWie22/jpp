
public class GaussField {

    private int value;
    private static int primeNumber;

    private int number(int a) {
        if (a < 0) {
            while (a < 0) {
                a += primeNumber;
            }
            return a;
        }
        return a % primeNumber;
    }

    private int[] extendedEuclideanAlgorithm(int a, int b) {
        int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
        int c, temp, nextX, nextY;
        while(b != 0) {
            c = a/b;
		    temp = b;
		    b = a % b;
		    a = temp;
		    nextX = x0 - c*x1;
		    nextY = y0 - c*y1;
		    x0 = x1;
		    y0 = y1;
		    x1 = nextX;
		    y1 = nextY;
        }
        int[] res = new int[3];
        res[0] = a; res[1] = x0; res[2] = y0;
        return res;
    }

    private int invert(int a) {
        /*int temp = this.value;
        this.value = a;
        for(int i = 1; i < primeNumber; i++) {
            if (multiply(i).checkIfEqual(1)) {
                this.value = temp;
                return i;
            }
        }
        this.value = temp;
        return -1;*/
        int aa = number(a);
        int[] extEuc = extendedEuclideanAlgorithm(aa, primeNumber);
        if (extEuc[0] == 1) {
            return (extEuc[1] % primeNumber + primeNumber) % primeNumber;
        }
        return -1;
    }

    public GaussField(int value) {
        this.value = number(value);
    }

    static public void setPrimeNumber(int prime) {
        primeNumber = prime;
    }

    static int getPrimeNumber() {
        return primeNumber;
    }

    public int getValue() {
        return this.value;
    }

    public GaussField add(int b) {
        return new GaussField(this.value + b);
    }

    public GaussField subtract(int b) {
        return new GaussField(this.value - b);
    }

    public GaussField multiply(int b) {
        long bb = number(b);
        long mult = this.value*bb % primeNumber;
        return new GaussField((int) mult);
    }

    public GaussField divide(int b) throws ArithmeticException {
        if (number(b) == 0) {
            throw new ArithmeticException("You cannot divide by zero.");
        }
        int inverted = invert(b);
        if (inverted == -1) {
            throw new ArithmeticException("Number " + b + " cannot be inverted.");
        }
        return multiply(inverted);
    }

    public void subst(int b) {
        this.value = number(b);
    }

    public void addAndSubst(int b) {
        this.value = add(b).value;
    }

    public void subtractAndSubst(int b) {
        this.value = subtract(b).value;
    }

    public void multiplyAndSubst(int b) {
        this.value = multiply(b).value;
    }

    public void divideAndSubst(int b) {
        this.value = divide(b).value;
    }

    public boolean checkIfEqual(int b) {
        if (this.value == number(b)) {
            return true;
        }
        return false;
    }

    public boolean checkIfNotEqual(int b) {
        if (this.value != number(b)) {
            return true;
        }
        return false;
    }

    public boolean checkIfThisGreater(int b) {
        if (this.value > number(b)) {
            return true;
        }
        return false;
    }

    public boolean checkIfThisSmaller(int b) {
        if (this.value < number(b)) {
            return true;
        }
        return false;
    }

    public boolean checkIfThisGreaterEqual(int b) {
        if (this.value >= number(b)) {
            return true;
        }
        return false;
    }

    public boolean checkIfThisSmallerEqual(int b) {
        if (this.value <= number(b)) {
            return true;
        }
        return false;
    }

    public void println() {
        System.out.println(this.value);
    }

}