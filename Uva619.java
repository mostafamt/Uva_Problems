import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Uva619
{
    static final BigInteger twenty_six = new BigInteger("26");

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        while( br.ready() ){
            String s = br.readLine();
            String number="" , word="" ;
            if( s.equals("*") ){
                break ;
            }
            char digit_or_char = s.charAt(0);
            if( digit_or_char >= 'a' && digit_or_char <= 'z' ){
                word = s ; number = encrypt(s);
            } else {
                number = s ; word = decrypt(s);
            }
            number = format_number(number);
            int space = 22 - word.length() ;
            String formated = String.format("%s%"+space+"c%s",word,' ',number);
            sb.append(formated).append('\n');
        }
        pr.print(sb.toString());
        br.close();
        pr.close();
    }


    static String encrypt(String word)
    {
        BigInteger number = new BigInteger("0");
        for(int i = word.length()-1 , j = 0 ; i >= 0 ; i--,j++){
            int c = word.charAt(i) - 'a' + 1 ;
            number = number.add( new BigInteger(c+"").multiply(twenty_six.pow(j))  );
        }
        return number.toString();
    }

    static String decrypt(String bigNum)
    {
        BigInteger number = new BigInteger(bigNum);
        int pow = 0 ;
        while( number.compareTo(twenty_six.pow(pow) ) > 0 ){
            pow++ ;
        }
        char [] word = new char[pow];
        for(int i = pow-1 , j = 0 ; i >= 0 ; i--,j++){
            BigInteger base = twenty_six.pow(i) ;
            BigInteger [] a = number.divideAndRemainder(base);
            int num = Integer.parseInt( a[0].toString() );
            number = a[1];
            word[j] = (char)(num+'a'-1) ;
        }
        return new String(word);
    }

    static String format_number(String number)
    {
        int len = number.length();
        int size = len/3 ;
        if( len % 3 == 0 ){
            size-- ;
        }
        char [] a = new char[len+size];
        int idx = len+size-1 ;
        for(int i = len-1 , j = 1 ; i >= 0 ; i--,j++){
            a[idx--] = number.charAt(i) ;
            if( j % 3 == 0 && i != 0 ){
                a[idx--] = ',' ;
            }
        }
        return new String(a);
    }
}
