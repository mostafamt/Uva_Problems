import java.util.*;
import java.io.*;

/*
 * Uva 1112 - Mice and Maze
 * @ author Mostafa Kamel
 */

public class uva1112
{
    static ArrayList<Edge>[] adjList ;
    static int [] distTo ;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            br.readLine();
            int n = Integer.parseInt(br.readLine());
            int e = Integer.parseInt(br.readLine())-1;
            int t = Integer.parseInt(br.readLine());
            int m = Integer.parseInt(br.readLine());
            distTo = new int[n];
            adjList = (ArrayList<Edge>[]) new ArrayList[n];
            for (int i = 0; i < n; i++)
                adjList[i] = new ArrayList<Edge>();
            while(m-->0)
            {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken())-1;
                int v = Integer.parseInt(st.nextToken())-1;
                int w = Integer.parseInt(st.nextToken());
                adjList[u].add(new Edge(v,w));
            }
            int sum = 0 ;
            for (int i = 0; i < n; i++) {
                Dijkstra(i,e);
                if(distTo[e] <= t) sum++ ;
            }
            sb.append(sum).append(tc == 0 ? "\n":"\n\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static void Dijkstra(int S , int D)
    {
        if(S == D)
        {
            distTo[D] = 0 ;
            return ;
        }
        Arrays.fill(distTo , INF);
        distTo[S] = 0 ;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(S,0));
        while(!pq.isEmpty())
        {
            int v = pq.remove().to ;
            for (Edge e : adjList[v])
            {
                int w = e.to ;
                if(distTo[w] > distTo[v] + e.weight)
                {
                    distTo[w] = distTo[v] + e.weight;
                    pq.add(new Edge(w , distTo[w]));
                }
            }
        }
    }

    static class Edge implements Comparable<Edge>
    {
        int to;
        int weight ;
        public Edge(int u , int w)
        {
            this.to = u ;
            this.weight = w ;
        }

        @Override
        public int compareTo(Edge e)
        {
            return this.weight - e.weight ;
        }
    }

}

