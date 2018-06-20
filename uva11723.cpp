/* @author : mostafa
 * created : 2018-06-20 00:48
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

const int SIZE = 26 ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , r , c = 1 ;
	while( cin >> n >> r , n ){
		cout << "Case " << c++ << ": " ;
		if( n > r + r * SIZE ){
			cout << "impossible\n" ;
		} else {
			int ans = n / r ;
			if( n % r != 0 ) ans++ ;
			cout << ans-1 << "\n" ;
		}
	}
    return 0 ;
}


