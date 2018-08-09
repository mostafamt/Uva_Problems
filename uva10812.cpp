/* @author : mostafa
 * created : 2018-08-09 01:47
 */
#include <stdio.h>

int main()
{
    int n , x , y ; 
    scanf("%d" , &n);
    while( n-- ){
        scanf( "%d %d" , &x , &y );
        if( ((x+y)%2) != 0 ){
            printf( "impossible\n" ) ;
        } else {
            int u = (x+y) / 2 ;
            int v = u - y ;
            if( v < 0 ){
                printf("impossible\n") ;
            } else {
                printf( "%d %d\n" , u , v );
            }
        }
    }
    return 0 ;
}


