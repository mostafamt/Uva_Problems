
import java.io.* ;
import java.util.* ;
/**
 *
 * @author mostafa
 */
public class Uva11060 {
    
    static int [][] adjMat ;
    static int nVerts ;
    static String [] vertexList ;
    static Map<String , Integer> map = new HashMap<>() ;
    static int [] sortedArray ;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s ;
        int time = 1 ;
        StringBuilder stringBuilder = new StringBuilder();
        while( ( s = br.readLine()) != null && !s.isEmpty() )
        {
            int n = Integer.parseInt(s);
            Topo graph = new Topo(n);
            Map<String , Integer> map = new HashMap<>();
            Map<Integer , String> map2 = new HashMap<>();
            int index = 0 ;
            for (int i = 0; i < n ; i++) {
                String str = br.readLine();
                map2.put(index, str);
                map.put(str , index++);
            }
            int len = Integer.parseInt(br.readLine());
            for (int i = 0; i < len ; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                graph.addEdge( map.get(st.nextToken()) , map.get(st.nextToken()) );
            }
            List<Integer> list = graph.topoSort();
            
            stringBuilder.append("Case #");
            stringBuilder.append(time++);
            stringBuilder.append(": Dilbert should drink beverages in this order: ");
            int size = list.size();
            for (int i = 0 ; i < size ; i++) {
                if( i == size-1 )
                    stringBuilder.append(map2.get(list.get(i) )+".");
                else
                    stringBuilder.append(map2.get(list.get(i) )+" ");
            }
            stringBuilder.append("\n\n");
            br.readLine();
        }
        System.out.print( stringBuilder.toString() );
        
        br.close();
        out.flush();
        out.close();
    }
    
    
    
}


class Topo
{
    List<Integer> [] adjList ;
    int nVertex ;
    
    public Topo(int n)
    {
        nVertex = n ;
        adjList = new ArrayList[nVertex];
        for (int i = 0; i < nVertex ; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    
    public void addEdge(int u , int v)
    {
        adjList[u].add(v);
    }
    
    public List topoSort()
    {
        int [] indegree = new int[nVertex];
        for (int i = 0; i < adjList.length; i++) {
            ArrayList<Integer> list = (ArrayList<Integer>)adjList[i];
            for (int t : list) {
                indegree[t]++ ;
            }
        }
        Queue<Integer> q = new PriorityQueue<>();
        for (int i = 0 ; i < indegree.length ; i++) {
            if( indegree[i] == 0 )
                q.add(i);
        }

        List<Integer> list = new ArrayList<>();
        while( !q.isEmpty() )
        {
            int u = q.poll();
            list.add(u);
            ArrayList<Integer> neigh = (ArrayList<Integer>)adjList[u];
            for (int i : neigh) {
                if( --indegree[i] == 0 )
                    q.add(i);
            }
        }
        return list ;
    }
}

