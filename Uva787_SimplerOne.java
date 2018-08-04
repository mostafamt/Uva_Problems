import java.util.*;
import java.io.*;
import java.math.BigInteger ;

public class Uva787_SimplerOne
{

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        while( sc.hasNext() ){
            BigInteger max = BigInteger.valueOf(Long.MIN_VALUE);
            int x = 0 ;
            while( ( x = sc.nextInt() ) != -999999  ){
                list.add(x);
                for(int i = 0 ; i < list.size() ; i++){
                    BigInteger prod = BigInteger.valueOf(1L);
                    for(int j = i ; j < list.size() ; j++){
                        prod = prod.multiply( BigInteger.valueOf(list.get(j)) );
                        if( prod.compareTo(max) > 0 ){
                            max = prod ;
                        }
                    }
                }
            }
            list.clear();
            System.out.println(max.toString());
        }
    }
}