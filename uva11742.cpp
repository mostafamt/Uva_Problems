/* @author : mostafa
 * created : 2018-06-14 16:13
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n)  for(int i = 0 ; i < n ; i++)


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int n , m ;
	while( cin >> n >> m , n ){
		pair<int,int> constraints[n][n] ;
		forn(i,n) forn(j,n) { constraints[i][j] = {-1,-1}; }
		int a , b , c ;
		bool can = true ;
		for(int i = 0 ; i < m ; i++){
			cin >> a >> b >> c ;
			if( !can ) continue ;
			if( a == b ) continue ;
			if( a > b ){ // swap 
				a ^= b ;
				b ^= a ;
				a ^= b ;
			}

			int from = 0 , to = 0 ;
			if( c > 0 ){
				from = 1 ;to = c ;
			} else {
				from = abs(c) , to = n-1 ;
			}

			if( constraints[a][b].first == -1 ){ // first time constraint
				constraints[a][b] = {from,to};
			} else {
				int old_from = constraints[a][b].first ;
				int old_to = constraints[a][b].second ;
				pair<int,int> tmp[] = { {from,to} , {old_from,old_to} };
				sort( tmp , tmp+2 );
				if( tmp[0].second >= tmp[1].first ){ // intersect
					int new_from = tmp[1].first ;
					int new_to = tmp[0].second ;
					// update it
					constraints[a][b] = { new_from , new_to };
				} else {
					can = false ;
					constraints[a][b] = {0,0};
				}
			}
		}
		pair< pair<int,int> , pair<int,int> > linear[m] ;
		int idx = 0 ;
		forn(i,n)forn(j,n){
			if( constraints[i][j].first != -1 && constraints[i][j].first != 0 ){
				linear[idx++] = {{i,j},{constraints[i][j].first , constraints[i][j].second}};
			}
		}
		int p [] = {0,1,2,3,4,5,6,7};
		int ans = 0 ;
		int sum = 0 ;
		do{
			bool state = true ;
			for(int i = 0 ; i < idx ; i++){
				int u = linear[i].first.first ;
				int v = linear[i].first.second ;
				int from = linear[i].second.first ;
				int to = linear[i].second.second ;
				// search for positions
				int pu = -1 , pv = -1 ;
				for(int j = 0 ; j < n ; j++){
					if( p[j] == u ){
						pu = j ;
					}
					if( p[j] == v ){
						pv = j ;
					}
				}
				int distance = abs( pu - pv );
				bool status = ( distance >= from && distance <= to ) ;
				if( !status ){
					state = false ;
					break ;
				}
			}
			if( state ){
				sum++ ;
			}

		} while( next_permutation(p,p+n) );
		if( !can ){
			cout << "0\n" ;
		} else {
			cout << sum << "\n" ;
		}

	}
     
    return 0 ;
}


