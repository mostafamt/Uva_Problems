/* @author : mostafa
 * created : 2018-06-20 05:46
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n ;
	cin >> tc ;
	for(int i = 1 ; i <= tc ; i++){
		cout << "Case " << i << ": " ;
		cin >> n ;
		int a[n] ;
		forn(i,n) cin >> a[i] ;
		sort( a , a+n ) ;
		cout << a[n/2] << "\n" ;
	}
    return 0 ;
}


