/* @author : mostafa
 * created : 2018-06-11 02:26
 */
#include <iostream>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n ;
	cin >> tc ;
	while( tc-- ){
		cin >> n ;
		int a[n] , b[n-1] , ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 1 ; i < n ; i++){
			b[i-1] = 0 ;
			for(int j = 0 ; j < i ; j++){
				if( a[j] <= a[i] ){
					b[i-1]++ ;
				}
			}
			ans += b[i-1] ;
		}
		cout << ans << "\n" ;
	}
    return 0 ;
}


