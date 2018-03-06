import java.util.*;
import java.io.*;

/*
 * Uva 10986 - Sending email
 * @ author Mostafa Kamel
 */
public class Uva10986
{
    static ArrayList<Edge> [] adjList ;
    static long [] distTo;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        for (int T = 1 ; T <= tc; T++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            distTo = new long[n];
            adjList = (ArrayList<Edge>[]) new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i] = new ArrayList<Edge>();
            for (int i = 0; i < m; i++)
            {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                adjList[u].add(new Edge(v,w));
                adjList[v].add(new Edge(u,w));
            }
            Dijikstra(s,d);

            sb.append("Case #").append(T).append(": ").append(distTo[d] == INF ? "unreachable" : distTo[d]).append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static void Dijikstra(int S , int T)
    {
        Arrays.fill(distTo , INF);
        distTo[S] = 0 ;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(S,0));
        while(!pq.isEmpty())
        {
            Edge pair = pq.remove();
            int v = pair.to;
            for (Edge e : adjList[v])
            {
                int w = e.to;
                if( distTo[w] > distTo[v] + e.weight )
                {
                    distTo[w] = distTo[v] + e.weight ;
                    pq.add(new Edge(w, distTo[w]));
                }
            }
        }
    }

    static class Edge implements Comparable<Edge>
    {
        int to;
        long weight ;
        public Edge(int to , long w)
        {
            this.to = to ;
            weight = w ;
        }

        public int compareTo(Edge d)
        {
            return (int)(this.weight - d.weight) ;
        }
    }
}