import java.util.*;
import java.io.*;

public class Uva280
{
    static ArrayList<Integer> [] adjList ;
    static boolean [] marked ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        String line ;
        while( !(line = br.readLine()).equals("0") ){
            Integer n = Integer.parseInt(line);
            adjList = new ArrayList[n+1];
            for (int i = 0; i < n + 1; i++) {
                adjList[i] = new ArrayList<>();
            }
            String s ;
            while( !(s = br.readLine()).equals("0") ){
                StringTokenizer st = new StringTokenizer(s);
                int u = Integer.parseInt(st.nextToken());
                while( st.hasMoreTokens() ){
                    int v = Integer.parseInt(st.nextToken());
                    if( v == 0 ){
                        continue ;
                    }
                    adjList[u].add(v);
                }
            }
            StringTokenizer st = new StringTokenizer(br.readLine());
            int q = Integer.parseInt(st.nextToken());
            for (int i = 0; i < q; i++) {
                int x = Integer.parseInt(st.nextToken());
                marked = new boolean[n+1];
                int sum = 0 ;
                for(int y : adjList[x]){
                    if(!marked[y]){
                        sum += dfs(y);
                    }
                }
                sb.append(n-sum);
                for(int j = 1 ; j <= n ; j++){
                    if(!marked[j]){
                        sb.append(" ").append(j);
                    }
                }
                sb.append('\n');
            }
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static int dfs(int u)
    {
        marked[u] = true ;
        int sum = 1 ;
        for(int v : adjList[u]){
            if( !marked[v] ){
                sum += dfs(v);
            }
        }
        return sum ;
    }
}
