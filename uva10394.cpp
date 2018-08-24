/* @author : mostafa
 * created : 2018-08-24 08:41
 */
#include <iostream>
#include <vector>
#include <bitset>
using namespace std ;
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define MX 20000010 
typedef long long ll ;
typedef vector<ii> vii ;

vii twins ;
bitset<20000010> bs ;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0 ;
    for(ll i = 2 ; i < MX ; i++){
        if( bs[i] ){
            if( bs[i+2] ){
                twins.pb( {i,i+2} ); 
            }
            for(ll j = i*i ; j < MX ; j +=i){
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
    int S ;
    while( cin >> S ){
        cout << "(" << twins[S].fi << ", " << twins[S].se << ")" << '\n' ;
    }
    return 0 ;
}


