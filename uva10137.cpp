/* @author : mostafa
 * created : 2018-06-25 05:16
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    int n , x , y ;
    while( scanf("%d",&n) , n ){
        int a[n] , sum = 0 ;
        forn(i,n){
            scanf("%d.%d",&x,&y );
            a[i] = x*100 + y  ;
            sum += a[i] ; 
        }
        int avg = sum / n ;
        int rem = sum % n ;
        int exchanged = 0 ; sum = 0 ;
        forn(i,n){
            if( a[i] <= avg ){
                exchanged += avg - a[i] ;
                sum++ ;
            }
        }
        if( n-sum < rem ){
            exchanged += rem - (n-sum) ;
        }
        double ans = exchanged/100.0 ;
        printf("$%2.2lf\n" , ans );
    }
    
    return 0 ;
}


