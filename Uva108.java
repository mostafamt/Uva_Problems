import java.util.*;
import java.io.*;

public class Uva108 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        int[][] a = new int[N][N];
        int i = 0, j = 0;
        while (br.ready()) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                if (j == N) {
                    i++;
                    j = 0;
                }
                a[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        int max = Integer.MIN_VALUE;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                int m = maxSubRectangle(a,N,i,j);
//                System.out.println("m = " + m);
                max = Integer.max(max,m);
            }
        }
        pr.println(max);
        pr.close();
        br.close();
    }

    static int maxSubRectangle(final int[][] rec, int N, int i, int j)
    {
        int max = Integer.MIN_VALUE ;

        int [][] memo = new int[N][N];

        for(int y = i ; y < N ; y++)
        {
            for(int x = j ; x < N ; x++)
            {
                memo[y][x] = rec[y][x] ;

                if( y == i && x == j)
                    memo[y][x] = memo[y][x] ;
                else if( y == i )
                    memo[y][x] += memo[y][x-1] ;
                else if( x == j )
                    memo[y][x] += memo[y-1][x];
                else
                    memo[y][x] += memo[y][x-1] + memo[y-1][x] - memo[y-1][x-1];

                max = Integer.max(memo[y][x] , max) ;
            }
        }

        return max ;
    }

}
