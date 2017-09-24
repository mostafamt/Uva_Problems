/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author mostafa
 */

import java.io.* ;
import java.util.* ;

public class Uva10469 {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter pr = new PrintWriter( System.out );
        String s ;
        while( (s = br.readLine()) != null && ! s.isEmpty() )
        {
            StringTokenizer st = new StringTokenizer(s);
            pr.println( Integer.parseInt(st.nextToken()) ^ Integer.parseInt(st.nextToken()) );
        }
        
        br.close();
        pr.close();
    }
    
}
