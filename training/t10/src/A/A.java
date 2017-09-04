package A;

import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by cyuun on 2017/7/18.
 */
public class A {

    public static void main(String[] args) {
        BigInteger m,n;
        int t,t1,t2;
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        t1 = cin.nextInt();
        t2 = cin.nextInt();
        m = BigInteger.valueOf(t1);
        n = BigInteger.valueOf(t2);
        t = cin.nextInt();
        if(t == 1) {
            BigInteger zero = BigInteger.valueOf(0);
            BigInteger one = BigInteger.valueOf(1);
            BigInteger tt = n, ttt = n.subtract(one);
            while(ttt.compareTo(zero) > 0) {
                tt = tt.multiply(ttt);
                if(tt.compareTo(m) > 0) {
                    System.out.println("TLE\n");
                    return;
                }
                ttt = ttt.subtract(one);
            }
            //System.out.println(tt);
            System.out.println("AC\n");
        }else if(t == 2) {
            BigInteger pow = BigInteger.valueOf(1);
            BigInteger base = BigInteger.valueOf(2);
            BigInteger two = BigInteger.valueOf(2);
            BigInteger res = n;
            BigInteger zero = BigInteger.valueOf(0);
            while(res.compareTo(zero) > 0) {
                if(res.mod(two).compareTo(zero) > 0) pow = pow.multiply(base);
                base = base.multiply(base);
                if(pow.compareTo(m) > 0) {
                    System.out.println("TLE\n");
                    return;
                }
                res = res.divide(two);
            }
            //System.out.println(pow);
            System.out.println("AC\n");
        }else if(t == 3) {
            if(n.multiply(n).multiply(n).multiply(n).compareTo(m) <= 0) {
                System.out.println("AC\n");
            }else {
                System.out.println("TLE\n");
            }
        }else if(t == 4) {
            if(n.multiply(n).multiply(n).compareTo(m) <= 0) {
                System.out.println("AC\n");
            }else {
                System.out.println("TLE\n");
            }
        }else if(t == 5) {
            //System.out.println(m);
            if(n.multiply(n).compareTo(m) <= 0) {
                System.out.println("AC\n");
            }else {
                System.out.println("TLE\n");
            }
        }else if(t == 6) {
            double lg = Math.log(t2)/Math.log(2);
            double ans = t2*lg;
            //System.out.println((int)(ans+0.5));
            if((int)(ans+0.5) <= t1) {
                System.out.println("AC\n");
            }else {
                System.out.println("TLE\n");
            }
        }else if(t == 7) {
            if(n.compareTo(m) <= 0) {
                System.out.println("AC\n");
            }else {
                System.out.println("TLE\n");
            }
        }
    }
}
