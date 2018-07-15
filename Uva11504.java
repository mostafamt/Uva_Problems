import java.util.*;
import java.io.*;

public class Uva11504
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        while( tc-->0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()) , m = Integer.parseInt(st.nextToken());
            Graph g = new Graph(n);
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken()) , v = Integer.parseInt(st.nextToken());
                g.addEdge(u-1,v-1);
            }
            g.SCC();
            int ans = g.count();
            sb.append(ans).append('\n');
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
        int count ;

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
            count = 0 ;
        }

        public int count()
        {
            return this.count ;
        }

        public void addEdge(int v , int w)
        {
            adjList[v].add(w);
        }

        public void SCC()
        {
            for (int i = 0; i < V; i++) {
                if( disc[i] == -1 ){
                    count++ ;
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
                    stackMember[w] = false ;

                }
                w = stack.pop();
                stackMember[w] = false ;
            }
        }
    }
}
