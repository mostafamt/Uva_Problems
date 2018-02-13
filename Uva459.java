import java.util.* ;
import java.io.* ;
/**
 * uva 459 Graph Connectivity
 * @author mostafa
 */
public class Uva459 
{
    static ArrayList<Integer> [] adjList ;
    static boolean [] marked ;
    
    public static void main(String[] args) throws IOException
    {
//        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        br.readLine();
        while(tc-->0)
        {
            int N = br.readLine().charAt(0)- 'A' + 1 ;
            marked = new boolean [N];
            adjList = new ArrayList[N];
            for (int i = 0; i < N ; i++)
                adjList[i] = new ArrayList<Integer>();
            String str ; 
            while( ( str = br.readLine() ) != null && !str.equals("") )
                addEdge( str.charAt(0)-'A' ,  str.charAt(1)-'A' );
            int count = 0 ;
            for (int i = 0; i < N ; i++)
                if(!marked[i])
                {
                    count++ ;
                    dfs(i);
                }
            if(tc==0)
                sb.append(count+"\n");
            else
                sb.append(count+"\n\n");
        }
        
        pr.print(sb);
        br.close();
        pr.close();
    }
    
    public static void dfs(int s)
    {
        marked[s] = true ;
        for(int w : adjList[s])
            if(!marked[w])  dfs(w);
    }
    
    public static void addEdge(int u , int v)
    {
        adjList[u].add(v);
        adjList[v].add(u);
    }
    
}
