import java.util.*;
import java.io.*;

public class Uva10954 {

    public static void main(String[] args) throws  IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(true)
        {
            int n = Integer.parseInt(br.readLine());
            if(n==0)
                break;
            PriorityQueue<Integer> pq = new PriorityQueue<>(n);
            StringTokenizer st = new StringTokenizer(br.readLine());
            int ind = 0 ;
            while (st.hasMoreTokens()){
                pq.add(Integer.parseInt(st.nextToken()));
            }
            long cost = 0 ;
            while (pq.size()>1){
                int x = pq.poll();
                int y = pq.poll();
                cost += x + y ;
                pq.add(x+y);
            }
            sb.append(cost).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
