import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva465
{
    static final BigInteger overFlow = new BigInteger(Integer.MAX_VALUE+"");

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( br.ready() )
        {
            String line = br.readLine() ;
            sb.append(line).append("\n");
            StringTokenizer st = new StringTokenizer(line);
            BigInteger a = new BigInteger(st.nextToken());
            char c = st.nextToken().charAt(0);
            BigInteger b = new BigInteger(st.nextToken());
            BigInteger resutlt = new BigInteger("0");
            if( c == '+' ){
                resutlt = a.add(b);
            } else {
                resutlt = a.multiply(b);
            }

            if( a.compareTo(overFlow) > 0 ){
                sb.append("first number too big\n");
            }
            if( b.compareTo(overFlow) > 0 ){
                sb.append("second number too big\n");
            }
            if( resutlt.compareTo(overFlow) > 0 ){
                sb.append("result too big\n");
            }

        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

}
