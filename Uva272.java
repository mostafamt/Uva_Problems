import java.util.*;
import java.io.*;

public class Uva272
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        PrintWriter pr = new PrintWriter(System.out);
        String str ;
        boolean staus =false ;
        while((str = br.readLine()) != null)
        {
            int len = str.length();
            for (int i = 0; i < len; i++)
            {
                if(str.charAt(i) == '"')
                {
                    if(staus) sb.append("''");
                    else      sb.append("``");
                    staus = !staus ;
                }
                else
                    sb.append(str.charAt(i));
            }
            sb.append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
