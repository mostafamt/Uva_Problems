/* @author : mostafa
 * created : 2018-08-24 07:58
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
#include <cmath>
using namespace std ;
#define pb push_back
#define MX 10000010
typedef long long ll ;
typedef vector<int> vi ;

vi primes ;
bitset<10000010> bs ;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0 ;
    for(ll i = 2 ; i <= MX ; i++){
        if( bs[i] ){
            primes.pb(i);
            for(ll j = i*i ; j <= MX ; j +=i){
                bs[j] = 0 ;
            }
        }
    }
}

bool is_prime(ll N)
{
    if( N < MX ){
        return bs[N] ; 
    }
    for(int i = 0 ; i < (int)(primes.size() ); i++){
        if( primes[i] > (int)sqrt(N)  ){
            return true ;
        }
        if( N % primes[i] == 0 ){
            return false ;
        }
    }
    return true ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    sieve();
    int L , U ;
    while( cin >> L >> U ){
        int last = -1 ;
        int mx = 0 , mn = INT_MAX ;
        int x , y , u , v ;
        x = y = u = v = -1 ;
        for(ll i = L ; i <= U ; i++){
            if( is_prime(i) ){
                if( last != -1 ){
                    int dif = i - last ;
                    if( dif > mx ){
                        mx = dif ;
                        x = last ;
                        y = i ;
                    }

                    if( dif < mn ){
                        mn = dif ;
                        u = last ;
                        v = i ;
                    }
                }
                last = i ;
            }
        }
        if( mx == 0 ){
            cout << "There are no adjacent primes." << '\n' ;
        } else {
            cout << u << "," << v << " are closest, " ;
            cout << x << "," << y << " are most distant." << '\n' ;
        }
    }
    return 0 ;
}


