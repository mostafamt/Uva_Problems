import java.io.* ;
import java.util.* ;
/**
 * 10305 - Ordering Tasks
 * @author mostafa
 */
public class Uva10305 
{
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(true)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if(n==0&&m==0)
                break ;
            Digraph digraph = new Digraph(n);
            while(m-->0)
            {
                st = new StringTokenizer(br.readLine());
                int i = Integer.parseInt(st.nextToken());
                int j = Integer.parseInt(st.nextToken());
                digraph.addEdge(i-1, j-1);
            }
            DepthFirstOrder dfo = new DepthFirstOrder(digraph);
            for(int i : dfo.reversePost())
                sb.append(i+1).append(" ");
            sb.append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }
    
    
}

class Digraph 
{
    private final int V ;
    private int E ;
    private ArrayList<Integer> [] adjList ;
    
    public Digraph(int V)
    {
        this.V = V ;
        E = 0 ;
        adjList = new ArrayList[V];
        for (int i = 0; i < V ; i++)
            adjList[i] = new ArrayList<Integer>();
    }
    
    public int V() {   return V ;  }
    
    public int E() {   return E ;  }
    
    public void addEdge(int v , int w)
    {
        adjList[v].add(w);
        E++ ;
    }
    
    public Iterable<Integer> adj(int v)
    {   return adjList[v];      }
    
}

class DepthFirstOrder 
{
    private boolean marked [];
    private Deque<Integer> reversePost ;
    
    public DepthFirstOrder(Digraph G)
    {
        reversePost = new LinkedList<>();
        marked = new boolean [G.V()];
        for (int i = 0; i < G.V() ; i++)
            if(!marked[i]) dfs(G, i);
    }
    
    public void dfs(Digraph G , int v)
    {
        marked[v] = true ;
        for(int w : G.adj(v))
            if(!marked[w])  dfs(G, w);
        reversePost.push(v);
    }
    
    public Iterable<Integer> reversePost()
    {   return reversePost ;     }
    
}