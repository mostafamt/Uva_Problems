
import java.io.* ;
import java.util.* ;

public class Uva469 {
    
    static char [][] adjMat = new char[101][101] ;
    static boolean [][] visited = new boolean[101][101];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n ; i++) {
            if(  i==0)
                br.readLine();
            String s ;
            int index = 1 ;
            int a = 0 , b = 0 ;
            while( (s = br.readLine()) != null && !s.isEmpty() )
            {
                if(s.charAt(0) == 'W' || s.charAt(0) == 'L')
                {
                    for (int j = 0; j < s.length() ; j++) {
                        adjMat[index][j+1] = s.charAt(j);
                    }
                }
                else
                {
                    StringTokenizer st = new StringTokenizer(s);
                    a = Integer.parseInt(st.nextToken()) ;
                    b = Integer.parseInt(st.nextToken()) ;
                    out.println( dfs(a, b) );
                    for (int j = 0; j < 101 ; j++) {
                        for (int k = 0; k < 101 ; k++) {
                            visited[j][k] = false ;
                        }
                    }
                }
                index ++ ;
            }
            
            
            
            for (int j = 0; j < 101 ; j++) {
                for (int k = 0; k < 101 ; k++) {
                    adjMat[j][k] = 'L' ;
                }
                
            }
            if( i != n-1 )
                out.println();
        }
        out.close();
        br.close();
    }
    
    public static int dfs(int a , int b)
    {
        int sum = 1 ;
        visited[a][b] = true ;
        Deque<Point> stack = new LinkedList<>();
        stack.push( new Point(a, b) );
        while( !stack.isEmpty() )
        {
            Point p = getNeighbours( stack.peek() );
            if( p == null )
                stack.pop();
            else
            {
                sum++ ;
                stack.push( p );
                visited[p.x][p.y] = true ;
            }
        }
        return sum ;
    }
    
    public static Point getNeighbours( Point p )
    {
        int x = p.x ;
        int y = p.y ;
        if( adjMat[x][y+1] == 'W' && !visited[x][y+1] )
            return new Point(x, y+1);
        else if( adjMat[x][y-1] == 'W' && !visited[x][y-1] )
            return new Point(x, y-1);
        else if( adjMat[x+1][y] == 'W' && !visited[x+1][y] )
            return new Point(x+1,y);
        else if( adjMat[x-1][y] == 'W' && !visited[x-1][y] )
            return new Point(x-1, y);
        else if( adjMat[x+1][y+1] == 'W' && !visited[x+1][y+1] )
            return new Point(x+1,y+1);
        else if( adjMat[x-1][y-1] == 'W' && !visited[x-1][y-1] )
            return new Point(x-1,y-1);
        else if( adjMat[x+1][y-1] == 'W' && !visited[x+1][y-1] )
            return new Point(x+1,y-1);
        else if( adjMat[x-1][y+1] == 'W' && !visited[x-1][y+1] )
            return new Point(x-1, y+1);
        else
            return null ;
    }
}

class Point
{
    public int x , y ;
    public Point(int x , int y)
    {
        this.x = x ;
        this.y = y ;
    }
}

