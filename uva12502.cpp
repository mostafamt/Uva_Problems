/* @author : mostafa
 * created : 2018-06-20 06:21
 */
#include <iostream>
#include <cmath>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , x , y , z ;
	cin >> tc ;
	while( tc-- ){
		cin >> x >> y >> z ;
		// convet to minutes to increase precision
		int sum = x*60 + y*60 ;
		int unit = sum/3 ;
		int a = x*60 - unit ;
		cout << z * a / unit << "\n" ;
	}
    return 0 ;
}


