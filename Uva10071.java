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

public class Uva10071 
{
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter out = new PrintWriter(System.out);
        
        String s ;
        while( !(s = br.readLine()).isEmpty() )
        {
            StringTokenizer st = new StringTokenizer(s);
            int v = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            int d = v * t ;
            out.println(2*d);
        }
        
        br.close();
        out.close();
    }
    
}
