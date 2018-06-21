/* @author : mostafa
 * created : 2018-06-21 19:43
 */
#include <iostream>
#include <cmath>
using namespace std ;
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int start , end ;
	int sum ;
	while( cin >> sum , sum != -1 ){
		int n = sqrt( 2L * sum ) ;
		for(int i = n ; i >= 1 ; i--){
			ll x = 2L*sum - i * i + i ;
			if( x % ( 2 * i ) == 0 ){
				start = x / ( 2 * i ) ;
				end = start + i - 1 ;
				break ;
			}
		}
		cout << sum << " = " << start << " + ... + " << end << "\n" ;
	}
    return 0 ;
}


