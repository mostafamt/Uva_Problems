import java.util.*;
import java.io.*;

public class Uva11631
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        while (n!=0&&m!=0)
        {
            Edge [] edgeList = new Edge[m];
            UF uf = new UF(n+1);
            int minCost = 0 ;
            int maxCost = 0 ;
            for(int i = 0 ; i < m ; i++)
            {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());
                edgeList[i] = new Edge(x,y,z);
                maxCost += z ;
            }
            Arrays.sort(edgeList);
            for(int i = 0 ; i < m ; i++)
            {
                Edge e = edgeList[i];
                int u = e.u ;
                int v = e.v;
                int w = e.weight;
                if(uf.connected(u,v)) continue;
                uf.union(u,v);
                minCost += w ;
            }
            sb.append(maxCost-minCost+"\n");
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static class Edge implements Comparable<Edge>
    {
        int u , v , weight ;
        public Edge(int x , int y , int z)
        {
            u = x ; v = y ; weight = z ;
        }

        public int compareTo(Edge that)
        {
            if     (this.weight > that.weight) return  1 ;
            else if(this.weight < that.weight) return -1 ;
            else                               return  0  ;
        }
    }


    static class UF
    {
        private int [] id ;
        private int count ;

        public UF(int N)
        {
            count = N ;
            id = new int[N];
            for (int i = 0; i < N; i++)
                id[i] = i ;
        }

        public int count()
        {
            return count ;
        }

        public boolean connected(int p , int q)
        {
            return find(p) == find(q);
        }

        public int find(int p)
        {
            return id[p];
        }

        public void union(int p ,int q)
        {
            int pID = find(p);
            int qID = find(q);
            if(qID==pID) return ;
            for (int i = 0; i < id.length; i++)
                if(id[i]==pID) id[i]=qID;
            count-- ;
        }
    }
}

