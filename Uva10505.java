import java.util.*;
import java.io.*;

/*
 * Uva 10505 - Montesco vs Capuleto
 * Description : The first thing you will do is connect each two enemes by an edge .
 *               what will that do ?
 *               It makes the graph to be bipartite .It means each that two neighbours must be assigned
 *               different values (different colors) . by dfs assign the valus to each subgraph .
 *               calculate max color for each subgraph .
 * @ author Mostafa Kamel
 */

public class Uva10505
{
    static ArrayList<Integer> [] adjList ;
    static int [] marked ;
    static int montesco = 0 , capuleto = 0 ;
    static boolean isBipartite ;
    static final int N = 200 ;

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        while(tc-->0)
        {
            int n = sc.nextInt();
            marked = new int[N];
            adjList = (ArrayList<Integer>[]) new ArrayList[N];
            for (int i = 0; i < N; i++)
                adjList[i] = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                int t = sc.nextInt();
                while (t-->0)
                {
                    int x = sc.nextInt()-1;
                    if(x>=n) continue;
                    adjList[i].add(x);
                    adjList[x].add(i);
                }
            }
            int max = 0 ;
            for (int i = 0; i < n; i++) {
                if(marked[i] == 0 )
                {
                    isBipartite = true ;
                    marked[i] = 1 ;
                    capuleto = montesco = 0 ;
                    bipartite(i);
                    if(isBipartite)
                        max += Integer.max(montesco , capuleto);
                }
            }
            sb.append(max).append("\n");
        }
        pr.print(sb.toString());
        sc.close();
        pr.close();
    }

    static void bipartite(int u)
    {
        if(marked[u] == 1)
            montesco++ ;
        else if( marked[u] == -1 )
            capuleto++ ;
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u].get(i);
            if(marked[v] == 0)
            {
                if(marked[u]==1)
                    marked[v] = -1 ;
                else
                    marked[v] = 1 ;
                bipartite(v);
            }
            else if( marked[v] == marked[u] )
                isBipartite = false ;
        }
    }

}
