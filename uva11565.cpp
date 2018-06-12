/* @author : mostafa
 * created : 2018-06-12 18:52
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
	cin >> tc ;
	while( tc-- ){
		int a , b , c ;
		cin >> a >> b >> c ;
		bool state = true ;
		for(int x = -22 ; x < 22 && state ; x++){
			for(int y = -100 ; y < 100 && state ; y++){
				for(int z = -100 ; z < 100 && state ; z++){
					if( x != y && y != z && z != x && 
							x+y+z == a             && 
							x*y*z == b             &&
							x*x + y*y + z*z == c ){
						state = false ;
						cout << x << " " << y << " " << z << "\n" ;
					}
				}
			}
		}
		if( state ){
			cout << "No solution.\n" ;
		}
	}
    return 0 ;
}


