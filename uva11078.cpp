/* @author : mostafa
 * created : 2018-06-10 16:59
 */
#include <iostream>
#include <climits>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n ;
	cin >> tc ;
	while( tc-- ){
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int mx = INT_MIN ;
		int mx_diff = INT_MIN ;
		for(int i = 0 ; i < n-1 ; i++){
			mx = max( mx , a[i] );
			mx_diff = max( mx_diff , mx - a[i+1] ) ;
		}
		cout << mx_diff << "\n" ;
	}
    return 0 ;
}


