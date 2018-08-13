import java.util.*;
import java.io.*;

public class Uva924
{
    static int N ;
    static ArrayList<Integer> [] adjList ;
    static int sum , day ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());
        adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            for (int j = 0; j < n; j++) {
                int u = Integer.parseInt(st.nextToken());
                adjList[i].add(u);
            }
        }
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            int x = Integer.parseInt(br.readLine());
            bfs(x);
            if( sum == 0 ){
                sb.append(0).append('\n');
            } else {
                sb.append(sum).append(" ").append(day).append('\n');
            }
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static void bfs(int u)
    {
        int [] level = new int[N+2];
        int [] num = new int[N+2];
        boolean [] marked = new boolean[N];
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        marked[u]= true ;
        level[u] = 0 ;
        num[u] = 0 ;
        sum = 0 ;
        while( !q.isEmpty() ){
            int w = q.remove() ;
            for(int i : adjList[w]){
                if( !marked[i] ){
                    marked[i] = true ;
                    q.add(i);
                    level[i] = level[w]+1 ;
                    num[ level[i] ]++ ;
                    if( num[ level[i] ] > sum ){
                        sum = num[ level[i] ];
                        day = level[i] ;
                    }
                }
            }
        }
    }

}
