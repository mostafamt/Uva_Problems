import java.util.*;
import java.io.*;

public class Uva264
{
    static final int max = (int)1e7 ;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(System.out);
        int num = 1 ;
        int den = 1 ;
        int [] numValues = new int[max];
        int [] denValues = new int[max];
        boolean status = false ;
        for (int i = 0; i < max; i++) {
            numValues[i] = num ;
            denValues[i] = den ;
            if(num==1&&den%2==1)
                den++ ;
            else if(den==1&&num%2==0)
                num++ ;
            else if(num==1&&den%2==0)
            {
                num++ ;
                den-- ;
                status = true ;
            }
            else if(den==1&&num%2==1)
            {
                num-- ;
                den++ ;
                status = false ;
            }
            else if(status)
            {
                num++ ; den-- ;
            }
            else if(!status)
            {
                num-- ; den++ ;
            }
        }

        while(br.ready())
        {
            int x = Integer.parseInt(br.readLine());
            pr.println("TERM "+x+" IS "+ numValues[x-1]+"/"+denValues[x-1] );
        }


        br.close();
        pr.close();
    }

}
