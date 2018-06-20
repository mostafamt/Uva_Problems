/* @author : mostafa
 * created : 2018-06-20 15:20
 */
#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , x , y , z ;
	cin >> tc ;
	while( tc-- ){
		cin >> x >> y >> z ;
		double work_per_family = (x+y)/3.0 ;
		if( x >= 2*work_per_family ){
			// in any case , one family can't get greater than input z
			cout << z << "\n" ;
		} else if( x <= work_per_family ){
			// in any case , one family can't get negative
			cout << 0 << "\n" ;
		} else {
			double ans = z*((x-work_per_family)/work_per_family) ;
			cout << (int)round(ans) << "\n" ; // print an Integer
		}
	}
    return 0 ;
}


