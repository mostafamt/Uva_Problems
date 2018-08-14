/* @author : mostafa
 * created : 2018-08-13 15:12
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    cout << fixed ;
    cout << setprecision(3);
    int tc , n ;
    cin >> tc ;
    while( tc-- ){
        cin >> n ;
        if( n < 2 ){
            cout << 0.000 << '\n' ;
        } else if( n == 2 ){
            cout << 4.000 << '\n' ;
        } else {
            cout << (n-2)*(n-2)*sqrt(2) + n*n - (n-2)*(n-2) << '\n' ;
        }
        if( tc ){
            cout << '\n' ;
        }

    }
     
    return 0 ;
}


