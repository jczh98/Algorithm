import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by cyuun on 2017/7/18.
 */
public class F {
    public static void main(String[] args) {
        BigInteger h0,t1,t2;
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        h0 = cin.nextBigInteger();t1 = h0;t2 = h0;
        BigInteger a,b;
        if(h0.compareTo(BigInteger.valueOf(5)) <= 0) {
            System.out.println("5\n");
            return;
        }else if(h0.compareTo(BigInteger.valueOf(8)) <= 0) {
            System.out.println("8\n");
            return;
        }
        if(t1.subtract(BigInteger.valueOf(5)).mod(BigInteger.valueOf(8)).equals(BigInteger.ZERO)) {
            t1 = t1.subtract(BigInteger.valueOf(5)).divide(BigInteger.valueOf(8));
            a = t1.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(5));
        }else {
            t1 = t1.subtract(BigInteger.valueOf(5)).divide(BigInteger.valueOf(8)).add(BigInteger.valueOf(1));
            a = t1.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(5));
        }

        if(t2.subtract(BigInteger.valueOf(8)).mod(BigInteger.valueOf(8)).equals(BigInteger.ZERO)) {
            t2 = t2.subtract(BigInteger.valueOf(8)).divide(BigInteger.valueOf(8));
            b = t2.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(8));
        }else {
            t2 = t2.subtract(BigInteger.valueOf(8)).divide(BigInteger.valueOf(8)).add(BigInteger.valueOf(1));
            b = t2.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(8));
            //System.out.println(t2);
        }
        if(a.compareTo(b) > 0) {
            System.out.println(b);
        }else {
            System.out.println(a);
        }
    }
}
