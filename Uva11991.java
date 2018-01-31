import java.util.* ;
import java.io.* ;

/**
 *
 * @author mostafa kamel
 */

public class Uva11991 
{
    static final int N = (int)(1e6 + 2);
    
    public static void main(String[] args) throws IOException 
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        while(sc.hasNext())
        {
            int n = sc.nextInt();
            int m = sc.nextInt();
            ArrayList<Integer> [] adjList = new ArrayList[N];
            for (int i = 0; i < N ; i++)
                adjList[i] = new ArrayList();
            for (int i = 0; i < n ; i++)
                adjList[sc.nextInt()].add(i+1);
            for (int i = 0; i < m ; i++)
            {
                int k = sc.nextInt();
                int v = sc.nextInt();
                if(adjList[v].size() < k)
                    pr.println(0);
                else
                    pr.println(adjList[v].get(k-1));
            }
        }
        sc.close();
        pr.close();
    }

}
