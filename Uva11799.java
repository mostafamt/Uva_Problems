import java.util.*;
import java.io.*;

public class Uva11799
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        for (int i = 1; i <= tc; i++)
        {
            int n = sc.nextInt();
            int max = Integer.MIN_VALUE;
            for (int j = 0; j < n; j++)
                max = Integer.max(max,sc.nextInt());
            sb.append("Case ").append(i).append(": ").append(max).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        sc.close();
    }
}
