import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva10235
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( br.ready() ){
            String n = br.readLine();
            BigInteger bi = new BigInteger(n);
            String r = new StringBuilder(n).reverse().toString() ;
            sb.append( n ).append(" is ");
            sb.append( !bi.isProbablePrime(10) ?  "not prime." :
                    !new BigInteger(r).isProbablePrime(10) || n.equals(r) ? "prime." : "emirp." );
            sb.append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
