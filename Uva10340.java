import java.util.*;
import java.io.*;
public class Uva10340 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(br.ready()){
            boolean status = true ;
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s1 = st.nextToken();
            String s2 = st.nextToken();
            int i1  = 0 ,i2 = 0 ;
            while(i1<s1.length() && i2<s2.length()) {
                if (s1.charAt(i1) == s2.charAt(i2)) i1++;
                i2++;
            }
            if(i1 != s1.length()) status = false ;
            sb.append( status ? "Yes\n" :"No\n" );
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
