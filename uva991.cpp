/* @author : mostafa
 * created : 2018-08-15 21:37
 */
#include <iostream>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int N = 11 ;
    int a[N] ;
    a[0] = 1 ;
    for(int i = 1 ; i < N ; i++){
        a[i] = a[i-1] * 2*i * (2*i-1) / ((i+1)*i) ;
    }
    int n ;
    int c = 1 ;
    while( cin >> n ){
        if( c > 1 ){
            cout << '\n' ;
        }
        c++ ;
        cout << a[n] << '\n' ;
    }
    return 0 ;
}


