/* @author : mostafa
 * created : 2018-06-25 22:14
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
    ll limit = (int)1e9 ;
    vector<int> v ;
    for(ll i = 1L ; i <= limit ; i *= 5 ){
        for(ll j = 1L ; i * j <= limit ; j *= 3 ){
            for(ll k = 1L ; i * j * k <= limit ; k *= 2 ){
                v.push_back( (int)(i * j * k) );
            }
        }
    }
    sort( v.begin() , v.end() );
    cout << "The 1500'th ugly number is " << v[1500-1] << ".\n" ;
    return 0 ;
}


