import java.util.*;
import java.io.*;

public class Uva10048
{
    static ArrayList<Pair> [] tree ;
    static int ans ;
    static boolean [] marked ;

    static boolean dfs(int u , int v)
    {
        if( u == v ){
            return true ;
        }
        marked[u] = true ;
        for(Pair p : tree[u]){
            if( !marked[p.u] && dfs(p.u ,v) ){
                ans = Integer.max(ans , p.w);
                return true ;
            }
        }
        return false ;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int c = 1 ;
        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            if( N == 0 ){
                break ;
            }
            if(c>1){
                sb.append('\n');
            }
            sb.append("Case #").append(c++).append('\n');
            Triple [] edgeList = new Triple[E];
            tree = new ArrayList[N];
            for (int i = 0; i < N; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                u-- ; v-- ;
                edgeList[i] = new Triple(w,u,v);
            }
            Arrays.sort( edgeList );
            UnionFind uf = new UnionFind(N);
            for (int i = 0; i < E; i++) {
                int w = edgeList[i].w , u = edgeList[i].u , v = edgeList[i].v ;
                if( !uf.isSameSet(u,v) ){
                    uf.union(u,v);
                    tree[u].add( new Pair(w,v) );
                    tree[v].add( new Pair(w,u) );
                }
            }

            for (int i = 0; i < q; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                u-- ; v-- ;
                marked = new boolean[101];
                ans = 0 ;
                boolean status = dfs(u,v);
                sb.append( status ? ans : "no path" ).append('\n');
            }
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }


    static class Triple implements Comparable<Triple>
    {
        int w ;
        int u ;
        int v ;

        public Triple(int w, int u, int v) {
            this.w = w;
            this.u = u;
            this.v = v;
        }

        @Override
        public int compareTo(Triple that)
        {
            return this.w - that.w ;
        }
    }

    static class Pair
    {
        int w ;
        int u ;

        public Pair(int w, int u) {
            this.w = w;
            this.u = u;
        }
    }


    static class UnionFind
    {
        int n ;
        int [] parent ;
        int [] rank ;

        public UnionFind(int n)
        {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i ;
            }
        }

        public int find(int i)
        {
            return parent[i] == i ? i : find(parent[i]);
        }

        public boolean isSameSet(int i , int j)
        {
            return find(i) == find(j);
        }

        public void union(int i , int j)
        {
            int x = find(i);
            int y = find(j);
            if(rank[x] > rank[y])
                parent[y] = x ;
            else
            {
                parent[x] = y ;
                rank[y]++ ;
            }
        }
    }

}
