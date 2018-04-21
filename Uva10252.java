import java.util.*;
import java.io.*;

public class Uva10252 {
    static final int max = 26 ;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while (br.ready()) {
            int [] a = new int[max];
            int [] b = new int[max];
            String str1 = br.readLine();
            String str2 = br.readLine();
            int m = Integer.max(str1.length(), str2.length());
            for (int i = 0; i < m; i++) {
                if (i < str1.length())
                    a[str1.charAt(i)-'a']++;
                if (i < str2.length())
                    b[str2.charAt(i)-'a']++;
            }
            for (int i = 0; i < max; i++)
                if(a[i]>0&&b[i]>0)
                    for (int j = 0; j < Integer.min(a[i],b[i]); j++)
                        sb.append((char)(i+'a'));
                sb.append("\n");
        }
            pr.print(sb.toString());
            pr.close();
            br.close();
    }
}
