/* @author : mostafa
 * created : 2018-08-24 07:25
 */
#include <iostream>
#include <bitset>
#include <vector>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MX 1000001
typedef long long ll ;
typedef vector<int> vi ;

vi primes ;
bitset<1000100> bs ;

void sieve()
{
    bs.set();
    for(ll i = 2 ; i < MX ; i++){
        if( bs[i] ){
            primes.pb(i);
            for(ll j = i*i ; j < MX ; j += i){
                bs[j] = 0 ;
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    sieve();
    int n ;
    while( cin >> n , n ){
        int num = -1 ;
        for(int i = 0 ; i < (int) primes.size() ; i++){
            if( primes[i] >= n ){
                break ;
            }
            int other = n - primes[i] ;
            if( bs[other] ){
                num = primes[i] ;
                break ;
            }
        }
        if( num == -1 ){
            cout << "Goldbach's conjecture is wrong." << '\n' ;
        } else {
            cout << n << " = " << num << " + " << n-num << '\n' ;
        }
    }
    return 0 ;
}


