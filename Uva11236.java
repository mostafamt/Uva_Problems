/* @author : mostafa
 * created : 2018-09-16 07:29 
 */
public class Uva11236 
{
    public static void main(String[] args) 
    {
        StringBuilder sb = new StringBuilder();
        for(int i = 1 ; i * 4 <= 2000 ; i++){
            for(int j = i ; i + j * 3 <= 2000 ; j++){
                for(int k = j ; i + j + k * 2 <= 2000 ; k++){
                    if( i * j * k <= 1000000 ){ // This condition to prevent division by zero
                        continue ;
                    }
                    int l = ( i + j + k ) * 1000000 / ( i * j * k - 1000000 ) ;
                    if( l >= k && l <= 20000 && i + j + k + l <= 2000 && ( i + j + k + l ) * 1000000 == i * j * k * l ){
                        sb.append(i+" "+j+" "+k+" "+l).append('\n');
                    }
                    
                }
            }
        }
        System.out.println(sb.toString());
    }
}
