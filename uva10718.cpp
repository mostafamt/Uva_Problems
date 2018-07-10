/* @author : mostafa
 * created : 2018-07-10 17:41
 */
#include <iostream>
using namespace std ;
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    ll n , l , u , ans ;
    while( cin >> n >> l >> u ){
        ans = 0 ;
        for(int i = 32 ; i >= 0 ; i--){
            ll x = 1L << i ;
            bool state = x & n ;
            if( state ){
                ll temp = ans ;
                temp += x-1 ;
                if( temp < l ){
                    ans |= x ;
                }
            } else {
                ll temp = ans ;
                temp |= x ;
                if( temp <= u ){
                    ans |= x ;
                }
            }
       }
       cout << ans << '\n' ;
    }
    return 0 ;
}


