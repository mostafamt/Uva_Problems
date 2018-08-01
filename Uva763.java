/* @author : mostafa
 * created : 2018-08-01 13:34
 */
import java.util.*;
import java.io.* ;
import java.math.BigInteger ;

public class Uva763
{
    static int MX = 105 ;
    static BigInteger [] f ;

    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        PrintWriter pr = new PrintWriter(System.out); 
        StringBuilder sb = new StringBuilder();
        generate_fibonacci_number();
        int c = 1 ;
        while( br.ready() ){
            if( c > 1 ){
                sb.append("\n\n");
            }
            c++ ;
            String s1 = br.readLine();
            String s2 = br.readLine();
            if( s1.equals("0") || s2.equals("0") ) {
                if( s1.equals("0") && s2.equals("0") ){
                    sb.append("0");
                } else if( s1.equals("0") ){
                    sb.append(s2.toString() );
                } else {
                    sb.append( s1.toString() );
                }
                if( br.ready() ){
                    br.readLine();
                }
                continue ;
            }
            BigInteger a1 = decrypt(s1);
            BigInteger a2 = decrypt(s2);
            a1 = a1.add(a2);
            String ans = encrypt(a1);
            sb.append(ans);
            if( br.ready() ){
                br.readLine();
            }
        }
        pr.println(sb.toString() );
        pr.close();
        br.close();
    }

    static void generate_fibonacci_number()
    {
        f = new BigInteger[MX];
        f[1] = new BigInteger("1");
        f[2] = new BigInteger("2");
        for(int i = 3 ; i < MX ; i++){
            f[i] = f[i-1].add( f[i-2] );
        }
    }

    static BigInteger decrypt(String s)
    {
        BigInteger ans = new BigInteger("0");
        for(int i = s.length()-1 , j = 1 ; i >= 0 ; i-- , j++){
            ans = ans.add( f[j].multiply( new BigInteger( s.charAt(i)+"" ) ) ) ;
        }
        return ans ;
    }

    static String encrypt(BigInteger a)
    {
        int idx = 1 ;
        for(int i = 1 ; i < MX ; i++){
            if( f[i].compareTo(a) > 0 ){
                idx = i ;
                break ;
            }
        }
        String s = "" ;
        for(int i = idx-1 ; i > 0 ; i--){
            if( f[i].compareTo(a) <= 0 ){
                s += "1";
                a = a.subtract( f[i] );
            } else {
                s += "0" ;
            }
        }
        return s ;
    }
}

