/* @author : mostafa
 * created : 2018-08-25 06:37
 */
#include <iostream>
#include <bitset>
using namespace std ;
#define MX 32777

bitset<MX> bs ;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0 ;
    for(int i = 2 ; i < MX ; i++){
        if( bs[i] ){
            for(int j = i*i ; j < MX ; j+=i){
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
        int sum = 0 ;
        for(int i = 2 ; i <= n/2 ; i++){
            if( bs[i] && bs[n-i] ){
                sum++ ;
            }
        }
        cout << sum << '\n' ;
    }
    return 0 ;
}


