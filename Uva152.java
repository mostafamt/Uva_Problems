import java.util.*;
import java.io.*;

public class Uva152
{

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        Point [] points = new Point[5001];
        int [] ans = new int[10];
        int length = 0 ;
        while(true)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            if(x==0&&y==0&&z==0) break;
            points[length++] = new Point(x,y,z);
        }
        for (int i = 0; i < length; i++)
        {
            int min = Integer.MAX_VALUE ;
            for (int k = 0; k < length; k++)
            {
                if(i==k) continue;
                Point p1 = points[i];
                Point p2 = points[k];
                int d = points[i].getDest(points[k]);
                min = Integer.min(min,d);
            }
            if(min<=9) ans[min]++ ;
        }
        for (int i : ans) pr.printf("%4d",i);
        pr.print("\n");
        sc.close();
        pr.close();
    }


    static class Point
    {
        int x , y , z ;
        public Point(int _x ,int _y , int _z){x=_x;y=_y;z=_z;}
        int getDest(Point other)
        {
            return (int)Math.sqrt(Math.pow(x-other.x,2)+Math.pow(y-other.y,2)+Math.pow(z-other.z,2));
        }
    }

}
