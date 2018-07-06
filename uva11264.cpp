/* @author : mostafa
 * created : 2018-07-06 19:52
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    while( tc-- ){
        int n ;
        cin >> n ;
        ll a[n] ;
        forn(i,n){
            cin >> a[i] ;
        }

        ll sum = 0 ;
        int ans = 1 ;
        for(int i = 0 ; i < n-1 ; i++){
            if( sum+a[i] < a[i+1] ){
                sum += a[i] ;
                ans++ ;
            }
        }
        cout << ans << '\n' ;

    }
    return 0 ;
}


