import java.util.*;
import java.io.*;

public class Uva12250
{
    static Map<String,String> map ;
    public static void main(String[] args) throws IOException
    {
        fill_map();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder("");
        String line = "" ;
        int tc = 1 ;
        while( !(line = br.readLine()).equals("#") ){
            String ans = map.containsKey(line) ? map.get(line) : "UNKNOWN";
            sb.append("Case "+ tc++ + ": " + ans ).append('\n');
        }
        System.out.print(sb.toString());
    }

    static void fill_map()
    {
        map = new HashMap<>();map.put("HELLO","ENGLISH");
        map.put("HOLA","SPANISH");map.put("HALLO","GERMAN");
        map.put("BONJOUR","FRENCH");map.put("CIAO","ITALIAN");map.put("ZDRAVSTVUJTE","RUSSIAN");
    }
}
