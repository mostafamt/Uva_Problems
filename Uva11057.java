import java.util.*;
import java.io.*;

public class Uva11057
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();
        while( br.ready() ){
            int n = Integer.parseInt(br.readLine()) ;
            int [] a = new int[n] ;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken()) ;
            }
            Arrays.sort(a);
            int m = Integer.parseInt(br.readLine()) ;
            int max_sum = 0 , book1 = 0 , book2 = 0 ;
            int min_diff = Integer.MAX_VALUE ;
            for(int i = 0 ; i < n ; i++){
                if( a[i] > m ){
                    break ;
                }
                int key = m - a[i] ;
                int idx = binary_search(a , key , i) ;
                if( idx == -1 ){
                    continue;
                }
                int sum = a[i] + a[idx] ;
                int diff = Integer.max(a[i],a[idx]) - Integer.min(a[i],a[idx]) ;
                if( sum > max_sum ){
                    max_sum = sum ;
                    min_diff = diff ;
                    book1 = a[i] ;
                    book2 = a[idx] ;
                } else if( sum == max_sum && diff < min_diff ){
                    min_diff = diff ;
                    book1 = a[i] ;
                    book2 = a[idx] ;
                }
            }
            sb.append("Peter should buy books whose prices are ").
                    append( Integer.min(book1,book2) ).
                    append(" and ").
                    append( Integer.max(book1,book2) ).
                    append(".\n\n");
            br.readLine() ;
        }
        pw.print(sb.toString());
        br.close();
        pw.close();
    }

    static int binary_search(int [] array , int key , int idx)
    {
        int low = 0 ;
        int high = array.length ;
        int x = 0 ;
        while( low <= high ){
            int mid = (low+high) >>> 1 ;
            int midVal = array[mid] ;
            if( midVal <= key && ( ( mid+1 < array.length && array[mid+1] > key ) || mid+1 == array.length ) ){
                if( mid == idx ){
                    return mid-1 ;
                } else {
                    return mid;
                }
            } else if( midVal > key ){
                high = mid-1 ;
            } else if( midVal < key ){
                low = mid+1 ;
            }
        }
        return -1 ;
    }

}
