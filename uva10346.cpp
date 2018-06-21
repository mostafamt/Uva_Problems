/* @author : mostafa
 * created : 2018-06-21 05:25
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int N , k ;
    while( cin >> N >> k ){
		int n = N ;
		int sum = 0 ;
		while( n / k ){
			sum += n/k ;
			n = n/k + n%k ;
		}
		cout << N+sum << "\n" ;
	}
    return 0 ;
}


