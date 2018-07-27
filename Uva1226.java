import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva1226
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            BigInteger n = new BigInteger(br.readLine());
            BigInteger p = new BigInteger(br.readLine());
            sb.append(p.remainder(n).toString()).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
