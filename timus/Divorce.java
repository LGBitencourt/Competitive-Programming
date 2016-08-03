import java.util.Scanner;
import java.math.BigInteger;

public class Divorce {
    public static void main (String[] args) {
        Scanner sc = new Scanner (System.in);
        BigInteger n = sc.nextBigInteger();
        System.out.println(n.mod(new BigInteger("7")));
    }
}
