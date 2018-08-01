/* @author : mostafa
 * created : 2018-08-01 16:07
 */
import java.util.*;
import java.io.* ;
import java.math.BigInteger ;

public class Main
{
    static final int MX = 15005 ;
    static final int [] period = {60,300,1500,15000};
    static final int [] mod = {10,100,1000,10000};
    static BigInteger [] f ;

    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter pr = new PrintWriter(System.out); 
        StringBuilder sb = new StringBuilder(); 
        int tc = Integer.parseInt(br.readLine() );
        generate_finbonacci_numbers();
        while( tc-->0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken() );
            int b = Integer.parseInt(st.nextToken() );
            int n = Integer.parseInt(st.nextToken() );
            int m = Integer.parseInt(st.nextToken() );
            BigInteger v = f[ (n-1)%period[m-1] ].multiply( BigInteger.valueOf( a%mod[m-1] ) );
            BigInteger u = f[n%period[m-1] ].multiply( BigInteger.valueOf( b%mod[m-1])  );
            u = u.add(v);
            u = u.mod( BigInteger.valueOf(mod[m-1]) );
            sb.append( u ).append('\n');
        }
        pr.print(sb.toString() );
        pr.close();
        br.close();
    }

    static void generate_finbonacci_numbers()
    {
        f = new BigInteger[MX];
        f[0] = BigInteger.ZERO ;
        f[1] = BigInteger.ONE ;
        for(int i = 2 ; i < MX ; i++){
            f[i] = f[i-1].add( f[i-2] );
        }
    }

}

