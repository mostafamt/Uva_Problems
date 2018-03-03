import java.util.*;
import java.io.*;

/*
 * Uva 11733 - Airports
 * @ author Mostafa Kamel
 */
public class Uva11733
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        for(int t = 1 ; t <= tc ; t++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            Edge [] edgeList = new Edge[m];
            for(int i = 0 ; i < m ; i++)
            {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken())-1;
                int y = Integer.parseInt(st.nextToken())-1;
                int z = Integer.parseInt(st.nextToken());
                edgeList[i] = new Edge(x,y,z);
            }
            Arrays.sort(edgeList);
            int airports = n ;
            int ans = 0 ;
            UnionFind uf = new UnionFind(n);
            for (int i = 0; i < m; i++) {
                int u = edgeList[i].u;
                int v = edgeList[i].v;
                int w = edgeList[i].weight;
                if(w>=a) break;
                if(!uf.isSameSet(u,v))
                {
                    uf.union(u,v);
                    ans += w ;
                    airports-- ;
                }
            }
            ans += airports * a ;
            sb.append("Case ").append("#").append(t).append(": ").append(ans+" ").append(airports+"\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static class Edge implements Comparable<Edge>
    {
        int u , v , weight ;
        public Edge(int x,int y , int z)
        {
            u = x ;
            v = y ;
            weight = z ;
        }
        @Override
        public int compareTo(Edge that)
        {
            if     (this.weight > that.weight) return  1 ;
            else if(this.weight < that.weight) return -1 ;
            else                               return  0  ;
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
