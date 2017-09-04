import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by cyuun on 2017/7/25.
 */
public class H {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int t = cin.nextInt();
        for(int k = 1;k<=t; k++)
        {
            BigInteger n,m,rator=BigInteger.ZERO,nator=BigInteger.ZERO;
            n = cin.nextBigInteger();
            m = cin.nextBigInteger();

            for(int i=1;;i++)
            {
                BigInteger compare = BigInteger.valueOf(2*(i-1));
                if(compare.compareTo(n.add(m)) >= 0)break;
                BigInteger up=BigInteger.ONE,down=BigInteger.ONE;
                for(int j=0;j<2*(i-1);j++)
                {
                    up=up.multiply(m.subtract(BigInteger.valueOf(j)));
                    down=down.multiply(n.add(m).subtract(BigInteger.valueOf(j)));
                }
                up=up.multiply(n);down=down.multiply(n.add(m).subtract(compare));
                BigInteger g=up.gcd(down);
                up=up.divide(g);down=down.divide(g);
                //Simplify(up,down);
                if(nator==BigInteger.ZERO&&rator==BigInteger.ZERO) {
                    rator=up;
                    nator=down;
                }
                else {
                    rator=rator.multiply(down).add(nator.multiply(up));
                    nator=nator.multiply(down);
                }
                g=rator.gcd(nator);
                rator=rator.divide(g);nator=nator.divide(g);
                //Simplify(rator,nator);
            }
            System.out.print(rator+"/"+nator+"\n");
        }
    }
}
