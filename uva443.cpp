/* @author : mostafa
 * created : 2018-06-25 22:53
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    ll limit = 2L << 30 ;
    vector<ll> v ;
    for(ll i = 1 ; i <= limit ; i *= 7 ){
        for(ll j = 1 ; i * j <= limit ; j *= 5 ){
            for(ll k = 1 ; i * j * k <= limit ; k *= 3 ){
                for(ll m = 1 ; i * j * k * m <= limit ; m *= 2 ){
                    v.push_back( i * j * k * m );
                }
            }
        }
    }
    sort( v.begin() , v.end() );
    int n ;
    while( cin >> n , n ){
        int x = n%10 ;
        int y = n%100 ;
        string suffix ;
        if( y == 11 || y == 12 || y == 13 ){
            suffix = "th" ;
        } else if( x == 1 ){
            suffix = "st" ;
        } else if( x == 2 ){
            suffix = "nd" ;
        } else if( x == 3 ){
            suffix = "rd" ;
        } else {
            suffix = "th" ;
        }
        cout << "The "<< n << suffix <<" humble number is "<< v[n-1] <<".\n";
    }
    return 0 ;
}


