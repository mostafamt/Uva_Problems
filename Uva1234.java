import java.util.*;
import java.io.*;

/*
 * Uva 1234 - RACING
 * @ author Mostafa Kamel
 */
public class Uva1234
{
    static int N ;
    static int M ;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            Edge [] edgeList = new Edge[M];
            int maxWeight = 0 ;
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken())-1;
                int v = Integer.parseInt(st.nextToken())-1;
                int w = Integer.parseInt(st.nextToken());
                edgeList[i] = new Edge(u,v,w);
                maxWeight += w ;
            }
            sb.append(maxWeight-kruskalMst(edgeList)).append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static int kruskalMst( Edge [] edgesList )
    {
        Arrays.sort(edgesList);
        UnionFind uf = new UnionFind(N);
        int weight = 0 ;
        for (int i = 0; i < M ; i++) {
            int u = edgesList[i].u;
            int v = edgesList[i].v;
            int w = edgesList[i].w;
            if(uf.isSameSet(u,v)) continue;
            weight += w ;
            uf.union(u,v);
        }
        return weight ;
    }

    static class Edge implements Comparable<Edge>
    {
        int u , v , w ;
        public Edge(int x,int y,int z){u=x;v=y;w=z;}
        @Override
        public int compareTo(Edge e)
        {   return e.w - this.w ;   }
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
