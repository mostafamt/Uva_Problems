/* @author : mostafa
 * created : 2018-07-27 16:35
 */

import java.util.* ;
import java.io.* ;
import java.math.BigInteger ;
public class Uva11879
{
    static final BigInteger seventeen = new BigInteger("17");

    public static void main(String[]args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        
        while( br.ready() ){
            String s = br.readLine();
            if( s.equals("0") ){
                break ;
            }
            int digit = Integer.parseInt(s.substring(s.length()-1,s.length()));
            s = s.substring(0,s.length()-1);
            BigInteger n = new BigInteger(s);
            int val = 5*digit ;
            n = n.subtract(new BigInteger(val+""));
            if( n.mod(seventeen).compareTo(BigInteger.ZERO) == 0 ){
                sb.append(1);
            } else {
                sb.append(0);
            }
            sb.append('\n');
        }
        pr.print(sb.toString() );
        br.close();
        pr.close();
    }

}

