import java.util.*;
import java.io.*;

public class Uva920
{
    static final double EPS = (int)1e-9 ;

    public static void main(String[] args) throws IOException
    {
//        Scanner sc = new Scanner(new File("in.txt"));
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        int tc = sc.nextInt();
        while(tc-->0)
        {
            int n = sc.nextInt();
            Point [] points = new Point[n];
            for (int i = 0; i < n; i++)
                points[i] = new Point(sc.nextInt() , sc.nextInt());
            Arrays.sort(points);
            double sum = 0 , max = 0 ;
            for (int i = 1; i < n; i++) {
                if(points[i].y > max)
                {
                    sum += new Point(new Line(points[i],points[i-1]).getX(max) , max).dist(points[i]);
                    max = points[i].y ;
                }
            }
            pr.printf("%.2f\n" , sum);
        }
        pr.close();
        sc.close();
    }

    static class Point implements Comparable<Point>
    {
        double x , y ;
        public Point(double _x , double _y){x=_x;y=_y;}

        public double dist(Point other)
        {
            return Math.sqrt( (this.x-other.x)*(this.x-other.x) + (this.y-other.y)*(this.y-other.y) );
        }

        public int compareTo(Point other)
        {
            if(this.x!=other.x) return (int)(other.x - this.x) ;
            else                return (int)(other.y - this.y) ;
        }
    }

    static class Line
    {
        double a , b , c ;
        Line(Point p , Point q)
        {
            if(Math.abs(q.x - p.x) < EPS)
            {
                a = 1.0 ;
                b = 0.0 ;
                c = -p.x ;
            }
            else
            {
                a = (p.y - q.y) / (q.x - p.x) ;
                b = 1.0 ;
                c = - a * p.x - p.y ;
            }
        }
        boolean isHorizontal()
        {
            return Math.abs(a) < EPS ;
        }

        double getX(double y)
        {
            return  ( -c-b*y ) / a  ;
        }
    }

}
