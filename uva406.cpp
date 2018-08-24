/* @author : mostafa
 * created : 2018-08-24 06:47
 */
#include <iostream>
#include <bitset>
#include <vector>
using namespace std ;
#define pb push_back
#define MX 1001
typedef vector<int> vi ;

bitset<1010> bs ;
vi primes ;

void sieve()
{
    bs.set();
    primes.pb(1);
    for(int i = 2 ; i < MX ; i++){
        if( bs[i] ){
            primes.pb(i);
            for(int j = i*i ; j < MX ; j += i ){
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
    int N , C  ;
    while( cin >> N >> C ){
        cout << N << " " << C << ":" ;
        vi ans ;
        int sz = 0 ;
        for(int i = 0 ; i < (int)primes.size() ; i++){
            if( primes[i] > N ){
                break ;
            }
            ans.pb(primes[i]);
            sz++ ;
        }
        if( sz % 2 == 0 ){
            if( 2*C >= sz ){
                for(int i : ans ){
                    cout << " " << i ;
                }
            } else {
                int r = ( sz - 2 * C ) / 2 ;
                for(int i = r ; i < sz - r ; i++){
                    cout << " " << ans[i] ;
                }
            }
            cout << '\n' ;
        } else {
            if( 2 * C - 1 >= sz ){
                for(int i : ans ){
                    cout << " " << i ;
                }
            } else {
                int r = ( sz - (2*C-1) ) / 2 ;
                for(int i = r ; i < sz - r ; i++){
                    cout << " " << ans[i] ;
                }
            }
            cout << '\n' ;
        }
        cout << '\n' ;
    }
    return 0 ;
}


