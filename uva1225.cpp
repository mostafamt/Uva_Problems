/* @author : mostafa
 * created : 2018-06-21 05:36
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int digits[10] ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n ;
	cin >> tc ;
	while( tc-- ){
		memset( digits , 0 , sizeof digits ) ;
		cin >> n ;
		for(int i = 1 ; i <= n ; i++){
			int x = i ;
			while( x ){
				int y = x%10 ;
				digits[y]++ ;
				x /= 10 ;
			}
		}
		cout << digits[0] ;
		for(int i = 1 ; i < 10 ; i++){
			cout << " " << digits[i] ;
		}
		cout << "\n" ;
	}
    return 0 ;
}


