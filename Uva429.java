import java.util.*;
import java.io.*;

public class Uva429
{
    static ArrayList<Integer> [] adjList ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int tc = Integer.parseInt(br.readLine());
        br.readLine();
        while( br.ready() ){
            ArrayList<String> list = new ArrayList<>();
            Map<String,Integer> mp = new HashMap<>();
            int num = 0 ;
            while( true ){
                String s = br.readLine();
                list.add(s);
                mp.put(s,num++);
                if( s.equals("*") ){
                    break ;
                }
            }
            adjList = new ArrayList[num];
            for (int i = 0; i < num; i++) {
                adjList[i] = new ArrayList<>();
            }
            for (int i = 0; i < list.size(); i++) {
                for (int j = i+1 ; j < list.size(); j++) {
                    if( OK( list.get(i) , list.get(j) ) ){
                        adjList[i].add(j);
                        adjList[j].add(i);
                    }
                }
            }
            while( br.ready() ){
                String s = br.readLine();
                if( s.isEmpty() ){
                    sb.append('\n');
                    break ;
                }
                StringTokenizer st = new StringTokenizer(s);
                String s1 = st.nextToken();
                String s2 = st.nextToken();
                int u = mp.get(s1) , v = mp.get(s2);
                int ans = bfs(u,v);
                sb.append(s1).append(" ").append(s2).append(" ");
                sb.append(ans).append('\n');
            }
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }

    static boolean OK(String u , String v)
    {
        if( u.length() != v.length() ){
            return false ;
        } else {
            int dif = 0 ;
            for (int i = 0; i < u.length(); i++) {
                if( u.charAt(i) != v.charAt(i) ){
                    dif++ ;
                }
            }
            return dif <= 1 ? true : false ;
        }
    }

    static int bfs( int u , int v )
    {
        int [] dist = new int[201];
        boolean [] marked = new boolean[201];
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        marked[u] = true ;
        dist[u] = 0 ;
        while( !q.isEmpty() ){
            int w = q.remove();
            for(int i : adjList[w]){
                if(!marked[i]){
                    marked[i] = true ;
                    q.add(i);
                    dist[i] = dist[w]+ 1 ;
                }
            }
        }
        return dist[v] ;
    }

}
