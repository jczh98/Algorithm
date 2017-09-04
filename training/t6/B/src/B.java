import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by cyuun on 2017/7/13.
 */
public class B {

    public static void main(String[] args) {
        BigInteger x[] = new BigInteger[4];
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        for(int i=1;i<=3;i++) {
            x[i] = cin.nextBigInteger();
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++) {
                for(int k=1;k<=3;k++) {
                    if(x[i].add(x[j]).equals(x[k])) {
                        System.out.println("YES\n");
                        return ;
                    }
                }
            }
        }
        System.out.println("NO\n");
        return ;
    }
}
