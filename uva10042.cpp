/* @author : mostafa
 * created : 2018-08-23 08:36
 */
#include <iostream>
#include <cmath>
using namespace std ;
typedef long long ll ;

int get_sum(ll n)
{
    int sum = 0 ;
    while(n){
        sum += n % 10 ;
        n /= 10 ;
    }
    return sum ;
}

// prime factorization , don't use sieve algorithm
// by this way , maybe it's faster .
bool is_smith_number(ll n)
{
    ll m = n ;
    int sum = 0 ;
    bool prime = true ;
    for(int i = 2 ; i <= (int)sqrt(n) ; i++ ){
        while( n % i == 0 ){
             n /= i ;
             sum += get_sum(i);
             prime = false ;
        }
    }
    if( prime ){
        return false ;
    }
    if( n > 1 ){
        sum += get_sum(n);
    }
    return get_sum(m) == sum ? true : false ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    ll n ;
    while( tc-- ){
        cin >> n ;
        while( ++n ){
            if( is_smith_number(n) ){
                cout << n << '\n' ;
                break ;
            }
        }
    }
    return 0 ;
}


