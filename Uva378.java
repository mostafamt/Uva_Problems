import java.util.*;
import java.io.*;

public class Uva378
{
    static final int EPS = (int)1e-9 ;

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder("INTERSECTING LINES OUTPUT\n");
        int tc = sc.nextInt();
        while(tc-->0)
        {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            int x3 = sc.nextInt();
            int y3 = sc.nextInt();
            int x4 = sc.nextInt();
            int y4 = sc.nextInt();
            Line l1 = new Line(new Point(x1,y1),new Point(x2,y2));
            Line l2 = new Line(new Point(x3,y3),new Point(x4,y4));
            if(l1.areSame(l2))
                sb.append("LINE\n");
            else if(l1.areParallel(l2))
                sb.append("NONE\n");
            else
            {
                Point p = l1.intersect(l2);
                String str = String.format("%.2f %.2f" , p.x , p.y);
                sb.append("POINT ").append(str).append("\n");
            }
        }
        sb.append("END OF OUTPUT\n");
        pr.print(sb.toString());
        pr.close();
    }


    static class Point
    {
        double x , y ;
        public Point(double _x , double _y){x=_x;y=_y;}
        public boolean betweenPoints(Point p1 , Point p2)
        {
            if (x + EPS >= Math.min(p1.x, p2.x) && x <= Math.max(p1.x, p2.x) + EPS &&
                    y + EPS >= Math.min(p1.y, p2.y) && y <= Math.max(p1.y, p2.y) + EPS)
                return true;
            return false ;
        }
    }

    static class Line
    {
        double a , b , c ;
        public Line(Point p1 , Point p2)
        {
            if(p1.x==p2.x)
            {
                a = 1.0 ; b = 0.0 ; c = -p1.x ;
            }
            else
            {
                double slope = (double) (p1.y-p2.y)/(p1.x-p2.x);
                a = -slope ;
                b = 1.0 ;
                c = slope*p1.x - p1.y ;
            }
        }
        boolean areParallel(Line l)
        {
            return (Math.abs(a-l.a)<=EPS && Math.abs(b-l.b)<=EPS);
        }

        boolean areSame(Line l)
        {
            return areParallel(l)&&Math.abs(c-l.c)<=EPS ;
        }

        Point intersect(Line l)
        {
            if(areParallel(l)) return null ;
            Point p = new Point(0,0);
            p.x = (l.b*c - b*l.c) / (l.a*b-a*l.b);
            if(Math.abs(b)>EPS) p.y = -(a*p.x+c);
            else                p.y = -(l.a*p.x+l.c);
            return p ;
        }
    }


}
