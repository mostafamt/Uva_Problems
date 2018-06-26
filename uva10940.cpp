/* @author : mostafa
 * created : 2018-06-26 00:35
 */
#include <iostream>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n , n ){
        int x = 1 , s = 1 ;
        while( x <= n ){
            x *= 2 ;
            s = x%n ;
        }
        cout << n-s << '\n' ;
    }
    
    return 0 ;
}


