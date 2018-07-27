import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva10523
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        BigInteger ans = new BigInteger("0");
        while(br.ready() ){
            ans = BigInteger.ZERO ;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()) ;
            BigInteger a = new BigInteger(st.nextToken());
            for(int i = 1 ; i <= n ; i++){
                ans = ans.add( new BigInteger(i+"").multiply(a.pow(i)) );
            }
            sb.append(ans.toString()).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
