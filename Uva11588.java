import java.util.*;
import java.io.*;
public class Uva11588
{
    static final int max = 26 ;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        for(int k = 1 ; k <= tc ; k++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int [] feq = new int[max];
            int maxFreq = -1 ;
            int num = 0 ;
            for (int i = 0; i < r; i++) {
                String s = br.readLine();
                for (int j = 0; j < c; j++) {
                    feq[s.charAt(j)-'A']++;
                    if(feq[s.charAt(j)-'A'] > maxFreq) {
                        maxFreq = feq[s.charAt(j) - 'A'];
                        num = 1 ;
                    }
                    else if(feq[s.charAt(j)-'A'] == maxFreq)
                        num++ ;
                }
            }
            sb.append("Case "+k+": "+((maxFreq*num)*m + (r*c-maxFreq*num)*n )+"\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
