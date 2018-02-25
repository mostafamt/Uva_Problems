import java.util.*;
import java.io.*;

/*
 * Uva 315 - Network
 * @ author Mostafa Kamel
 * Description : John Edward Hopcroft and Robert Endre Tarjan to compute Articulation point
 */
public class Uva315
{
    static ArrayList<Integer> []adjList ;
    static boolean [] marked ;
    static int [] parent ;
    static boolean [] isArticulationPoint ;
    static int [] dfs_low ;
    static int [] dfs_num ;
    static int counter ;
    static int root ;
    static int rootChildren ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while (n!=0)
        {
            marked = new boolean[n];
            parent = new int[n];
            isArticulationPoint = new boolean[n];
            dfs_low = new int[n];
            dfs_num = new int[n];
            adjList = (ArrayList<Integer>[]) new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i] = new ArrayList<Integer>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken())-1;
            while(x!=-1)
            {
                while (st.hasMoreTokens())
                {
                    int y = Integer.parseInt(st.nextToken())-1;
                    adjList[x].add(y);
                    adjList[y].add(x);
                }
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken())-1;
            }
            for (int i = 0; i < n; i++) {
                if(!marked[i])
                {
                    root = i ;
                    rootChildren = 0 ;
                    marked[i] = true ;
                    dfs(i);
                    if(rootChildren <= 1)
                        isArticulationPoint[root] =false ;
                }
            }
            int sum = 0 ;
            for (boolean b : isArticulationPoint ) {
                if(b) sum++ ;
            }
            sb.append(sum).append("\n");
            n = Integer.parseInt(br.readLine());
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static void dfs(int u)
    {
        marked[u] = true ;
        dfs_num[u] = dfs_low[u] = counter++ ;
        for (int w :adjList[u])
        {
            if(!marked[w])
            {
                parent[w] = u ;
                if(u==root)
                    rootChildren++ ;
                dfs(w);
                if(dfs_low[w] >= dfs_num[u])
                    isArticulationPoint[u] = true ;
                dfs_low[u] = Integer.min(dfs_low[w],dfs_low[u]);

            }
            else
            {
                if(parent[u] != w)
                    dfs_low[u] = Integer.min(dfs_low[u] , dfs_num[w]);
            }
        }

    }


}
