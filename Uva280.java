import java.util.* ;
import java.io.* ;
/**
 * Uva 280 - Vertex
 * @author mostafa
 */
public class Uva280 
{
    static ArrayList<Integer> [] adjList ;
    static int N ;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        String s ;
        while( !( s = br.readLine() ).equals("0") )
        {
            N = Integer.parseInt(s)+1 ;
            adjList = new ArrayList[N];
            for (int i = 0; i < N ; i++)
                adjList[i] = new ArrayList();
            String str ;
            StringTokenizer st ;
            while( !( str = br.readLine() ).equals("0") )
            {
                st = new StringTokenizer(str);
                int start = Integer.parseInt(st.nextToken());
                String string;
                while(! ( string = st.nextToken()).equals("0"))
                    adjList[start].add( Integer.parseInt(string));
            }
            st = new StringTokenizer(br.readLine());
            // check AdjList
//            System.out.println("AdjList : ");
//            for (int i = 0; i < adjList.length ; i++) {
//                ArrayList<Integer> lst = adjList[i];
//                System.out.print(i+" = ");
//                for (Integer integer : lst) {
//                    System.out.print(integer+" ");
//                }
//                System.out.println("");
//            }
            int num = Integer.parseInt(st.nextToken());
            while(num-->0)
            {
                HashSet<Integer> set = DFS(Integer.parseInt(st.nextToken()));
                int n = N - set.size()-1;
                sb.append(n);
                for (int i = 1 ; i < N ; i++ ) {
                    if(!set.contains(i)){
                        sb.append(" "+i);
                    }
                }
                sb.append("\n");
            }
        }
        pr.print(sb.toString());
        
        pr.close();
        br.close();
    }
    
    public static HashSet DFS(int startVertex)
    {
        Stack<Integer> stack = new Stack<Integer>();
        boolean [] visited = new boolean[N];
        HashSet<Integer> set = new HashSet();
        stack.push(startVertex);
//        visited[startVertex] = true ;          // don't visit it . it might contain a self loop .
        while(!stack.isEmpty())
        {
            int v = getUnvisitedVertex(stack.peek(), visited);
            if(v==-1)
                stack.pop();
            else
            {
                stack.push(v);
                visited[v] = true ;
                set.add(v);
            }
        }
        return set ;
    }
    
    public static int getUnvisitedVertex(int vertex , boolean [] visited)
    {
        int size = adjList[vertex].size();
        for (int i = 0; i < size ; i++) {
            int node = adjList[vertex].get(i);
            if(!visited[node])
                return node ;
        }
        return -1 ;
    }
}
