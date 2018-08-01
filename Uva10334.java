/* @author : mostafa
 * created : 2018-08-01 16:07
 */
import java.util.*;
import java.io.* ;
import java.math.BigInteger ;

public class Uva10334
{
    static final int MX = 1002 ;
    static BigInteger f [];

    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter pr = new PrintWriter(System.out); 
        StringBuilder sb = new StringBuilder(); 
        generate_fibonacci_number();
        while( br.ready() ){
            Integer n = Integer.parseInt(br.readLine() );
            sb.append( f[n].toString() ).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static void generate_fibonacci_number()
    {
        f = new BigInteger[MX];
        f[0] = new BigInteger("1");
        f[1] = new BigInteger("2");
        for(int i = 2 ; i < MX ; i++){
            f[i] = f[i-1].add(f[i-2]);
        }
    }
}

