/* @author : mostafa
 * created : 2018-06-20 03:08
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n , k , p ;
	cin >> tc ;
	for(int i = 1 ; i <= tc ; i++){
		cin >> n >> k >> p ;
		cout << "Case " << i << ": " ;
		int ans = (k+p) % n ;
		ans == 0 ? ans = n : ans = ans ;
		cout << ans << "\n" ;
	}
    return 0 ;
}


