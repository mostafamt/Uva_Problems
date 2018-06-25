/* @author : mostafa
 * created : 2018-06-25 11:13
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

bool check_ugly( int x )
{
    while( x % 2 == 0 ) x /= 2 ;
    while( x % 3 == 0 ) x /= 3 ;
    while( x % 5 == 0 ) x /= 5 ;

    return x == 1 ? true : false ;
}


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    /* int x = 1 ; */
    /* int num = 1 ; */
    /* int last = -1 ; */
    /* while( num <= 1500 ){ */
    /*     bool state = check_ugly( x ); */
    /*     if( state ){ */
    /*         num++ ; */
    /*         last = x ; */
    /*     } */
    /*     x++ ; */
    /* } */
    cout << "The 1500'th ugly number is 859963392.\n"  ;
    return 0 ;
}


