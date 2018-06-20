/* @author : mostafa
 * created : 2018-06-20 15:20
 */
#include <iostream>
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
		double work_per_family = (x+y)/3.0 ;
		if( x >= 2*work_per_family ){
			// in any case , one family can't get greater than input z
			cout << z << "\n" ;
		} else if( x <= work_per_family ){
			// in any case , one family can't get negative
			cout << 0 << "\n" ;
		} else {
			double ans = z*((x-work_per_family)/work_per_family) ;
			cout << (int)(ans+0.1) << "\n" ; // use 0.1 to improve precision , for example 19.9999999999234
			// should give 20 , if you will not use 0.1 will give 19 
			// another solution , you can use printf("%.lf" , ans ) .
		}
	}
    return 0 ;
}


