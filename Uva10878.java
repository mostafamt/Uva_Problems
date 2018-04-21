import java.text.DecimalFormat;
import java.util.*;
import java.io.*;

public class Uva10878 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(br.ready()){
            String binary = "";
            String s = br.readLine();
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i)=='o')
                    binary+='1';
                else if(s.charAt(i)==' ')
                    binary+='0';
            }
            if(!binary.isEmpty())
                sb.append((char)Integer.parseInt(binary,2));
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
