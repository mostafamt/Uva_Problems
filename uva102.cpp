#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <climits>
using namespace std ; 


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int len = 3 ;
	string s ;
	string bins[] = {"B","C","G"};
	map<string,int> mp ;
	mp["B"] = 0 ; mp["C"] = 2 ; mp["G"] = 1 ;
	while( getline(cin , s) , !s.empty() ){
		stringstream ss ;
		ss.clear() ;
		ss << s ;
		int a[len][len] ;
		for(int i = 0 ; i < len ; i++){
			for(int j = 0 ; j < len ; j++){
				ss >> a[j][i] ;
			}
		}
		string s[6] ;
		int ind = 0 ;
		int mn = INT_MAX ;
		int min_ind = -1 ;
		for(int i = 0 ; i < len ; i++){
			for(int j = 0 ; j < len ; j++){
				for(int k = 0 ; k < len ; k++){
					if( i==j || j==k || k==i ){
						continue ;
					}
					int move = 0 ;
					s[ind++] = bins[i]+bins[j]+bins[k] ;
					for(int x = 0 ; x < len ; x++){
						if( x == 0 ){
							continue ;
						}
						move += a[mp[bins[i]]][x] ;
					}

					for(int y = 0 ; y < len ; y++){
						if( y == 1 ){
							continue ;
						}
						move += a[mp[bins[j]]][y] ;
					}
					for(int z = 0 ; z < len ; z++){
						if( z == 2 ){
							continue ;
						}
						move += a[mp[bins[k]]][z] ;
					}
					if( mn > move ){
						mn = move ;
						min_ind = ind-1 ;
					}
				}
			}
		}
		cout << s[min_ind] << " " << mn << "\n" ; 
	}

	return 0 ;
}
