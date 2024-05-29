
public class TestDH {
    public static void main(String[] args) {
        GaloisField.setPrimeNumber(1234567891);
        //DHSetup<GaloisField> dhs = new DHSetup<GaloisField>(GaloisField.getPrimeNumber(), new GaloisField(0));
        DHSetup<GaloisField> dhs = new DHSetup<GaloisField>(GaloisField.getPrimeNumber(), new GaloisField(0));
        DHUser<GaloisField> user1 = new DHUser<GaloisField>(dhs, GaloisField.getPrimeNumber());
        DHUser<GaloisField> user2 = new DHUser<GaloisField>(dhs, GaloisField.getPrimeNumber());
        try {
            user1.setKey(user2.getPublicKey());
            GaloisField e = user1.encrypt(new GaloisField(111436077));
            user2.setKey(user1.getPublicKey());
            System.out.print("e: ");
            user2.decrypt(e).println();
            e = user2.encrypt(new GaloisField(841536281));
            System.out.print("e: ");
            user1.decrypt(e).println();
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }
}