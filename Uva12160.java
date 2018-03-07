import java.util.*;
import java.io.*;

/*
 * Uva 12160 - Unlock the Lock
 * @ author Mostafa Kamel
 */
public class Uva12160
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int U = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int Case = 1 ;
        while(!(L==0&&U==0&&R==0))
        {
            st = new StringTokenizer(br.readLine());
            int [] distTo = new int[10000];
            int [] btn = new int[R];
            for (int i = 0; i < R; i++)
                btn[i] = Integer.parseInt(st.nextToken());
            Queue<Integer> q = new LinkedList<>();
            q.add(L);
            distTo[L] = 0 ;
            while (!q.isEmpty())
            {
                int curKey = q.remove();
                for(int Key : btn)
                {
                    int w = (Key+curKey) % 10000 ;
                    if(distTo[w] == 0)
                    {
                        q.add(w);
                        distTo[w] = distTo[curKey]+1 ;
                    }
                }
            }
            sb.append("Case "+Case+++": ").append(distTo[U] == 0 ? "Permanently Locked":distTo[U]).append("\n");
            st = new StringTokenizer(br.readLine());
            L = Integer.parseInt(st.nextToken());
            U = Integer.parseInt(st.nextToken());
            R = Integer.parseInt(st.nextToken());
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
