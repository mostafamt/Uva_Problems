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

public class Uva10055 
{
    
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter out = new PrintWriter(System.out);
        
        String s ;
        while( (s = br.readLine())!= null && !s.isEmpty() )
        {
            StringTokenizer st = new StringTokenizer(s);
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            
            out.println( (long)Math.abs(a-b) );
        }
        
        br.close();
        out.close();
    }
    
}
