import java.util.*;
import java.io.*;

public class Uva11988
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while( br.ready() ){
            LinkedList<Character> linkedList = new LinkedList<>();
            LinkedList<Character> tmp = new LinkedList<>();
            char [] a = br.readLine().toCharArray();
            boolean insertAtFirst = false;
            for (int i = 0; i < a.length; i++) {
                if(a[i] == '[') {
                    if(insertAtFirst){
                        linkedList.addAll(0,tmp);
                        tmp.clear();
                    }
                    else  insertAtFirst = true;
                }
                else if(a[i] == ']') {
                    insertAtFirst = false;
                    linkedList.addAll(0,tmp);
                    tmp.clear();
                }
                else
                if (insertAtFirst)
                    tmp.addLast(a[i]);
                else {
                    linkedList.addLast(a[i]);
                }
            }
            linkedList.addAll(0,tmp);
            tmp.clear();
            Iterator<Character> it = linkedList.iterator() ;
            while(it.hasNext())
                sb.append(it.next());
            sb.append("\n");
        }
        pr.print(sb.toString());
        pr.close();
        br.close();
    }
}
