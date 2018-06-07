/* @author : mostafa
 * created : 2018-06-07 17:04
 */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#define MAX 10000
using namespace std ;
// this type of problems is time consumer , about >= 4 hour
// it's accepted from second sumbission but it's very tedious
pair< pair<int,int> ,int> a[MAX] ;
int l , h , r ,idx = 0 ;
int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    string s ;
	int last = 0 ;
	while( getline( cin , s ) , !s.empty() ){
		stringstream ss ;
		ss << s ;
		ss >> l >> h >> r ;
		a[idx++] = make_pair( make_pair(l,h) , r ) ;
		last = max(last,r) ;
	}

	vector< pair< pair<int,int> ,int> > v ;
	int start = 0 ; 
	int height = 0 ;
	int exit_time = -1 ;
	int pre = 0 ;
	for(int i = 0 ; i < last ; i++){
		
		while( i == a[start].first.first ){
			// keep the height maximum
			if( a[start].first.second > height ){
				height = a[start].first.second ;
				exit_time = a[start].second ;
			}
			// add it to your bag
			v.push_back( a[start++] ) ;
		}

		// refine it
		for(int j = 0 ; j < (int)v.size() ; j++){
			if( v[j].second == i ){
				v.erase( v.begin()+j ) ;
			}
		}

		// if it finishes , it will be gotten the greatest height or 0 . 
		if( i == exit_time ){
			if( v.empty() ){
				height = 0 ;
				exit_time = i+1 ;
			} else {
				height = 0 ;
				for(int j = 0 ; j < (int)v.size() ; j++){
					if( v[j].first.second > height ){
						height = v[j].first.second ;
						exit_time = v[j].second ;
					}
				}
			}
		}
		if( height != pre ){
			cout << i << " " << height << " " ;
		}
		pre = height ;
	}
	cout << last << " " << 0 << "\n" ;

    return 0 ;
}


