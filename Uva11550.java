import java.util.* ;
import java.io.* ;
/**
 * 11550 - Demanding Dilemma
 * @author mostafa
 */
public class Uva11550 
{
    static int incidenceMatrix[][];
    static boolean adjMat[][];
    static int N , M ;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while(t-->0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            incidenceMatrix = new int[N][M];
            adjMat = new boolean[N][N];
            for (int i = 0; i < N ; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M ; j++)
                    incidenceMatrix[i][j] = Integer.parseInt(st.nextToken());
            }
            sb.append( canBeIncidenceMatrix() ? "Yes\n" : "No\n" );
        }
        pr.print(sb);
        
        pr.close();
        br.close();
    }
    
    public static boolean canBeIncidenceMatrix()
    {
        for (int i = 0; i < M ; i++) {
            int u = -1 , v = -1 ;
            for (int j = 0; j < N ; j++) {
                if(incidenceMatrix[j][i]==1)
                {
                    if(u==-1)
                        u= j ;
                    else if(v==-1)
                        v= j ;
                    else
                        return false ;
                }
            }
            if(v==-1 || adjMat[u][v])
                return false ;
            adjMat[u][v] = adjMat[v][u] = true ;
        }
        return true ;
    }
}
