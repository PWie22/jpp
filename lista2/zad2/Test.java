
class Test {
    public static void main(String []args) {
        GaloisField.setPrimeNumber(1234577);
        GaloisField gs = new GaloisField(1);

        GaloisField gs2 = gs.add(1234577);
        System.out.print("1 + 1234577 = "); gs2.println();
        gs2 = gs.add(0);
        System.out.print("1 + 0 = "); gs2.println();
        gs2 = gs.add(-1);
        System.out.print("1 + (-1) = "); gs2.println();
        gs2 = gs.add(1234576);
        System.out.print("1 + 1234576 = "); gs2.println();
        gs2 = gs.add(100);
        System.out.print("1 + 100 = "); gs2.println();
        gs2 = gs.add(1234977);
        System.out.print("1 + 1234977 = "); gs2.println();

        System.out.println("\n------------------------------\n");

        gs2 = gs.subtract(1234577);
        System.out.print("1 - 1234577 = "); gs2.println();
        gs2 = gs.subtract(0);
        System.out.print("1 - 0 = "); gs2.println();
        gs2 = gs.subtract(1);
        System.out.print("1 - 1 = "); gs2.println();
        gs2 = gs.subtract(1234578);
        System.out.print("1 - 1234578 = "); gs2.println();
        gs2 = gs.subtract(-1);
        System.out.print("1 - (-1) = "); gs2.println();
        gs2 = gs.subtract(1234576);
        System.out.print("1 - 1234576 = "); gs2.println();
        gs2 = gs.subtract(2);
        System.out.print("1 - 2 = "); gs2.println();

        System.out.println("\n------------------------------\n");

        gs2 = gs.multiply(1234577);
        System.out.print("1 * 1234577 = "); gs2.println();
        gs2 = gs.multiply(0);
        System.out.print("1 * 0 = "); gs2.println();
        gs2 = gs.multiply(-1);
        System.out.print("1 * (-1) = "); gs2.println();
        gs2 = gs.multiply(10);
        System.out.print("1 * 10 = "); gs2.println();
        gs2 = gs.multiply(-1234567);
        System.out.print("1 * (-1234567) = "); gs2.println();
        gs.subst(-580978);
        gs2 = gs.multiply(1);
        System.out.print("-580978 * 1 = "); gs2.println();
        gs2 = gs.multiply(2);
        System.out.print("-580978 * 2 = "); gs2.println();
        gs2 = gs.multiply(1234576);
        System.out.print("-580978 * 1234576 = "); gs2.println();
        gs.subst(1234576);
        gs2 = gs.multiply(1234576);
        System.out.print("1234576 * 1234576 = "); gs2.println();

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        try {
            gs2 = gs.divide(0);
        } catch (ArithmeticException ae) {
            System.out.println("Exception for 1 / 0 caught: " + ae.getMessage());
        }
        try {
            gs2 = gs.divide(1234577);
        } catch (ArithmeticException ae) {
            System.out.println("Exception for 1 / 1234577 caught: " + ae.getMessage());
        }
        gs2 = gs.divide(1);
        System.out.print("1 / 1 = "); gs2.println();
        gs2 = gs.divide(-1234576);
        System.out.print("1 / (-1234576) = "); gs2.println();
        gs2 = gs.divide(1234576);
        System.out.print("1 / 1234576 = "); gs2.println();
        gs2 = gs.divide(653599);
        System.out.print("1 / 653599 = "); gs2.println();
        gs2 = gs.divide(-580978);
        System.out.print("1 / (-580978) = "); gs2.println();
        gs.subst(-4);
        gs2 = gs.divide(1234578);
        System.out.print("1 / 1234578 = "); gs2.println();
        gs2 = gs.divide(653599);
        System.out.print("1 / 653599 = "); gs2.println();

        System.out.println("\n------------------------------\n");

        gs.subst(0);
        System.out.print("Value after subst(0): "); gs.println();
        gs.subst(1234577);
        System.out.print("Value after subst(1234577): "); gs.println();
        gs.subst(-1234577);
        System.out.print("Value after subst(-1234577): "); gs.println();
        gs.subst(1234578);
        System.out.print("Value after subst(1234578): "); gs.println();
        gs.subst(-1);
        System.out.print("Value after subst(-1): "); gs.println();
        gs.subst(-580978);
        System.out.print("Value after subst(-580978): "); gs.println();

        System.out.println("\n------------------------------\n");

        gs.subst(0);
        gs.addAndSubst(1);
        System.out.print("gs = 0; gs += 1; gs = "); gs.println();
        gs.addAndSubst(1234576);
        System.out.print("gs = 1; gs += 1234576; gs = "); gs.println();
        gs.addAndSubst(1234577);
        System.out.print("gs = 0; gs += 1234577; gs = "); gs.println();
        gs.addAndSubst(-580978);
        System.out.print("gs = 0; gs += -580978; gs = "); gs.println();
        gs.addAndSubst(12345770);
        System.out.print("gs = 653599; gs += 12345770; gs = "); gs.println();

        System.out.println("\n------------------------------\n");

        gs.subst(0);
        gs.subtractAndSubst(1);
        System.out.print("gs = 0; gs -= 1; gs = "); gs.println();
        gs.subtractAndSubst(-1);
        System.out.print("gs = 1234576; gs -= -1; gs = "); gs.println();
        gs.subtractAndSubst(1234577);
        System.out.print("gs = 0; gs -= 1234577; gs = "); gs.println();
        gs.subtractAndSubst(100);
        System.out.print("gs = 0; gs -= 100; gs = "); gs.println();

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        gs.multiplyAndSubst(1);
        System.out.print("gs = 1; gs *= 1; gs = "); gs.println();
        gs.multiplyAndSubst(-1234576);
        System.out.print("gs = 1; gs *= -1234576; gs = "); gs.println();
        gs.multiplyAndSubst(1234577);
        System.out.print("gs = 1; gs *= 1234577; gs = "); gs.println();
        gs.multiplyAndSubst(653599);
        System.out.print("gs = 0; gs *= 653599; gs = "); gs.println();
        gs.subst(653599);
        gs.multiplyAndSubst(123456);
        System.out.print("gs = 0; gs *= 123456; gs = "); gs.println();
        gs.subst(1234576);
        gs.multiplyAndSubst(1234576);
        System.out.print("gs = 1; gs *= 1234576; gs = "); gs.println();
        gs.subst(1234576);
        gs.multiplyAndSubst(2469153);
        System.out.print("gs = 1; gs *= 2469153; gs = "); gs.println();

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        try {
            gs.divideAndSubst(0);
        } catch (ArithmeticException ae) {
            System.out.println("Exception for 1 / 0 caught: " + ae.getMessage());
        }
        try {
            gs.divideAndSubst(1234577);
        } catch (ArithmeticException ae) {
            System.out.println("Exception for 1 / 1234577 caught: " + ae.getMessage());
        }
        gs.divideAndSubst(-1234576);
        System.out.print("gs = 1; gs /= -1234576; gs = "); gs.println();
        gs.divideAndSubst(1234576);
        System.out.print("gs = 1; gs /= 1234576; gs = "); gs.println();
        gs.subst(1);
        gs.divideAndSubst(653599);
        System.out.print("gs = 1; gs /= 653599; gs = "); gs.println();
        gs.subst(1);
        gs.divideAndSubst(-580978);
        System.out.print("gs = 1; gs /= -580978; gs = "); gs.println();
        gs.subst(-4);
        gs.divideAndSubst(1234578);
        System.out.print("gs = -4; gs /= 1234578; gs = "); gs.println();

        System.out.println("\n------------------------------\n");

        gs.subst(0);
        System.out.println("0 == 1234577 : " + gs.checkIfEqual(1234577));
        System.out.println("0 == -1234577 : " + gs.checkIfEqual(-1234577));
        System.out.println("0 == 1 : " + gs.checkIfEqual(1234577));
        gs.subst(1234577);
        System.out.println("1234577 == 0 : " + gs.checkIfEqual(0));
        gs.subst(1);
        System.out.println("1 == 1 : " + gs.checkIfEqual(1));
        System.out.println("1 == 1234578 : " + gs.checkIfEqual(1234578));
        System.out.println("1 == -1234576 : " + gs.checkIfEqual(-1234576));
        gs.subst(-1);
        System.out.println("-1 == 1234576 : " + gs.checkIfEqual(1234576));
        System.out.println("-1 == -1234578 : " + gs.checkIfEqual(-1234578));

        System.out.println("\n------------------------------\n");

        gs.subst(1234577);
        System.out.println("1234577 != 1234577 : " + gs.checkIfNotEqual(1234577));
        System.out.println("1234577 != 1 : " + gs.checkIfNotEqual(1));
        System.out.println("1234577 != 1234578 : " + gs.checkIfNotEqual(1234578));
        System.out.println("1234577 != -5 : " + gs.checkIfNotEqual(-5));
        gs.subst(-1);
        System.out.println("-1 != 1234576 : " + gs.checkIfNotEqual(1234576));
        System.out.println("-1 != 1 : " + gs.checkIfNotEqual(1));
        System.out.println("-1 != 1234575 : " + gs.checkIfNotEqual(1234575));
        System.out.println("-1 != -5 : " + gs.checkIfNotEqual(-5));

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        System.out.println("1 > 0 : " + gs.checkIfThisGreater(0));
        System.out.println("1 > 1234577 : " + gs.checkIfThisGreater(1234577));
        System.out.println("1 > 1 : " + gs.checkIfThisGreater(1));
        gs.subst(-1);
        System.out.println("-1 > 0 : " + gs.checkIfThisGreater(0));
        System.out.println("-1 > 1 : " + gs.checkIfThisGreater(1));
        System.out.println("-1 > -10 : " + gs.checkIfThisGreater(-10));
        System.out.println("-1 > 1234576 : " + gs.checkIfThisGreater(1234576));

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        System.out.println("1 >= 1 : " + gs.checkIfThisGreaterEqual(1));
        System.out.println("1 >= 1234577 : " + gs.checkIfThisGreaterEqual(1234577));
        System.out.println("1 >= -1234567 : " + gs.checkIfThisGreaterEqual(-1234567));
        gs.subst(-1);
        System.out.println("-1 >= 0 : " + gs.checkIfThisGreaterEqual(0));
        System.out.println("-1 >= 1 : " + gs.checkIfThisGreaterEqual(1));
        System.out.println("-1 >= -10 : " + gs.checkIfThisGreaterEqual(-10));
        System.out.println("-1 >= 1234576 : " + gs.checkIfThisGreaterEqual(1234576));

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        System.out.println("1 < 1 : " + gs.checkIfThisSmaller(1));
        System.out.println("1 < -1234575 : " + gs.checkIfThisSmaller(-1234575));
        System.out.println("1 < 1234577 : " + gs.checkIfThisSmaller(1234577));
        gs.subst(-1);
        System.out.println("-1 < -1234575 : " + gs.checkIfThisSmaller(-1234575));
        System.out.println("-1 < 1234576 : " + gs.checkIfThisSmaller(1234576));
        System.out.println("-1 < -1 : " + gs.checkIfThisSmaller(-1));

        System.out.println("\n------------------------------\n");

        gs.subst(1);
        System.out.println("1 <= 1 : " + gs.checkIfThisSmallerEqual(1));
        System.out.println("1 <= -1234575 : " + gs.checkIfThisSmallerEqual(-1234575));
        System.out.println("1 <= 1234577 : " + gs.checkIfThisSmallerEqual(1234577));
        gs.subst(-1);
        System.out.println("-1 <= -1234575 : " + gs.checkIfThisSmallerEqual(-1234575));
        System.out.println("-1 <= 1234576 : " + gs.checkIfThisSmallerEqual(1234576));
        System.out.println("-1 <= -1 : " + gs.checkIfThisSmallerEqual(-1));

    }
}