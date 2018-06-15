/* @author : mostafa
 * created : 2018-06-14 13:50
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
double EPS = 0.000001 ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int v , vo ;
	while( cin >> v >> vo , v ){
		if( v <= vo ){
			cout << "0\n" ;
			continue ;
		}
		int n = 1 ;
		double new_v = v ;
		vector< pair<double,int> > vec ;
		while( new_v > vo ){
			double d = 0.3 * sqrt( new_v - vo );
			double len = d * n ;
			vec.push_back( {len,n} );

			new_v = (double)v / ++n ;
		}
		sort( vec.begin() , vec.end() );
		int size = (int)vec.size();
		double longest = vec[size-1].first ;
		bool status = false ;
		for(int i = 0 ; i < size-1 ; i++){
			if( abs( vec[i].first - longest ) <= EPS ){
				status = true ;
			}
		}
		if( !status ){
			cout << vec[size-1].second << "\n" ;
		} else {
			cout << "0\n" ;
		}
	}
    return 0 ;
}


