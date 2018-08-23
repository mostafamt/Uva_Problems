/* @author : mostafa
 * created : 2018-08-17 00:19
 */
import java.util.*;
import java.io.* ;
import java.math.BigInteger ;

public class Uva10541
{
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter pr = new PrintWriter(System.out); 
        StringBuilder sb = new StringBuilder(); 
        
        int tc = Integer.parseInt(br.readLine());
        while( tc--> 0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt( st.nextToken() ) ;
            int k = Integer.parseInt( st.nextToken() ) ;
            for(int i = 0 ; i < k ; i++){
                int x = Integer.parseInt( st.nextToken() );
                n -= x ;
            }
            n++ ;
            if( k > n ){
                sb.append(0).append('\n');
                continue ;
            }
            BigInteger ans = BigInteger.ONE ;
            for(int i = n ; i > n-k ; i--){
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            for(int i = k ; i > 1 ; i--){
                ans = ans.divide(BigInteger.valueOf(i));
            }
            sb.append(ans.toString()).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}

