/* @author : mostafa
 * created : 2018-06-20 06:03
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
	while( cin>>n , n ){
		int ans = 0 ;
		while( n >= 1 ){
			ans += n*n ;
			n-- ;
		}
		cout << ans << "\n" ;
	}
    return 0 ;
}


