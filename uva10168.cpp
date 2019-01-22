/* @author : mostafa
 * created : 2019-01-21 19:43
 */
#include <iostream>
#include <bitset>
#include <vector>
#include <stack>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MAX 10000010
typedef long long ll ;
typedef vector<int> vi ;

vi primes ;
bitset<MAX> bs ;
ll _sieve_size ;
vi prevois_prime(MAX);

void sieve(ll upperbound)
{
    _sieve_size = upperbound ;
    bs.set();
    bs[0] = bs[1] = 0 ;
    for(ll i = 2 ; i <= _sieve_size ; i++){
        if( bs[i] ){
            for(ll j = i*i ; j <= _sieve_size ; j+=i ){
                bs[j] = 0 ;
            }
            primes.pb( (int)i );
        }
    }
}

void fill_previous_primes()
{
    int previous = 2 ;
    for(int i = 2 ; i < 10000001 ; i++){
        if( bs[i] ){
            previous = i ;
        }
        prevois_prime[i] = previous ;
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int N = 10000005 ;
    sieve(N);
    fill_previous_primes();
    int n ;
    while( cin >> n ){

        // It's impossible to have 4 primes from n < 8
        if ( n < 8 ){
            cout << "Impossible." << '\n' ;
            continue ;
        }

        for(int i = 3 ; i >= 0 ; i--){
            int last = prevois_prime[n-i*2];
            if( i == 0 ){
                cout << last << '\n' ;
            } else {
                cout << last << " " ;
            }
            n -= last ;
        }
    }
    return 0 ;
}

