import java.util.*;
import java.io.*;
import java.math.BigInteger ;

public class Uva10007
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int N = 301 ;
        BigInteger [] a = new BigInteger[N];
        BigInteger [] f = new BigInteger[N];
        a[0] = f[0] = BigInteger.valueOf(1L);
        for(int i = 1 ; i < N ; i++){
            int num = 2*i * (2*i-1);
            int den = (i+1) * i ;
            a[i] = a[i-1].multiply(BigInteger.valueOf(num)).divide(BigInteger.valueOf(den));
            f[i] = f[i-1].multiply(BigInteger.valueOf(i));
        }

        int n = 0 ;
        while( (n = Integer.parseInt(br.readLine())) != 0 ){
            sb.append(a[n].multiply(f[n]).toString()).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
