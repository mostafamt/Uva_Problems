/* @author : mostafa
 * created : 2018-06-11 02:53
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	cout << fixed << setprecision(2) ;
    int f ;
	while( cin >> f , f ){
		int r ;
		cin >> r ;
		int a[f] , b[r] ;
		for(int i = 0 ; i < f ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < r ; i++){
			cin >> b[i] ;
		}
		double ratios[r*f] ;
		int idx = 0 ;
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < f ; j++){
				ratios[idx++] = (double)b[i] / a[j] ;
			}
		}
		sort( ratios , ratios+idx ) ;
		double mx = INT_MIN ;
		for(int i = 1 ; i < idx ; i++){
			double x = ratios[i] / ratios[i-1] ;
			mx = max( mx , x ) ;
		}
		cout << mx << "\n" ;
	}
    return 0 ;
}


