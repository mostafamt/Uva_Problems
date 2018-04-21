import java.util.*;
import java.io.*;
public class Uva409 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int c = 1 ;
        while(br.ready()){
            if(c!=1)
                sb.append("\n");
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            String [] keywords = new String[k];
            for (int i = 0; i < k; i++) {
                keywords[i] = br.readLine();
            }
            ArrayList<String> list = new ArrayList<>();
            int max = 0 ;
            while(e-->0){
                String s = br.readLine();
                s.replaceAll(" ","?");
                String [] a = s.split("[^a-zA-Z]");
                int sum = 0 ;
                for (int i = 0; i < a.length; i++) {
                    for (int j = 0; j < k; j++) {
                        if(a[i].toLowerCase().matches(keywords[j].toLowerCase())) {
                            sum++;
                            break;
                        }
                    }
                }
                if(sum>max){
                    max = sum ;
                    list.clear();
                    list.add(s);
                }
                else if(sum == max){
                    list.add(s);
                }
            }
            sb.append("Excuse Set #").append(c++).append("\n");
            for (int i = 0; i < list.size(); i++)
                sb.append(list.get(i)).append("\n");
            sb.append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
