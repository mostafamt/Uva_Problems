import java.util.*;
import java.io.*;

public class Uva247 {

    public static void main(String[] args) throws IOException
    {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int c = 0 ;
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if( n == 0 ){
                break ;
            }
            if( c > 0 ){
                sb.append('\n');
            }c++ ;
            Map<String,Integer> map = new HashMap<>();
            String [] a = new String[n];
            int num = 0 ;
            Graph g = new Graph(n);
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                String from = st.nextToken() ;
                String to = st.nextToken() ;
                if( !map.containsKey(from) ){
                    map.put(from,num);
                    a[num++] = from ;
                }
                if( !map.containsKey(to) ){
                    map.put(to,num);
                    a[num++] = to ;
                }
                g.addEdge(map.get(from),map.get(to));
            }
            g.setNames(a);
            g.SCC();
            sb.append("Calling circles for data set ").append(c).append(":\n");
            sb.append(g.getSb());
        }
        pw.print(sb.toString());
        pw.close();
        br.close();
    }



    static class Graph
    {
        int V ;
        ArrayList<Integer> [] adjList ;
        int time ;
        int [] disc ;
        int [] low ;
        boolean [] stackMember ;
        Stack<Integer> stack ;
        String [] names ;
        StringBuilder sb ;

        public Graph(int V)
        {
            this.V = V ;
            adjList = new ArrayList[V];
            for (int i = 0; i < V; i++) {
                adjList[i] = new ArrayList<Integer>();
            }
            time = 0 ;
            disc = new int[V] ;
            low = new int[V];
            stackMember = new boolean[V];
            stack = new Stack<>();
            Arrays.fill(disc,-1);
            Arrays.fill(low,-1);
            names = new String[V] ;
            sb = new StringBuilder();
        }

        public void setNames(String [] a)
        {
            this.names = a ;
        }

        public StringBuilder getSb() {
            return sb;
        }

        public void addEdge(int v , int w)
        {
            adjList[v].add(w);
        }

        public void SCC()
        {
            for (int i = 0; i < V; i++) {
                if( disc[i] == -1 ){
                    SCCUtil(i,disc , low , stack , stackMember);
                }
            }
        }

        public void SCCUtil(int u , int[] disc , int [] low , Stack<Integer> stack , boolean [] stackMember)
        {
            disc[u] = low[u] = ++time ;
            stack.push(u);
            stackMember[u] = true ;

            for(int v : adjList[u]){
                if(disc[v]==-1){
                    SCCUtil(v,disc,low,stack,stackMember);
                    low[u] = Integer.min(low[u],low[v]);
                } else if( stackMember[v] ){
                    low[u] = Integer.min(low[u],disc[v]);
                }
            }
            int w ;
            if( low[u] == disc[u] ){
                while( stack.peek() != u ){
                    w = stack.pop();
                    sb.append(names[w]).append(", ");
                    stackMember[w] = false ;

                }
                w = stack.pop();
                sb.append(names[w]).append('\n');
                stackMember[w] = false ;
            }

        }

    }
}
