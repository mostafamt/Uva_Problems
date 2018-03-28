import java.util.*;
import java.io.*;

public class Uva10141
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = 1 ;
        while(br.ready())
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int req = Integer.parseInt(st.nextToken()); if(req==0) break;
            int pro = Integer.parseInt(st.nextToken());
            for (int i = 0; i < req; i++) br.readLine();
            String ans = "";
            int initiaReq = -1 ;
            double intialPrice = 0 ;
            for (int i = 0; i < pro; i++) {
                String proName = br.readLine();
                st = new StringTokenizer(br.readLine());
                double price = Double.parseDouble(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                for (int j = 0; j < r; j++) br.readLine();
                if(r>initiaReq  || ( r == initiaReq && price < intialPrice  ))
                {
                    initiaReq = r ;
                    intialPrice = price ;
                    ans = proName ;
                }
            }
            if(tc>1) sb.append("\n");
            sb.append("RFP #").append(tc++).append("\n").append(ans).append("\n");
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }

}
