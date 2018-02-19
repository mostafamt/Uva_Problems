import java.util.* ;
import java.io.* ;
/**
 * 469 - Wetlands of Florida
 * @author mostafa
 */
public class Uva469 
{
    static char [][] Grid ; 
    static int N , M ;
    static int [] dx = { 1,1,1,  0,0,  -1,-1,-1};        // Flood Fill
    static int [] dy = { 1,0,-1, 1,-1, 1,0,-1};
    static boolean [][] visited ;
    
    static int dfs(int i , int j)
    {
        visited[i][j] = true ;
        int sum = 1 ;
        for (int k = 0; k < 8 ; k++) {
            if(isValid(i+dx[k], j+dy[k]))
                sum += dfs(i+dx[k], j+dy[k]);
        }
        return sum ;
    }
    
    static boolean isValid(int i , int j)
    {
        if(i<0 || j < 0 || i >= N || j >= M || visited[i][j] || Grid[i][j] == 'L')
            return false ;
        return true ;
    }
    
    
    
    
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        Grid = new char[100][100];
        int tc = Integer.parseInt(br.readLine());
        br.readLine();
        while(tc-->0)
        {
            N = 0 ;
            String x = br.readLine();
            M = x.length() ;
            Grid[N++] = x.toCharArray();
            String str ;
            while( (str = br.readLine()).length() == M )
               Grid[N++] = str.toCharArray();
            visited = new boolean[N][M];
            StringTokenizer st = new StringTokenizer(str);
            int i = Integer.parseInt(st.nextToken())-1 ;
            int j = Integer.parseInt(st.nextToken())-1 ;
            sb.append(dfs(i, j)).append("\n");
            while( br.ready() &&  ( str = br.readLine() ).length() > 0 )
            {
                visited = new boolean [N][M];
                st = new StringTokenizer(str);
                i = Integer.parseInt(st.nextToken())-1 ;
                j = Integer.parseInt(st.nextToken())-1 ;
                sb.append(dfs(i, j)).append("\n");
            }
            if(tc > 0)
                sb.append("\n");
        }
        pr.print(sb.toString());
        
        pr.close();
        br.close();
    }
    
}
