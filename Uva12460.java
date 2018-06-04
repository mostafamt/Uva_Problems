import java.util.*;
import java.io.*;
// bfs 
public class Uva12460 {
    static HashSet<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        String item = br.readLine();
        while(!item.equals("--")){
            set.add(item);
            item = br.readLine() ;
        }
        while(br.ready()){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String from = st.nextToken();
            String to = st.nextToken();
            if(from.length() != to.length()){
                sb.append("No\n");
            } else {
                if( bfs(from.toCharArray() , to.toCharArray()) ){
                    sb.append("Yes\n");
                } else {
                    sb.append("No\n") ;
                }
            }
        }
        pr.print(sb.toString()) ;
        pr.close();
        br.close();
    }

    static boolean bfs( char [] from , char [] to ){
        String a = new String(from) ;
        String b = new String(to) ;
        if( a.equals(b) ){
            return true ;
        }
        char [] out = Arrays.copyOf(from , from.length) ;
        for (int i = 0; i < from.length; i++) {
            if( from[i] != to[i] ){
                out[i] = to[i] ;
                String s = new String(out) ;
                if( set.contains(s) ){
                    boolean state = bfs(out , to) ;
                    if( state ){
                        return true ;
                    }
                }
                out[i] = from[i] ;
            }
        }
        return false ;
    }

}
