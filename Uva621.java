import java.util.*;
import java.io.*;

public class Uva621
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            char [] in = br.readLine().toCharArray();
            if(in.length<3)
                sb.append("+");
            else if(in[in.length-1]=='4'&&in[0]=='9')
                sb.append("*");
            else if(in[in.length-1]=='5'&&in[in.length-2]=='3')
                sb.append("-");
            else if(in[0]=='1'&&in[1]=='9'&&in[2]=='0')
                sb.append("?");
            sb.append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }
}
