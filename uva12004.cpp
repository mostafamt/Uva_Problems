/* @author : mostafa
 * created : 2018-06-26 08:12
 */
#include <iostream>
using namespace std ;
#define SIZE (int) 1e5 
typedef long long ll ;

ll ans[SIZE] ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    for(int i = 1 ; i < SIZE ; i++){
        ans[i] += ans[i-1] + i ;
    }
    int tc , x ; 
    cin >> tc ;
    for(int i = 1 ; i <= tc ; i++){
        cin >> x ;
        cout << "Case "<< i <<": " ;
        if( ans[x-1] % 2 == 0 ){
            cout << ans[x-1]/2 << "\n" ;
        } else {
            cout << ans[x-1] << "/2\n" ;
        }
    }

    
    return 0 ;
}


