/* @author : mostafa
 * created : 2018-06-14 17:43
 * This problem can be solved by precalculation . 
 * 9 mens requires 117,440,505 coconuts . 10 mens requires > 1e12 , this is sufficient .
 */
#include <iostream>
using namespace std ;


int main()
{
	cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int coconuts ;
	while( cin >> coconuts , coconuts != -1 ){
		bool state = true ;
		for(int mens = 10 ; mens >= 2 && state ; mens--){
			int num = coconuts ;
			bool status = true ;
			for( int i = 1 ; i <= mens && status ; i++){
				if( num % mens != 1 ){
					status = false ;
				} else {
					num -= 1 ;
					num -= num / mens ;
				}
			}
			if( status && num % mens == 0 ){
				cout << coconuts << " coconuts, " << mens << " people and 1 monkey\n" ;
				state = false ;
			}
		}
		if( state ){
			cout << coconuts << " coconuts, no solution\n" ;
		}
	}
    return 0 ;
}


