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

public class Uva11614 {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter pr = new PrintWriter( System.out );
        
        long n = Long.parseLong(br.readLine());
        while(n-->0)
        {
            long x = Long.parseLong(br.readLine());
            // n^2 + n - 2*x = 0
            int a = 1 ;
            int b = 1 ;
            long c = -2*x ;
            
            double r1 = ( -b + Math.sqrt( b*b - 4 * a * c ) ) / ( 2.0 * a ) ;
            double r2 = ( -b - Math.sqrt( b*b - 4 * a * c ) ) / ( 2.0 * a ) ;
            
            pr.println( Long.max((long) r1 , (long) r2 ) );
        }
        pr.close();
        br.close();
    }
    
}
