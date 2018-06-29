/* @author : mostafa
 * created : 2018-06-29 15:11
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int freq[101];

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n , x ;
    bool status ;
    cin >> tc ;
    for(int t = 1 ; t <= tc ; t++){
        status = true ;
        cout << "Case " << t << ": " ;
        memset( freq , 0 , sizeof freq );
        cin >> n ;
        forn(i,n)forn(j,n){
            cin >> x ;
            freq[x]++ ;
            if( freq[x] > n ){
                status = false ;
            }
        }
        status ? cout << "yes\n" : cout << "no\n" ;
    }

    return 0 ;
}


