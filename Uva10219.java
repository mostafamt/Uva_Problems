import java.util.*;
import java.io.*;
import java.math.BigInteger ;

public class Uva10219
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( br.ready() ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            sb.append( C(n,r).toString().length() ).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static BigInteger C(int n , int r)
    {
        r = Integer.min(r,n-r);
        BigInteger cnt = BigInteger.valueOf(1L);
        cnt = P(n,r).divide( P(r,r) );
        return cnt ;
    }

    static BigInteger P(int n , int r)
    {
        BigInteger ans = BigInteger.valueOf(1L);
        for(int i = n ; i > n-r ; i--){
            ans = ans.multiply(BigInteger.valueOf(i));
        }
        return ans ;
    }

}
