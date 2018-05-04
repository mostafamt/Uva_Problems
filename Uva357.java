import java.util.*;
import java.io.*;

/*
 * to understand the solution , take your pen and proof it by trying many cases
 *
 * */

public class Uva357 {

    static final int MAX = 30003 ;
    static int [] coins = {5,10,25,50};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        long [] a = new long[MAX];
        Arrays.fill(a,1);

        for(int i = 0 ; i < coins.length ; i++)
        {
            for(int j = coins[i] ; j < MAX ; j++)
            {
                a[j] += a[j-coins[i]];
            }
        }

//        for(int i = 1 ; i < MAX ; i++)
//        {
//            System.out.println( i +" = " + a[i] + " ");
//        }

        while(br.ready())
        {
            int n = Integer.parseInt(br.readLine());
            sb.append(a[n] == 1 ? "There is only 1 way" : "There are " + a[n] + " ways");
            sb.append(" to produce " + n + " cents change.\n");
        }

        pr.print(sb.toString());
        br.close();
        pr.close();
    }

}
