import java.util.* ;
import java.io.* ;
/**
 * 11906 - Knight in a War Grid
 * @author mostafa
 */
public class Uva11906 
{
    static boolean [][] blocked ;
    static boolean [][] visited ;
    static boolean [][] tmpVisit ;
    static int R , C , M , N  , even , odd ;
    static int [] dx ;
    static int [] dy ;
    
    static void dfs(int i , int j)
    {
        visited[i][j] = true ;
        int sum = 0 ;
        for (int k = 0; k < 8 ; k++) 
        {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y) && !tmpVisit[x][y])
            {
                sum++ ;
                tmpVisit[x][y] = true ;
            }
        }
        for (int k = 0; k < 8 ; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y) && tmpVisit[x][y])
            {
                tmpVisit[x][y] = false ;
            }
        }
        
        if(sum%2==0) even++;
        else         odd++ ;
        
        for (int k = 0; k < 8 ; k++)
            if(isValid(i+dx[k], j+dy[k]))
            {
                if(!visited[i+dx[k]][j+dy[k]])
                    dfs(i+dx[k], j+dy[k]);
            }
    }
    
    static boolean isValid(int i , int j)
    {
        if(i < 0 || j < 0 || i >= R || j >= C || blocked[i][j])
            return false ;
        return true ;
    }
    
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        for(int t = 1 ; t <= tc ; t++)
        {
            R = sc.nextInt();
            C = sc.nextInt();
            M = sc.nextInt();
            N = sc.nextInt();
            int w = sc.nextInt();
            blocked = new boolean[R][C];
            visited = new boolean [R][C];
            tmpVisit = new boolean [R][C];
            dx = new int[]{ M , M , -M , -M , N ,  N , -N , -N };
            dy = new int[]{ N , -N , N , -N , M , -M ,  M , -M };
            while(w-->0)
                blocked[sc.nextInt()][sc.nextInt()] = true ;
            even = odd = 0 ;
            dfs(0, 0);
            sb.append("Case ").append(t).append(": ").append(even).append(" ").append(odd).append("\n");
        }
        pr.print(sb.toString());
        sc.close();
        pr.close();
    }
    
}

