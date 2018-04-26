import java.util.*;
import java.io.*;

public class Uva893 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(true)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int days = Integer.parseInt(st.nextToken());
            int day = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int year = Integer.parseInt(st.nextToken());
            if(days==0&&day==0&&month==0&&year==0)
                break;
            GregorianCalendar cc = new GregorianCalendar(year,month-1,day);
            cc.add(GregorianCalendar.DAY_OF_YEAR , days);
            sb.append(cc.get(GregorianCalendar.DAY_OF_MONTH)+" "+(cc.get(GregorianCalendar.MONTH)+1)+" "+cc.get(GregorianCalendar.YEAR)+"\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
