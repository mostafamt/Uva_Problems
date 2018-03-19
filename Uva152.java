/*
 * Solution Description : 1) you can treat the line segment as a line with an infinite length .
 *                        2) find the intersection point between the line and each line of rectangle
 *                        3) if the intersection point inside the rectangle and between the line , print 'T'
 *                        4) else print 'F'
 *                        5) take care of special cases like : if the two points of the line is inside the rectangle ...etc .
 *                        6) In this special case , the intersection point is inside the rectangle but not between the line .
 */

import java.util.*;
import java.io.*;

public class Uva152
{
    static final int EPS = (int)1e-9 ;
    static final int EDGES = 4 ;
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = sc.nextInt();
        while(tc-->0)
        {
            Point p1 = new Point(sc.nextInt(),sc.nextInt());
            Point p2 = new Point(sc.nextInt(),sc.nextInt());
            Line l1 = new Line(p1,p2);
            Point [] points = new Point[EDGES];
            points[0] = new Point(sc.nextInt(),sc.nextInt());
            points[2] = new Point(sc.nextInt(),sc.nextInt());
            points[1] = new Point(points[2].x , points[0].y);
            points[3] = new Point(points[0].x , points[2].y);
            boolean areIntersect = false ;
            if(p1.betweenPoints(points[0],points[2]) || p2.betweenPoints(points[0],points[2]))
                areIntersect = true ;
            else
            {
                for (int i = 0; i < EDGES && areIntersect == false; i++)
                {
                    Line l = new Line(points[i], points[(i + 1) % 4]);
                    if(l.areParallel(l1))
                    {
                        if(!l.areSame(l1)) continue;
                        if(points[i].betweenPoints(p1,p2)&&points[(i+1)%4].betweenPoints(p1,p2))
                            areIntersect = true ;
                    }
                    else {
                        Point p = l.intersect(l1);
                        if (p == null) continue;
                        if(p.betweenPoints(p1,p2)&&p.betweenPoints(points[i],points[(i+1)%4]))
                            areIntersect = true ;
                    }
                }
            }
            sb.append(areIntersect?"T\n":"F\n");
        }
        pr.print(sb.toString());
        pr.close();
        sc.close();
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
