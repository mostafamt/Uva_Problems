/* @author : mostafa
 * created : 2018-08-13 23:31
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    while( tc-- ){
        int n ;
        cin >> n ;
        int a[n] ;
        int idx = n ;
        int x , y ;
        forn(i,n){
            cin >> x >> y ;
            a[--idx] = x+y ;
        }
        int carry = 0 ;
        forn(i,n){
            a[i] += carry ;
            carry = a[i] / 10 ;
            a[i] %= 10 ;
        }
        if( carry ){
            cout << carry ;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            cout << a[i] ;
        }
        tc ? cout << '\n' << '\n' : cout << '\n' ;

    }
    return 0 ;
}


