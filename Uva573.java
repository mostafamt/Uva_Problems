import java.util.*;
import java.io.*;

public class Uva573
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(br.ready())
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double height = Integer.parseInt(st.nextToken());if(height==0)break;
            double distanceClimbed = Integer.parseInt(st.nextToken());
            int distanceSlid = Integer.parseInt(st.nextToken());
            int factor = Integer.parseInt(st.nextToken());
            double decreaseFactor = (double) factor / 100 * distanceClimbed ;
            boolean status = false ;
            int day = 0 ;
            double initialHeight = 0 ;
            while(initialHeight <= height && initialHeight >= 0)
            {
                day++ ;
                initialHeight += distanceClimbed ;
                if(initialHeight>height)
                {
                    status = true ;
                    break;
                }
                initialHeight -= distanceSlid ;
                if(distanceClimbed>0) distanceClimbed -= decreaseFactor;
                if(distanceClimbed<0) distanceClimbed = 0 ;
            }
            sb.append(status ? "success":"failure").append(" on day ").append(day).append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
