/* @author : mostafa
 * created : 2018-07-06 23:34
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , d , r ;
    while( cin >> n >> d >> r , n ){
        int m[n] ;
        forn(i,n) cin >> m[i] ;
        int e[n] ;
        forn(i,n) cin >> e[i] ;
        sort( m , m+n );
        sort( e , e+n );
        int ans = 0 ;
        forn(i,n){
            int sum = m[i] + e[n-1-i] ;
            if( sum > d ){
                ans += (sum-d) * r ;
            }
        }
        cout << ans << '\n' ;
    }
     
    return 0 ;
}


