
import java.util.*;
import java.io.*;

public class Uva10055
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        String str = "" ;
        while( (str = br.readLine())!=null )
        {
            StringTokenizer st = new StringTokenizer(str);
            sb.append(Math.abs(Long.parseLong(st.nextToken())-Long.parseLong(st.nextToken()))).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }



}
