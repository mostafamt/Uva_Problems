/* @author : mostafa
 * created : 2018-06-11 00:02
 */
#include <iostream>
#include <algorithm>
using namespace std ;

int getlen( int value ){
	int len = 0 ;
	while( value ){
		len++ ;
		value /= 10 ;
	}
	return len ;
}

void format_output( int val , int num , int den , bool sign ){
	int len_val = getlen(val) ;
	int len_num = getlen(num) ;
	int len_den = getlen(den) ;
	int len_fraction = max( len_num , len_den );
	if( num == 0 ){
		if( sign ){
			cout << "- " << val << "\n" ;
		} else {
			cout << val << "\n" ;
		}
	} else {
		if( sign ){
			int rem = len_fraction - len_num ;
			for( int i = 0 ; i < len_val+2+rem ; i++){
				cout << " " ;
			}
			cout << num << "\n" ;

			cout << "- " ;
			if( val ){
				cout << val ;
			}
			for(int i = 0 ; i < len_fraction ; i++){
				cout << "-" ;
			}
			cout << "\n" ;

			rem = len_fraction - len_den ;
			for(int i = 0 ; i < len_val+2+rem ; i++){
				cout << " " ;
			}
			cout << den << "\n" ;
		} else {
			int rem = len_fraction - len_num ;
			for(int i = 0 ; i < len_val+rem ; i++){
				cout << " " ;
			}
			cout << num << "\n" ;

			if( val ){
				cout << val ;
			}
			for(int i = 0 ; i < len_fraction ; i++){
				cout << "-" ;
			}
			cout << "\n" ;

			rem = len_fraction - len_den ;
			for(int i = 0 ; i < len_val+rem ; i++){
				cout << " " ;
			}
			cout << den << "\n" ;
		}
	}
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , c = 1 ;
	while( cin >> n , n ){
		int a[n] ;
		int num = 0 ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			num += a[i] ;
		}
		bool neg = false ;
		if( num < 0 ){
			num *= -1 ;
			neg = true ;
		}
		int x = num / n ;
		num %= n ;
		if( num > 0 ){
			int gcd = __gcd(num , n ) ;
			num /= gcd ;
			n /= gcd ;
		}
		cout << "Case " << c++ << ":\n" ; 
		format_output( x , num , n , neg ) ;
	}
    return 0 ;
}


