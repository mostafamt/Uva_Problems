import java.util.* ;
import java.io.* ;
/**
 * 12442 - Forwarding Emails
 * @author mostafa
 *  Descroption : in this problem , it must have cycles so every vertex have one neighbour
 *                if you are going to count every node , you getting TLE .
 *                you might use a vector to store cycle vertex values 
 *                so you don't need to calculate it again and again ..
 *                if you use recursion DFS method , it helps you a lot .
 */
public class Uva12442 
{
    static int [] graph ;
    static int [] lengths ;
    static boolean [] visited ;
    static int N ;
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        for (int i = 1 ; i <= tc ; i++) 
        {
            N = sc.nextInt()+1 ;
            graph = new int[N];
            visited = new boolean[N];
            lengths = new int[N];             // you have to save lengths , otherwise you'r going to get TLE
            Arrays.fill(lengths, -1);         // (Time Limit Exceeded)
            for(int k = 1 ; k < N ; k++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                graph[u] = v;
            }
            int maxLength = Integer.MIN_VALUE ;
            int vertex = -1 ;
            for(int k = 1 ; k < N ; k++)    // start from down to top , otherwise will get WA(Wrong Answer)
            {                               // it stated in problem "If there is more than one correct answer,"
                if(lengths[k]==-1)          // ", output the smallest number"
                    DFS(k);
                if(lengths[k]>maxLength)
                {
                    maxLength = lengths[k];
                    vertex = k ;
                }
            }
            sb.append("Case "+i+": "+vertex+"\n");
        }
        pr.print(sb.toString());
        pr.close();
        sc.close();
    }
    
    // special DFS Using Recursion
    public static int DFS(int vertex)
    {
        int sum = 0 ;
        visited[vertex] = true ;
        if(!visited[graph[vertex]])
            sum += 1 + DFS(graph[vertex]);
        visited[vertex] = false ;          // clean visited array with default values(false)
        return lengths[vertex] = sum ;
    }
    
}
