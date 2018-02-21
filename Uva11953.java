import java.util.* ;
import java.io.*;
/**
 * Uva 11953 - Battleships
 * @author mostafa
 */
public class Uva11953 
{
    static char [][] Grid ;
    static int N ;
    static int [] dx = { 1 , -1 , 0 , 0 };
    static int [] dy = { 0 , 0 , 1 , -1 };
    
    static boolean dfs(int i , int j)
    {
        boolean status = Grid[i][j] == 'x' ;
        Grid[i][j] = '.' ;
        for (int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isvalid(x, y))
                status = dfs(x, y) || status ;
        }
        return status ;
    }
    
    static boolean isvalid(int i , int j)
    {
        if(i<0 || j < 0 || i >= N || j >= N || Grid[i][j] == '.' )
            return false ;
        return true ;
    }
    
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        for(int k = 1 ; k <= tc ; k++)
        {
            N = sc.nextInt();
            Grid = new char[N][N];
            int sum = 0 ;
            for(int j = 0 ; j < N ; j++)
                Grid[j] = sc.next().toCharArray();
            for(int i = 0; i < N ; i++) 
                for (int j = 0; j < N ; j++) 
                    if(Grid[i][j] != '.' && dfs(i, j))
                        sum++ ;
            sb.append("Case ").append(k).append(": ").append(sum).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        sc.close();
    }
    
}
