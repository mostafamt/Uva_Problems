import java.util.*;
import java.io.*;
import java.math.BigInteger ;

// This algorithm runs : O(n) = n
// you can try another algorithm if you can't understand it
// for example , you can try O(n) = n^2 , may be accepted
// or you can try dynamic programming

public class Uva787 {

    public static final BigInteger zero = BigInteger.ZERO ;

    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( in.ready() ){
            int x = 0 ;
            BigInteger ans = BigInteger.valueOf(0L);
            BigInteger sum = BigInteger.valueOf(0L);
            BigInteger first_negative = BigInteger.valueOf(0L);
            BigInteger last_negative = BigInteger.valueOf(0L);
            boolean negative_appeared = false , zero_appeared = false ;
            boolean first_num = true ;
            int len = 0 ;

            while( ( x = in.nextInt()) != -999999 ){
                if( x == 0 ){
                    // reset values
                    zero_appeared = true ;
                    if( sum.compareTo(zero) < 0 && len > 1 ){
                        BigInteger max = BigInteger.valueOf(0L);
                        if( first_negative.compareTo(last_negative) > 0 ){
                            max = first_negative ;
                        } else {
                            max = last_negative ;
                        }
                        if( max.compareTo(zero) != 0 ){
                            sum = sum.divide(max);
                        }
                    }
                    if( sum.compareTo(ans) > 0 ){
                        ans = sum ;
                    }
                    sum = zero ;
                    len = 0 ;
                    first_num = true ;
                    negative_appeared = false ;
                    first_negative = zero ;
                    last_negative = zero ;
                    continue;
                }

                if( first_num ){
                    sum = BigInteger.valueOf(x) ;
                    ans = sum ;
                    first_num = false ;
                } else {
                    sum = sum.multiply(BigInteger.valueOf(x));
                }

                if( sum.compareTo(ans) > 0 ){
                    ans = sum ;
                }

                if( x < 0 && negative_appeared ){
                    last_negative = BigInteger.valueOf(x) ;
                } else if( negative_appeared ){
                    last_negative = last_negative.multiply(BigInteger.valueOf(x));
                } else if( x < 0 ){
                    first_negative = sum ;
                    last_negative = BigInteger.valueOf(x);
                    negative_appeared = true ;
                }
                len++ ;
            }
            if( sum.compareTo(zero) < 0 && len > 1 ){
                BigInteger max = BigInteger.valueOf(0L);
                if( first_negative.compareTo(last_negative) > 0 ){
                    max = first_negative ;
                } else {
                    max = last_negative ;
                }
                if( max.compareTo(zero) != 0 ){
                    sum = sum.divide(max);
                }
            }
            if( sum.compareTo(ans) > 0 ){
                ans = sum ;
            }
            if( ans.compareTo(zero) < 0 && zero_appeared ){
                ans = zero ;
            }
            sb.append(ans).append('\n');
        }
        pr.print(sb.toString());
        pr.close();
        in.close();
    }

    static class Scanner
    {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

        public String next() throws IOException
        {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {return Integer.parseInt(next());}

        public long nextLong() throws IOException {return Long.parseLong(next());}

        public String nextLine() throws IOException {return br.readLine();}

        public boolean ready() throws IOException {return br.ready();}

        public void close() throws IOException { br.close(); }
    }
}
