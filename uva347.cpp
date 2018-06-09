/* @author : mostafa
 * created : 2018-06-09 16:01
 */
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#define MAX (int)1e7
using namespace std ;

template <typename T>
string number_to_string(T number)
{
	ostringstream ss ;
	ss << number ;
	return ss.str() ;
}

bool valid(string s)
{
	int idx = 0 ;
	int size = s.size() ;
	int num[10];
	memset( num , 0 , sizeof(num) );
	for(int i = 0 ; i < (int)s.size() ; i++){
		num[s[i]-'0']++ ;
		if( num[s[i]-'0'] > 1 ){
			return false ;
		}
	}
	int occ[size] ;
	memset( occ , 0 , sizeof(occ) );
	occ[idx]++ ;
	idx += s[idx]-'0' ;
	idx = idx % size ;
	while( idx != 0 ){
		for( int i = 0 ; i < size ; i++){
			if( occ[i] > 1 ){
				return false ;
			}
		}
		occ[idx]++ ;
		idx += s[idx]-'0' ;
		idx = idx % size ;
	}
	for(int i = 0 ; i < size ; i++){
		if( occ[i] != 1 ){
			return false ;
		}
	}
	return true ;
}

int a[MAX] ;
int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int n , c = 1 ;
	while( cin >> n , n ){
		if( !a[n] ) {
			for(int i = n ; i < MAX ; i++){
				string s = number_to_string(i) ;
				if( valid(s) ){
					for( int j = n ; j <= i ; j++){
						a[j] = i ;
					}
					break ;
				}
			}
		}
		cout << "Case " << c++ << ": " << a[n] << "\n" ;
	}
    return 0 ;
}


