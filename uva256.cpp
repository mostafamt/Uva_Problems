#include <iostream>
#include <vector>
using namespace std ;

int main()
{
	cin.sync_with_stdio(false) ;
	cin.tie(0) ;
	vector<string> v2 = {"00","01","81"} ;
	vector<string> v4 = {"0000","0001","2025","3025","9801"} ;
	vector<string> v6 = {"000000","000001","088209","494209","998001"};
	vector<string> v8 = {"00000000","00000001","04941729","07441984","24502500",
		"25502500","52881984","60481729","99980001"};

	int x ;
	while( cin >> x ){
		if( x == 2 ){
			for(int i = 0 ; i < (int)v2.size() ; i++){
				cout << v2[i] << "\n" ;
			}
		} else if( x == 4 ){	
			for(int i = 0 ; i < (int)v4.size() ; i++){
				cout << v4[i] << "\n" ;
			}
		} else if( x == 6 ){	
			for(int i = 0 ; i < (int)v6.size() ; i++){
				cout << v6[i] << "\n" ;
			}
		} else if( x == 8 ){
			for(int i = 0 ; i < (int)v8.size() ; i++){
				cout << v8[i] << "\n" ;
			}
		}
	}
	return 0 ;
}
