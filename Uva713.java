import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva713
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int tc = Integer.parseInt(br.readLine());
        while(tc-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            sb.append(new BigInteger(new StringBuffer(new BigInteger(new StringBuffer(st.nextToken()).reverse().toString()).
                    add(new BigInteger(new StringBuffer(st.nextToken()).reverse().toString())).toString()).
                    reverse().toString() ) ).append('\n');
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

}
