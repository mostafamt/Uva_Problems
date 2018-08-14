import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva11718
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        long tc = Long.parseLong(br.readLine());
        for(long i = 1 ; i <= tc ; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int mod = Integer.parseInt(st.nextToken());
            long sum = 0 ;
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                sum += Long.parseLong(st.nextToken());
                sum %= mod ;
            }
            // k * sum * n ^ k-1
            // modPow , so useful , it gives RTE without it .
            BigInteger val = BigInteger.valueOf(n).modPow(BigInteger.valueOf(k-1),BigInteger.valueOf(mod));
            int var = val.mod(BigInteger.valueOf(mod)).intValue();
            long ans = k * sum * var ;
            ans %= mod ;
            sb.append("Case ").append(i).append(": ").append(ans).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
