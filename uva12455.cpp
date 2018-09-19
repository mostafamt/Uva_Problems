/* @author : mostafa
 * created : 2018-09-19 08:36
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc , n , p , sum = 0 ;
    bool status ;
    cin >> tc ;
    while( tc-- ){
        cin >> n >> p ;
        int a[p];
        forn(i,p) cin >> a[i] ;
        sum = 0 ;
        status = false ;
        for(int i = 0 ; i < ( 1 << p ) ; i++){
            sum = 0 ;
            for(int j = 0 ; j < p ; j++){
                if( i & ( 1 << j ) ){
                    sum += a[j] ;
                }
            }
            if( sum == n ){
                status = true ;
                break ;
            } 
        } 
        status ? cout << "YES" : cout << "NO" ;
        cout << '\n' ;
    }
    return 0 ;
}
