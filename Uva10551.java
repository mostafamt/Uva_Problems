/* @author : mostafa
 * created : 2018-07-27 17:20
 */
import java.util.*;
import java.io.* ;
import java.math.BigInteger ;

public class Uva10551
{
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter pr = new PrintWriter(System.out); 
        StringBuilder sb = new StringBuilder();

        while( br.ready() ){
            StringTokenizer st = new StringTokenizer( br.readLine() );
            int base = Integer.parseInt(st.nextToken() );
            if( base == 0 ){
                break ;
            }
            BigInteger p = new BigInteger(st.nextToken() , base );
            BigInteger m = new BigInteger(st.nextToken() , base );
            sb.append( p.mod(m).toString(base) ).append('\n');
        }
        
        pr.print(sb.toString() );
        br.close();
        pr.close();
     
    }
    
}

