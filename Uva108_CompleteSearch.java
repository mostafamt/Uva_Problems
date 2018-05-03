import java.util.*;
import java.io.*;

public class Uva108_CompleteSearch {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        int [][] a = new int[N][N];
        int i = 0 , j = 0 ;
        while (br.ready()){
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()){
                if(j==N){
                    i++ ;
                    j = 0 ;
                }
                a[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        int max = Integer.MIN_VALUE ;
        for(i = 1 ; i <= N ; i++)
        {
            for(j = 1 ; j <= N ; j++)
            {
                int m = maxSubRectangleSum(a,N,i,j);
                max = Integer.max(max,m);
            }
        }
        pr.println(max);
        pr.close();
        br.close();

    }

    static int maxSubRectangleSum(final int [][] rectangle , int N , int n , int m)
    {
        int max = Integer.MIN_VALUE ;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if( i + n <= N && j + m <= N )
                {
                    int sum = 0 ;
                    for(int y = i ; y < i+n ; y++)
                    {
                        for(int x = j ; x < j+m ; x++)
                        {
                            sum += rectangle[y][x];
                        }
                    }
                    max = Integer.max(max,sum);
                }
            }
        }
        return max ;
    }
}
