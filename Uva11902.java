import java.util.* ;
import java.io.* ;

/**
 *
 * @author mostafa
 */
public class Uva11902 
{
    static ArrayList<Integer> [] adjList ;
    static boolean [] visited ;
    static int N ;
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        for (int c = 0; c < tc ; c++)
        {
            N = sc.nextInt();
            adjList = new ArrayList[N];
            visited = new boolean[N];
            for (int i = 0; i < N ; i++)
                adjList[i] = new ArrayList();
            for (int i = 0; i < N ; i++)
                for (int j = 0; j < N ; j++)
                    if(sc.nextInt() == 1)
                        adjList[i].add(j);
            sb.append("Case "+(c+1)+":\n");
            appendLine(N, sb);
            for (int i = 0; i < N ; i++) 
            {
                sb.append("|");
                for (int j = 0; j < N ; j++) 
                {
                    if(DFS_Check_Connectivity(j))
                    {
                        sb.append( DFS(i, j) ? "Y|" : "N|" );
                    }
                    else
                        sb.append("N|");
                    
                }
                sb.append("\n");
                appendLine(N, sb);
            }
        }
        pr.print(sb);
            
        pr.close();
        sc.close();
    }
    
    public static boolean DFS_Check_Connectivity(int node)
    {
        if(node==0)
            return true ;
        Arrays.fill(visited, false);
        Stack<Integer> stack = new Stack();
        stack.push(0);
        visited[0] = true ;
        while(!stack.isEmpty())
        {
            int x = getUnvisitedVertex(stack.peek());
            if(x==node)
                return true ;
            else if( x == -1 )
                stack.pop();
            else
            {
                stack.push(x);
                visited[x] = true ;
            }
        }
        return false ;
    }
    
    
    public static boolean DFS(int dominator , int target )
    {
        if( dominator == target || dominator == 0)
            return true ;
        if( target == 0 )
            return false ;
        Arrays.fill(visited, false);
        visited[dominator] = true ;
        Stack<Integer> stack = new Stack();
        stack.push(0);
        visited[0] = true ;
        while(!stack.isEmpty())
        {
            int x = getUnvisitedVertex(stack.peek());
            if( x == target )
                return false ;
            else if( x == -1 )
                stack.pop();
            else
            {
                stack.push(x);
                visited[x] = true ;
            }
        }
        return true ;
    }
    
    public static int getUnvisitedVertex(int node)
    {
        int size = adjList[node].size();
        for (int i = 0; i < size ; i++) {
            int x = adjList[node].get(i);
            if(!visited[x])
                return x ;
        }
        return -1 ;
    }
    
    public static void appendLine(int n , StringBuilder sb)
    {
        for (int i = 0; i < 2*n+1 ; i++) {
            if(i==0||i==2*n)
                sb.append("+");
            else
                sb.append("-");
        }
        sb.append("\n");
    }
    
}
