import java.util.* ;
import java.io.* ;

/*
* Uva 11396 - Claw Decomposition
* @ author Mostafa Kamel
*/
public class Uva11369
{

    public static void main(String[] args)throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        while(sc.hasNext())
        {
            int n = sc.nextInt();
            if(n==0)
                break;
            Graph G = new Graph(n+1);
            int u = sc.nextInt();
            int v = sc.nextInt();
            while(u!= 0 && v != 0)
            {
                G.addEdge(u,v);
                u = sc.nextInt();
                v = sc.nextInt();
            }
            pr.println(new TwoColor(G).isBipartite() ? "YES" : "NO");
        }
        pr.close();
        sc.close();
    }

}

class Graph
{
    private final int V ;
    private int E ;
    private ArrayList<Integer>[] adj ;

    public Graph(int V)
    {
        this.V = V ;
        adj = (ArrayList<Integer>[])new ArrayList[V];
        for (int i = 0; i < V ; i++)
            adj[i] = new ArrayList<Integer>();
    }

    public int V(){ return V; }
    public int E(){ return E; }

    public void addEdge(int v , int w)
    {
        adj[v].add(w);
        adj[w].add(v);
        E++ ;
    }

    public Iterable<Integer> adj(int v)
    {   return adj[v];   }

    @Override
    public String toString()
    {
        String s = V + " vertices, " + E + " edges\n";
        for (int v = 0; v < V ; v++)
        {
            s += v + ": " ;
            for(int w : adj(v))
                s += w + " ";
            s += "\n";
        }
        return s ;
    }
}

class TwoColor
{
    private boolean[]marked ;
    private boolean[]color ;
    private boolean isTwoColorable  = true ;

    public TwoColor(Graph G)
    {
        marked = new boolean[G.V()];
        color = new boolean[G.V()];
        for (int s = 0; s < G.V(); s++) {
            if (!marked[s])
                dfs(G,s);
        }
    }

    private void dfs(Graph G , int v)
    {
        marked[v] = true ;
        for(int w : G.adj(v))
            if(!marked[w])
            {
                color[w] = !color[v];
                dfs(G,w);
            }
            else if(color[w]==color[v])
            {
                isTwoColorable = false ;
            }
    }

    public boolean isBipartite()
    {
        return isTwoColorable ;
    }
}
