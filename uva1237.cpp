/* @author : mostafa
 * created : 2018-06-06 15:40
 */
#include <iostream>
#include <string>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int tc ;
	cin >> tc ;
	int c = 0 ;
	while( tc-- ){
		if( c > 0 ){
			cout << "\n" ;
		}
		c++ ;
		int d ;
		cin >> d ;
		pair<pair<int,int> , string> a[d] ;
		string name ;
		int low , high ;
		for(int i = 0 ; i < d ; i++){
			cin >> name >> low >> high ;
			a[i] = make_pair( make_pair(low,high) , name ) ;
		}
		int q , p ;
		cin >> q ;
		while( q-- ){
			cin >> p ;
			int sum = 0 ;
			int idx = -1 ;
			for( int i = 0 ; i < d ; i++){
				if( p >= a[i].first.first && p <= a[i].first.second ){
					sum++ ;
					idx = i ;
				}
			}
			if( sum == 1 ){
				cout << a[idx].second << "\n" ;
			} else {
				cout << "UNDETERMINED\n" ;
			}
		}
	}
     
    return 0 ;
}


