import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva748
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while(br.ready()){
            StringTokenizer st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            BigDecimal bd = new BigDecimal(Double.toString(x));
            String s = bd.pow(y).toString();
            String front = ""  ;
            int front_idx = -1 ;
            for(int i = 0 ; i < s.length() ; i++){
                if( s.charAt(i) == '.' ){
                    front = s.substring(0,i);
                    front_idx = i ;
                } else if( s.charAt(i) == 'E' ){
                    String end = s.substring(front_idx+1,i);
                    int num = Integer.parseInt( s.substring(i+2,s.length()) );
                    s = "." ;
                    for (int j = 0; j < num-front.length() ; j++) {
                        s += '0' ;
                    }
                    s += front+end ;
                }
            }
            sb.append(s).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
