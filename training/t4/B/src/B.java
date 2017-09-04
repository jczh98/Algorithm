import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

/**
 * Created by cyuun on 2017/7/11.
 */
public class B {

    public static void main(String[] args) {
        int n,k;
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        n=cin.nextInt();k=cin.nextInt();

        BigDecimal original = new BigDecimal(n);

        BigDecimal x1 = new BigDecimal(n);
        BigDecimal x2 = new BigDecimal(0);
        BigDecimal dif = new BigDecimal(0);

        BigDecimal precision =x1.divide(new BigDecimal(10).pow(k+10));

        while(true){
            x2 = x1.subtract(x1.pow(2).subtract(new BigDecimal(2)).divide(x1.multiply(new BigDecimal(2)),k+10, BigDecimal.ROUND_DOWN));

            //x2 = x1.divide(new BigDecimal(2), k, BigDecimal.ROUND_HALF_EVEN).add(original.divide(x1, k, BigDecimal.ROUND_HALF_EVEN));

            if(x1.compareTo(x2)==1){
                dif = x1.subtract(x2);
            }else{
                dif = x2.subtract(x1);
            }

            if(dif.compareTo(precision)==-1){
                BigDecimal ans = x2.setScale(k, BigDecimal.ROUND_DOWN);
                System.out.println(ans);
                break;
            }

            x1 = x2;
        }
    }
}
