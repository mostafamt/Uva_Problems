/* @author : mostafa
 * created : 2018-06-12 15:35
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	string s ;
	while( cin >> s , s.empty() == false ){
		int m = atoi(s.c_str() );
		s.clear();
		char c ;
		vector< pair<int,int> > ones ;
		vector< pair<int,int> > threes ;
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> c ;
				if( c == '1' ){
					ones.push_back( {i,j}  );
				} else if( c == '3' ){
					threes.push_back( {i,j}  );
				}
			}
		}
		int mx = INT_MIN ;
		for(int i = 0 ; i < (int)ones.size() ; i++){
			int mn = INT_MAX ;
			for(int j = 0 ; j < (int)threes.size() ; j++){
				int x1 = ones[i].first ;
				int y1 = ones[i].second ;
				int x2 = threes[j].first ;
				int y2 = threes[j].second ;
				int dist = abs( x1 - x2 ) + abs( y1 - y2 ) ;
				mn = min( mn , dist );
			}
			mx = max( mx , mn );
		}
		cout << mx << "\n" ;

	}
    return 0 ;
}


