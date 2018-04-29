import java.util.*;
import java.io.*;

public class Uva514
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while(true)
        {
            int n = Integer.parseInt(br.readLine());
            if(n==0)
                break;
            Stack<Integer> stack = new Stack<>();
            LOOP:while (true)
            {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int max = 0 ;
                boolean status = true ;
                while (st.hasMoreTokens())
                {
                    int x = Integer.parseInt(st.nextToken());
                    if(x==0)
                        break LOOP ;
                    if(x>max)
                    {
                        for (int i = max+1 ; i < x ; i++) {
                            stack.push(i);
                        }
                        max = x ;
                    }
                    else{
                        int y = stack.pop();
                        if(x!=y) {
                            status = false;
                            break ;
                        }
                    }
                }
                sb.append(status?"Yes\n":"No\n");
                stack.clear();
            }
            sb.append("\n");
        }

        pr.print(sb.toString());
        pr.close();
        br.close();
    }

}
