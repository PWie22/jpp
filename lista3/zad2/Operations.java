
public interface Operations<T> {
    int getValue();
    T add(int b);
    T subtract(int b);
    T multiply(int b);
    T divide(int b);
    void subst(int b);
    void addAndSubst(int b);
    void subtractAndSubst(int b);
    void multiplyAndSubst(int b);
    void divideAndSubst(int b);
    boolean checkIfEqual(int b);
    boolean checkIfNotEqual(int b);
    boolean checkIfThisGreater(int b);
    boolean checkIfThisGreaterEqual(int b);
    boolean checkIfThisSmaller(int b);
    boolean checkIfThisSmallerEqual(int b);
    T copy();
    int convertToInt();
    void println();
}