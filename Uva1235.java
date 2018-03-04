import java.util.*;
import java.io.*;

/*
 * 1235 - Anti Brute Force Lock
 * @ author Mostafa Kamel
 */

public class Uva1235
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-->0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int [] arr = new int[n];
            for(int i = 0 ; i < n ; i++)
                arr[i] = Integer.parseInt(st.nextToken());
            int mw = 0 ;
            int min = 16 ;
            for (int i = 0; i < n; i++)
                min = Integer.min(min, getWeight(0,arr[i]) );
            mw += min ;
            int size = n*(n-1)/2 ;
            Edge [] edgeList = new Edge[size];
            int index = 0 ;
            for (int i = 0; i < n ; i++) {
                for (int j = i+1 ; j < n ; j++) {
                    edgeList[index++] = new Edge(i,j,getWeight(arr[i],arr[j]));
                }
            }
            Arrays.sort(edgeList);
            UF uf = new UF(n);
            for (int i = 0; i < edgeList.length; i++) {
                int u = edgeList[i].u;
                int v = edgeList[i].v;
                int w = edgeList[i].w ;
                if(uf.connected(u,v)) continue;
                mw += w ;
                uf.union(u,v);
            }
            sb.append(mw).append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static int getWeight(int m , int n)
    {
        int w = 0 ;
        for (int i = 0; i < 4; i++ , n /= 10 , m /=10) {
            int d = Math.abs(m%10-n%10);
            w += Integer.min(d,10-d);
        }
        return w ;
    }

    static class Edge implements Comparable<Edge>
    {
        int u , v ,w ;
        public Edge(int x , int y , int z)
        {
            u = x ;
            v = y ;
            w = z ;
        }
        @Override
        public int compareTo(Edge e)
        {
            return this.w - e.w ;
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
