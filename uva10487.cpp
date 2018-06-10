/* @author : mostafa
 * created : 2018-06-10 22:05
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , c = 1 ;
	while( cin >> n , n ){
		int tmp[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> tmp[i] ;
		}
		set<int> myset ;
		int mx = INT_MIN ;
		int mn = INT_MAX ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if( i == j ) continue ;
				int val = tmp[i] + tmp[j] ;
				myset.insert( val );
				mx = max( mx , val );
				mn = min( mn , val );
			}
		}
		set<int>::iterator it ;
		int q , x ;
		cin >> q ;
		cout << "Case " << c++ << ":\n"; 
		while( q-- ){
			cin >> x ;
			cout << "Closest sum to " << x << " is " ;
			if( x >= mx ){
				cout << mx ;
			} else if( x <= mn ){
				cout << mn ;
			} else {
				it = myset.lower_bound(x);
				int u = abs( x - *it );
				int w = abs( x - *(--it) );
				if( u < w ){
					cout << *(++it) ;
				} else {
					cout << *it ;
				}
			}
			cout << ".\n" ;
		}
	}
    return 0 ;
}


