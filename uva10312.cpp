/* @author : mostafa
 * created : 2018-08-15 23:11
 */
#include <iostream>
using namespace std ;
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int N = 27 ;
    ll S[N] , C[N]; 
    S[1] = 1 ; S[2] = 1 ;
    C[0] = 1 ; C[1] = 1 ; C[2] = 2 ;
    for(int i = 3 ; i < N ; i++){
        S[i] = 1LL * ( ( 3*(2*i-3) * S[i-1] ) - ( (i-3) * S[i-2] ) ) / i ; ;
        C[i] = 1LL * ( C[i-1] * 2 * i * ( 2 * i - 1 )  ) / ( ( i + 1 ) * i  ) ;
    }
    int n ;
    while( cin >> n ){
        cout << S[n] - C[n-1] << '\n' ;
    }
    return 0 ;
}


