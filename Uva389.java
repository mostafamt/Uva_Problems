import java.util.*;
import java.io.*;
import java.math.BigInteger ;

public class Uva389
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( br.ready() ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String num = st.nextToken();
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            BigInteger bi = new BigInteger(num,from);
            String ans = bi.toString(to).toUpperCase();
            sb.append( ans.length() > 7 ? String.format("%7s","ERROR") : String.format("%7s",ans)).append('\n');
        }

        pr.print(sb.toString());
        pr.close();
        br.close();
    }


}
