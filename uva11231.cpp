/* @author : mostafa
 * created : 2018-06-27 15:25
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m , c , ans ;
    while( cin >> n >> m >> c , n ){
        int y = n-8+1 ;
        int x = m-8+1 ;
        if( x % 2 == 0 && y % 2 == 0 ){
            ans = x*y/2 ;
        } else if( x % 2 == 1 && y % 2 == 1 ){
            int u = x-1 , v = y - 1 ;
            ans = u*v/2 + x/2 + y/2 ;
            ans += c ? 1 : 0 ;
        } else if( x % 2 == 1 ){
            int u = x-1 , v = y ;
            ans = u*v/2 + y/2 ;
        } else {
            int u = x , v = y-1 ;
            ans = u*v/2 + x/2 ;
        }
        cout << ans << '\n' ;
        
    }
    return 0 ;
}


