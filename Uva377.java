import java.util.*;
import java.io.*;

public class Uva377
{
    static Map<String,String> map = new HashMap<>();

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String [][] arr = {
                {"VV","V"} , {"VU","U" } , {"VC","C" } , {"VD","D" } ,
                {"UV","U"} , {"UU","C" } , {"UC","D" } , {"UD","VU"} ,
                {"CV","C"} , {"CU","D" } , {"CC","VU"} , {"CD","UU"} ,
                {"DV","D"} , {"DU","VU"} , {"DC","UU"} , {"DD","CU"} } ;
        for(String [] a : arr){
            String key = a[0] , value = a[1] ;
            map.put(key,value) ;
        }
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while( n-->0 ){
            String num1 = br.readLine();
            String num2 = br.readLine();
            char [] a = new char[8] ;
            char [] b = new char[8] ;
            for(int i = 0 ; i < 3 ; i++){
                a[i] = 'V' ;
                b[i] = 'V' ;
            }
            for(int i = 0 ; i < 5 ; i++){
                a[i+3] = num1.charAt(i) ;
                b[i+3] = num2.charAt(i) ;
            }
            for(int i = 0 ; i < 3 ; i++){
                String op = br.readLine();
                b = calc(a , b , op);
            }
            String str = new String(b);
            String last = br.readLine();
            sb.append( last.equals(str) ? "YES\n" : "NO\n" );
        }
        pw.println("COWCULATIONS OUTPUT");
        pw.print(sb.toString());
        pw.println("END OF OUTPUT");
        pw.close();
        br.close();
    }

    static char[] calc(char[] a , char[] b , String op)
    {
        if( op.equals("A") ){
            char pre_carry = '0' ;
            for(int i = 7 ; i >= 0 ; i--){
                char x = a[i] , y = b[i] ;
                String s = map.get(x+""+y) ;
                char carry = '0' , ans = '0' ;
                if( s.length() == 1 ){
                    ans = s.charAt(0) ;
                    carry = '0' ;
                } else {
                    ans = s.charAt(0) ;
                    carry = s.charAt(1) ;
                }
                if( pre_carry != '0') {
                    s = map.get(ans + "" + pre_carry);
                    if (s.length() == 1) {
                        ans = s.charAt(0);
                    } else {
                        ans = s.charAt(0);
                        carry = s.charAt(1);
                    }
                }
                b[i] = ans ;
                pre_carry = carry ;
            }
        } else if( op.equals("R") ){
            for(int i = 7 ; i > 0 ; i--){
                b[i] = b[i-1] ;
            }
            b[0] = 'V' ;
        } else if( op.equals("L") ){
            for(int i = 0 ; i < 7 ; i++){
                b[i] = b[i+1] ;
            }
            b[7] = 'V' ;
        } else {
            // do nothing
        }
        return b ;
    }

    static void printArray(char [] c)
    {
        for (int i = 0; i < c.length; i++) {
            System.out.print(c[i]);
        }
        System.out.println();
    }

}
