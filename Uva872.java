import java.util.*;
import java.io.*;

// degree is an alternative efficient algorithm to chack graph cycle

public class Uva872
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        int t = 0 ;
        while( tc-->0 ){
            if( t > 0 ){
                sb.append('\n');
            }t++ ;
            Map<Character,Integer> map = new HashMap<>();
            char [] a = new char[22];
            int num = 0 ;
            br.readLine() ;
            StringTokenizer st = new StringTokenizer(br.readLine());
            while( st.hasMoreTokens() ){
                String str = st.nextToken() ;
                char c = str.charAt(0);
                map.put(c,num);
                a[num] = c ;
                num++ ;
            }
            Graph g = new Graph(num);
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                String s = st.nextToken() ;
                if( s.charAt(1) == '<' ){
                    g.addEdge(map.get(s.charAt(0)) , map.get(s.charAt(2)) );
                } else {
                    g.addEdge( map.get(s.charAt(2)) , map.get(s.charAt(0)) );
                }
            }
            g.setArray( a , num );
            g.allTopologicalSortUtil();
            if( g.hasCycle() ){
                sb.append("NO\n");
            } else {
                sb.append(g.getSb());
            }
        }
        pw.print(sb.toString());
        pw.close();
        br.close();

    }

    static class Graph
    {
        int V ;
        ArrayList<Integer> [] adjList ;
        int [] indegree ;
        boolean [] visited ;
        int [] res ;
        int idx ;
        char [] a ;
        StringBuilder sb ;
        boolean hasCycle ;

        public Graph(int V)
        {
            this.V = V ;
            adjList = new ArrayList[V];
            for (int i = 0; i < V; i++) {
                adjList[i] = new ArrayList<Integer>();
            }
            indegree = new int[V] ;
            visited = new boolean[V];
            res = new int[V] ;
            idx = 0 ;
            sb = new StringBuilder();
            hasCycle = true ;
        }

        public StringBuilder getSb() {
            return sb;
        }

        void setArray(char [] a , int size)
        {
            this.a = a ;
        }

        public boolean hasCycle()
        {
            return hasCycle ;
        }

        public void addEdge(int v ,int w)
        {
            adjList[v].add(w);
            indegree[w]++ ;
        }

        public void allTopologicalSortUtil()
        {
            boolean flag = false ;
            for (int i = 0; i < V; i++) {
                if( indegree[i] == 0 && !visited[i] ){
                    hasCycle = false ;
                    int size = adjList[i].size() ;
                    for (int j = 0; j < size; j++) {
                        indegree[adjList[i].get(j)]-- ;
                    }
                    res[idx++] = i ;
                    visited[i] = true ;
                    allTopologicalSortUtil();
                    // clear what you have used
                    visited[i] = false ;
                    idx-- ;
                    for (int j = 0; j < size; j++) {
                        indegree[adjList[i].get(j)]++ ;
                    }
                    flag = true ;
                }
            }
            if(!flag)
            {
                for (int i = 0; i < idx ; i++) {
                    if( i+1 == idx ){
                        sb.append(a[res[i]]);
                    } else {
                        sb.append(a[res[i]]).append(" ");
                    }
                }
                sb.append("\n");
            }
        }


    }

}
