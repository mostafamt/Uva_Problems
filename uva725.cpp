#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std ;

// don't put \n after each case , you will get PE by this way .
// you can put \n between each test case to avoid that .

template <typename T>
string number_to_string(T number)
{
	ostringstream tmp ;
 	tmp << number ;
	return tmp.str() ;
}

bool can(string s1 , string s2){
	int a[10] ;
	memset( a , 0 , sizeof(a) ) ;
	for(int i = 0 ; i < 5 ; i++){
		a[ s1[i]-'0' ]++ ;
		a[ s2[i]-'0' ]++ ;
	}
	for(int i = 0 ; i < 10 ; i++){
		if( a[i] > 1 ){
			return false  ;
		}
	}
	return true ;
}

int main()
{
	cout.sync_with_stdio(false);
	cout.tie(0);
	int n ;
	int sum = 0 ;
	int count = 0 ;
	while( cin >> n , n > 0 ){
		if( count > 0 ){
			cout << "\n" ;
		}
		count++ ;
		sum = 0 ;
		for(int i = 1000 ; i < 100000 ; i++){
			int x = i * n ;
			if( x > 99999 ){
				break ;
			}
			string s1 = number_to_string(i) ;
			string s2 = number_to_string(x) ;

			while( s1.size() < 5 ){
				s1 = '0'+s1 ;
			}

			while( s2.size() < 5 ){
				s2 = '0'+s2 ;
			}

			if( can( s1 , s2 ) ){
				cout << s2 << " / " << s1 << " = " << n << "\n" ;
				sum++ ;
			}
		}
		if( sum == 0 ){
			cout << "There are no solutions for " << n << ".\n" ;
		}
	}
	return 0 ;
}
