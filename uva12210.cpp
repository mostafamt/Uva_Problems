/* @author : mostafa
 * created : 2018-07-08 16:10
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int b , s , c = 1 ;
    while( cin >> b >> s , b ){
        int a[b] , p[s] ;
        forn(i,b) cin >> a[i] ;
        forn(i,s) cin >> p[i] ;
        if( b <= s ){
            cout << "Case " << c++ << ": 0\n" ;
        } else {
            sort( a , a+b );
            cout << "Case " << c++ << ": " << b-s << " " << a[0] << '\n' ;
        }
    }
    return 0 ;
}


