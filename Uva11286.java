import java.util.*;
import java.io.*;

public class Uva11286
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder("");
        int n ;
        int [] a = new int[5];
        HashMap<Key,Integer> map = new HashMap<>();
        while( ( n = Integer.parseInt(br.readLine()) ) != 0 ){
            map.clear();
            int ans = -1 , max = 0 ;
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 5; j++) {
                    a[j] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(a);
                Key k = new Key(a);
                if( map.containsKey(k) ){
                    int val = map.get(k);
                    map.put(k,++val);
                } else {
                    map.put(k,1);
                }

                if( map.get(k) > max ){
                    max = map.get(k);
                    ans = map.get(k);
                } else if( map.get(k) == max ){
                    ans += map.get(k);
                }
            }
            sb.append(ans).append('\n');
        }
        System.out.print(sb.toString());
        br.close();
    }

    static class Key
    {
        int [] a ;

        public Key(int[] a) {
            this.a = a;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Key key = (Key) o;
            return Arrays.equals(a, key.a);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(a);
        }
    }

}
