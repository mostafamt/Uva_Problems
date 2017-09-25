/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author mostafa
 */

import java.util.* ;
import java.io.* ;

public class Uva10773 {
  
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter pr = new PrintWriter( System.out );
        int Case = 1 ;
        long n = Long.parseLong(br.readLine());
        while( n-->0 )
        {
            StringTokenizer st = new StringTokenizer( br.readLine() );
            double d = Double.parseDouble( st.nextToken() );
            double v = Double.parseDouble( st.nextToken() );
            double u = Double.parseDouble( st.nextToken() );
            
            if( v == 0 || u == 0 || v >= u){
                pr.printf( "Case %d: can't determine\n" , Case++ );
                continue ;
            }
            
            double r = Math.sqrt( u*u - v*v );
            double t1 = d / u ;
            double t2 = d / r ;
            
            pr.printf( "Case %d: %.3f\n" , Case++ ,  t2 - t1 );
        }
        
        br.close();
        pr.close();
    }
    
}
