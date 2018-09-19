import java.util.*;
import java.io.*;

public class Uva1047
{
    static boolean [] used ;
    static int [] a ;
    static int [][] intersections ;
    static int r ;
    static int c ;
    static int m ;
    static int ans ;
    static boolean [] ans_com ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder("");
        int num = 1 ;

        while( true ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if( r == 0 ){
                break ;
            }
            ans = 0 ;
            ans_com = new boolean[r];
            used = new boolean[r] ;
            a = new int[r];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < r; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            m = Integer.parseInt(br.readLine());
            intersections = new int[m][] ;
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int t = Integer.parseInt(st.nextToken());
                int [] b = new int[t+1];
                for (int j = 0; j < t; j++) {
                    b[j] = Integer.parseInt(st.nextToken()) - 1 ;
                }
                b[t] = Integer.parseInt(st.nextToken());
                intersections[i] = b ;
            }
            // start here
            generate_combination(0,0,0);
            sb.append("Case Number  "+ num++ + '\n');
            sb.append("Number of Customers: " + ans + '\n');
            sb.append("Locations recommended: " );
            boolean first = true ;

            for (int i = 0; i < r; i++) {
                if( ans_com[i] ){
                    sb.append( first ? i+1 : " " + (i+1) );
                    first = false ;
                }
            }
            sb.append("\n\n");
        }

        pr.print(sb.toString());
        br.close();
        pr.close();
    }

    static int get_duplicate()
    {
        int exclusion = 0 ;
        for (int i = 0; i < m; i++) {
            int [] b = intersections[i] ;
            int cnt = 0 ;
            for (int j = 0; j < b.length-1 ; j++) {
                int x = b[j];
                if( used[x] ){
                    cnt++ ;
                }
            }
            if( cnt > 1 ){
                exclusion += ( cnt - 1 ) * b[b.length-1];
            }
        }
        return exclusion ;
    }

    static void generate_combination(int idx , int built , int inclusion)
    {
        if( built == c){
            int exclusion = get_duplicate();
            int y = inclusion - exclusion ;
            if( y > ans ){
                ans = y ;
                ans_com = Arrays.copyOf(used , r);
            }
            return ;
        }
        if( idx == r){
            return ;
        }
        used[idx] = true ;
        generate_combination(idx+1 , built+1 , inclusion + a[idx] );
        used[idx] = false ;
        generate_combination(idx+1 , built , inclusion );
    }

}
