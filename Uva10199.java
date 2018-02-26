import java.util.*;
import java.io.*;

/*
 * Uva 10199 - Tourist Guide
 * @ author Mostafa Kamel
 * Description : Just find articulation point .
 */

public class Uva10199
{
    static ArrayList<Integer> [] adjList ;
    static int [] parent ;
    static int [] dfs_low ;
    static int [] dfs_num ;
    static int root ;
    static int rootChildren ;
    static String [] names ;
    static HashMap<String,Integer> map ;
    static boolean [] marked ;
    static int counter ;
    static boolean [] isArticulationPoint ;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int count = 1 ;
        int n = sc.nextInt();
        while (n!=0)
        {
            adjList = (ArrayList<Integer>[]) new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i] = new ArrayList<>();
            parent = new int[n];
            dfs_low = new int[n];
            dfs_num = new int[n];
            names = new String[n];
            map = new HashMap<>();
            marked = new boolean[n];
            isArticulationPoint = new boolean[n];
            for(int i = 0 ; i < n ; i++)
            {
                String city = sc.next();
                names[i] = city ;
                map.put(city,i);
            }
            int m = sc.nextInt();
            while(m-->0)
            {
                int u = map.get(sc.next());
                int v = map.get(sc.next());
                adjList[u].add(v);
                adjList[v].add(u);
            }
            for (int i = 0; i < n; i++) {
                if(!marked[i])
                {
                    root = i ;
                    rootChildren = 0 ;
                    dfs(i);
                    if(rootChildren<=1)
                        isArticulationPoint[root] = false ;
                }
            }
            TreeSet<String> tree = new TreeSet<>();
            for (int i = 0; i < n; i++)
                if(isArticulationPoint[i])
                    tree.add(names[i]);
            sb.append("City map #"+(count++)+": "+(tree.size())+" camera(s) found\n");
            for(String s : tree)
                sb.append(s).append("\n");
            n = sc.nextInt();
            if(n!=0)
                sb.append("\n");
        }
        pr.print(sb.toString());
        sc.close();
        pr.close();
    }

    static void dfs(int u)
    {
        dfs_low[u] = dfs_num[u] = counter++ ;
        marked[u] = true ;
        for (int w :adjList[u])
        {
            if(!marked[w])
            {
                parent[w] = u ;
                if(u==root)
                    rootChildren++ ;
                dfs(w);
                if(dfs_low[w]>=dfs_num[u])
                    isArticulationPoint[u]=true ;
                dfs_low[u] = Integer.min(dfs_low[u],dfs_low[w]);
            }
            else
            {
                if(parent[w]!=u)
                    dfs_low[u] = Integer.min(dfs_low[u],dfs_num[w]);
            }
        }
    }
}
