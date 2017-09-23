
import java.util.*;
import java.io.*;
 
public class Uva11631
{
    public static void main (String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s ;
        while( (s = br.readLine()) != null && !s.isEmpty() )
        {
            StringTokenizer st = new StringTokenizer(s);
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if( n == 0 && m == 0 )
                return ;
            
            Kruskal graph = new Kruskal(n, m);
            int totalWeight = 0 ;
            int index = 0 ;
            while( m-->0 )
            {
                StringTokenizer str = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(str.nextToken());
                int v = Integer.parseInt(str.nextToken());
                int w = Integer.parseInt(str.nextToken());
                graph.edge[index].src = u ;
                graph.edge[index].dest = v ;
                graph.edge[index].weight = w ;
                totalWeight += w ;
                index ++ ;
            }
            int w = graph.KruskalMST();
            System.out.println( totalWeight -  w );
            
        }
        out.close();
        br.close();
    }
    
    
}


class Kruskal
{
    // A class to represent a graph edge
    class Edge implements Comparable<Edge>
    {
        int src, dest, weight;
 
        // Comparator function used for sorting edges based on
        // their weight
        public int compareTo(Edge compareEdge)
        {
            return this.weight-compareEdge.weight;
        }
    }
 
    // A class to represent a subset for union-find
    class subset
    {
        int parent, rank;
    }
 
    int V, E;    // V-> no. of vertices & E->no.of edges
    Edge edge[]; // collection of all edges
 
    // Creates a graph with V vertices and E edges
    public Kruskal(int v, int e)
    {
        V = v;
        E = e;
        edge = new Edge[E];
        for (int i=0; i<e; ++i)
            edge[i] = new Edge();
    }
 
    // A utility function to find set of an element i
    // (uses path compression technique)
    int find(subset subsets[], int i)
    {
        // find root and make root as parent of i (path compression)
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
 
        return subsets[i].parent;
    }
 
    // A function that does union of two sets of x and y
    // (uses union by rank)
    void Union(subset subsets[], int x, int y)
    {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
 
        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
 
        // If ranks are same, then make one as root and increment
        // its rank by one
        else
        {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
 
    // The main function to construct MST using Kruskal's algorithm
    int KruskalMST()
    {
        Edge result[] = new Edge[V];  // Tnis will store the resultant MST
        int e = 0;  // An index variable, used for result[]
        int i = 0;  // An index variable, used for sorted edges
        for (i=0; i<V; ++i)
            result[i] = new Edge();
 
        // Step 1:  Sort all the edges in non-decreasing order of their
        // weight.  If we are not allowed to change the given graph, we
        // can create a copy of array of edges
        Arrays.sort(edge);
 
        // Allocate memory for creating V ssubsets
        subset subsets[] = new subset[V];
        for(i=0; i<V; ++i)
            subsets[i]=new subset();
 
        // Create V subsets with single elements
        for (int v = 0; v < V; ++v)
        {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
 
        i = 0;  // Index used to pick next edge
 
        // Number of edges to be taken is equal to V-1
        while (e < V - 1)
        {
            // Step 2: Pick the smallest edge. And increment the index
            // for next iteration
            Edge next_edge = new Edge();
            next_edge = edge[i++];
 
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
 
            // If including this edge does't cause cycle, include it
            // in result and increment the index of result for next edge
            if (x != y)
            {
                result[e++] = next_edge;
                Union(subsets, x, y);
            }
            // Else discard the next_edge
        }
 
        // print the contents of result[] to display the built MST
        int weight = 0 ;
        for (i = 0; i < e; ++i)
            weight += result[i].weight ;
        return weight ;
    }
 
    
}