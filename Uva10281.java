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

public class Uva10281 {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
        PrintWriter pr = new PrintWriter( System.out );
        double speed = 0 ;
        Time time = new Time();
        double distance = 0 ;
            
        String s ;
        while( (s=br.readLine())!= null && !s.isEmpty() )
        {
            StringTokenizer st = new StringTokenizer(s);
            if( st.countTokens() == 2 )
            {
                String [] str = st.nextToken().split(":");
                Time t = new Time( Integer.parseInt(str[2]) , Integer.parseInt(str[1]) , Integer.parseInt(str[0]) );
                //t.minusOne();
                double d = speed * ( t.differenceTimePerHour(time) ) ;
                speed = Integer.parseInt(st.nextToken());
                distance += d ;
                time.setTime(t);
            }
            else
            {
                String [] str = st.nextToken().split(":");
                Time t = new Time(Integer.parseInt(str[2]) , Integer.parseInt(str[1]) , Integer.parseInt(str[0]));
                //t.minusOne();
                double d = (t.differenceTimePerHour(time)) * speed ;
                distance += d ;
                time.setTime(t); ;
                pr.printf( "%s %.2f km\n" , str[0]+":"+str[1]+":"+str[2] , distance );
            }
        }
        
        br.close();
        pr.close();
    }
    
}

class Time
{
    int second ;
    int minute ;
    int hour ;
    
    public Time()
    {
        second = 0 ;
        minute = 0 ;
        hour = 0 ;
    }
    
    public Time( int s , int m , int h )
    {
        this.second = s ;
        this.minute = m ;
        this.hour = h ;
    }
    
    public void setTime( Time t )
    {
        this.second = t.second ;
        this.minute = t.minute ;
        this.hour = t.hour ;
    }
    
    public Time minusOne()
    {
        if( second > 0 )
        {
            second-- ;
        }
        else if( minute > 0 )
        {
            minute-- ;
            second = 59 ;
        }
        else if( hour > 0 )
        {
            hour-- ;
            minute = 59 ;
            second = 59 ;
        }
        return this ;
    }
    
    public double getTimePerHour()
    {
        return  1D*hour + 1D*minute/60 + 1D*second/60/60 ;
    }
    
    public double differenceTimePerHour( Time t )
    {
        return ( this.getTimePerHour() - t.getTimePerHour() ) ;
    }
    
    @Override
    public String toString()
    {
        return ""+hour+":"+minute+":"+second+" " ;
    }
}