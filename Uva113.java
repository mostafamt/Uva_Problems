import java.util.*;
import java.io.*;

public class Uva113
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        while (sc.hasNext())
        {
            double n = sc.nextDouble();
            double p = sc.nextDouble();
            pr.println( (int)Math.round(Math.exp(1/n*Math.log(p))  ));
        }
        sc.close();
        pr.close();
    }

}
