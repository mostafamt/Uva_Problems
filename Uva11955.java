import java.util.*;
import java.io.*;
import java.math.BigInteger ;
import static java.lang.Math.* ;

public class Uva11955
{
    static BigInteger [][] memo = new BigInteger[51][51];

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int tc = Integer.parseInt(br.readLine());
        for(int t = 1 ; t <= tc ; t++) {
            sb.append("Case ").append(t).append(": ");
            String [] s = br.readLine().split("\\(|\\+|\\)|\\^");
            String var1 = s[1];
            String var2 = s[2];
            int k = Integer.parseInt(s[4]);
            for(int i = 0 ; i <= k ; i++){
                // C(k,i)
                if( memo[k][i] == null ){
                    memo[k][min(i,k-i)] = memo[k][max(i,k-i)] = C(k,i);
                }
                if( memo[k][i].compareTo(BigInteger.ONE) > 0 ){
                    sb.append(memo[k][i].toString()).append("*");
                }
                if( k-i > 0 ){
                    sb.append(var1);
                    if( k -i > 1 ){
                        sb.append("^").append(k-i);
                    }
                }
                if( i > 0 ){
                    if( k - i > 0 ) {
                        sb.append("*");
                    }
                    sb.append(var2);
                    if( i > 1 ){
                        sb.append("^").append(i);
                    }
                }
                if( i < k ) {
                    sb.append("+");
                }
            }
            sb.append('\n');
        }

        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static BigInteger C(int n , int r)
    {
        return P(n,r).divide( P(r,r) ) ;
    }

    static BigInteger P(int n , int r)
    {
        BigInteger ans = BigInteger.ONE ;
        for(int i = n ; i > n-r ; i--){
            ans = ans.multiply(BigInteger.valueOf(i));
        }
        return ans ;
    }


}
