import java.util.* ;
import java.io.* ;
/**
 * Uva 11060 - Beverages
 * @author mostafa
 */
public class Uva11060 
{
    static int [] indegree ;
    static int N ;
    static ArrayList<Integer> [] adjList ;
    static int [] ans ;
    
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int c = 1 ;
        while(br.ready())
        {
            N = Integer.parseInt(br.readLine());
            indegree = new int[N];
            adjList = (ArrayList<Integer>[])new ArrayList[N];
            for (int i = 0; i < N ; i++)
                adjList[i] = new ArrayList<Integer>();
            String [] toString = new String[N];
            Map<String,Integer> toInteger = new HashMap<String,Integer>();
            for (int i = 0; i < N ; i++)
            {
                String str = br.readLine();
                toString[i] = str ;
                toInteger.put(str, i);
            }
            int m = Integer.parseInt(br.readLine());
            for (int i = 0; i < m ; i++) 
            {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int u = toInteger.get(st.nextToken());
                int v = toInteger.get(st.nextToken());
                adjList[u].add(v);
                indegree[v]++ ;
            }
            khan();
            sb.append("Case #"+(c++)+": Dilbert should drink beverages in this order: ");
            for (int i = 0; i < N-1 ; i++) 
                sb.append(toString[ans[i]]).append(" ");
            sb.append(toString[ans[N-1]]+".\n\n");
            br.readLine();
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
        
    }
    
    static void khan()
    {
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        for (int i = 0; i < N ; i++)
            if (indegree[i] == 0)
                q.add(i);
        int cnt = 0;
        ans = new int[N];
        int i = 0 ;
        while (!q.isEmpty())
        {
            int u = q.poll();
            ans[i++] = u ;
            for (int node : adjList[u])
                if (--indegree[node] == 0)
                    q.add(node);
            cnt++;
        }
    }
}
