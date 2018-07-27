import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva424
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        BigInteger bi = new BigInteger("0");
        while( br.ready() ){
            bi = bi.add(new BigInteger(br.readLine()) );
        }
        pw.println(bi.toString());
        pw.close();
        br.close();
    }
}
