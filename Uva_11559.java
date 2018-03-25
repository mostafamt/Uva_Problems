import java.util.*;
import java.io.*;

public class Uva_11559
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while (sc.hasNext())
        {
            int ans = Integer.MAX_VALUE ;
            int n = sc.nextInt();
            int budget = sc.nextInt();
            int hotels = sc.nextInt();
            int weeks = sc.nextInt();
            for (int i = 0; i < hotels; i++) {
                int costPerOne = sc.nextInt();
                for (int j = 0; j < weeks; j++) {
                    int beds = sc.nextInt();
                    if(beds>=n) ans = Integer.min(ans , n*costPerOne);
                }
            }
            if(ans>budget) sb.append("stay home\n");
            else           sb.append(ans).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        sc.close();
    }


}
