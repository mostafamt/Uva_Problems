import java.util.*;
import java.io.*;

public class Uva796
{
    static ArrayList<Integer> [] adjList ;
    static int [] dfs_num ;
    static int [] dfs_low ;
    static int dfs_number_counter ;
    static int [] parent ;
    static ArrayList<Bridge> bridges ;

    public static void main(String[] args)throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int c = 0 ;
        while(br.ready()){
            int n = Integer.parseInt(br.readLine());
            adjList = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                adjList[i] = new ArrayList<Integer>();
            }
            dfs_num = new int[n];
            dfs_low = new int[n];
            dfs_number_counter = 0 ;
            parent = new int[n];
            bridges = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                st.nextToken();
                while(st.hasMoreTokens()){
                    int v = Integer.parseInt(st.nextToken());
                    addEdge(u,v);
                }
            }
            for (int i = 0; i < n; i++) {
                if(dfs_num[i] == 0){
                    findBridges(i);
                }
            }
            int size = bridges.size();
            Collections.sort(bridges);
            sb.append(size).append(" critical links\n");
            for (int i = 0; i < size; i++) {
                sb.append(bridges.get(i).u+" - "+bridges.get(i).v).append("\n");
            }
            sb.append('\n');
            br.readLine();
        }

        pw.print(sb.toString());
        pw.close();
        br.close();
    }

    public static void addEdge(int u , int v)
    {
        adjList[u].add(v);
        adjList[v].add(u);
    }

    public static void findBridges(int u)
    {
        dfs_num[u] = dfs_low[u] = ++dfs_number_counter ;
        for(int v : adjList[u]){
            if( dfs_num[v] == 0 ){
                parent[v] = u ;
                findBridges(v);
                if( dfs_low[v] > dfs_num[u] ){
                    // bridge
                    bridges.add(new Bridge(Integer.min(u,v),Integer.max(u,v)));
                }
                dfs_low[u] = Integer.min(dfs_low[u],dfs_low[v]);
            } else if( v != parent[u] ){
                dfs_low[u] = Integer.min(dfs_low[u],dfs_num[v]);
            }
        }
    }

    static class Bridge implements Comparable<Bridge>
    {
        int u ;
        int v ;

        public Bridge(int u, int v) {
            this.u = u;
            this.v = v;
        }

        public int compareTo(Bridge that)
        {
            if( this.u == that.u ){
                return this.v - that.v ;
            } else {
                return this.u - that.u;
            }
        }
    }

}
