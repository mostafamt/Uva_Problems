/* @author : mostafa
 * created : 2018-08-06 18:53
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n , n ){
        int sum = 0 , ans = 0 , x ;
        forn(i,n){
            if( sum < 0 ){
                sum = 0 ;
            }
            cin >> x ;
            sum += x ;
            ans = max(ans,sum);
        }
        if( ans > 0 ){
            cout << "The maximum winning streak is " << ans << ".\n" ;
        } else {
            cout << "Losing streak.\n" ;
        }
    }
    return 0 ;
}


