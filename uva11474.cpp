#include <iostream>
#include <vector>
#include <cmath>
using namespace std ;
typedef vector<int> vi ;

// don't forget to define a double varible for sqrt return , it wasted 1 hour from my time

class UnionFind {
private:
	vi p , rank ;
	int numSets ;
public:
	UnionFind(int N){
		numSets = N ;
		rank.assign(N,0);
		p.assign(N,0);
		for(int i = 0 ; i < N ; i++){
			p[i] = i ;
		}
	}
	int findSet(int i){
		return (p[i] == i) ? i : p[i] = findSet(p[i]) ;
	}
	bool isSameSet(int i , int j){
		return findSet(i) == findSet(j) ;
	}
	void unionSet(int i , int j){
		if(!isSameSet(i,j)){
			numSets-- ;
			int x = findSet(i) ;
			int y = findSet(j) ;
			if( rank[x] > rank[y] ){
				p[y] = x ;
			} else{
				p[x] = y ;
				if( rank[x] == rank[y] ){
					rank[y]++ ;
				}
			}
		}
	}
	int numDisjointSets(){
		return numSets ;
	}
} ;



int main()
{
	int tc ;
	int n , m , k , d , b , x , y ;
	cin >> tc ;
	while(tc--){
		cin >> n >> m >> k >> d ;
		vector< pair<int,int> > trees[n+m] ;
		int idx = 0 ;
		for(int i = 0 ; i < m ; i++){
			cin >> x >> y ;
			trees[idx++].push_back( make_pair(x,y) ) ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> b ;
			while(b--){
				cin >> x >> y ;
				trees[idx].push_back( make_pair(x,y) ) ;
			}
			idx++ ;
		}
	
		UnionFind uf(n+m) ;
		for( int i = 0 ; i < n+m ; i++){
			for( int j = 0 ; j < n+m ; j++){
				if(i == j){
					continue ;
				}
				bool state = true ;
				for(int x = 0 ; x < (int)trees[i].size() && state ; x++){
					for(int y = 0 ; y < (int)trees[j].size() && state ; y++){
						int x1 = trees[i][x].first ;
						int y1 = trees[i][x].second ;
						int x2 = trees[j][y].first ;
						int y2 = trees[j][y].second ;
						double dist = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) ;
						if( i < m || j < m ){
							if(dist <= d ){
								uf.unionSet(i,j) ;
								state = false ;
							}
						} else {
							if( dist <= k ){
								uf.unionSet(i,j) ;
								state = false ;
							}
						}
					}
				}

			}
		}

		bool status = false ;
		for( int i = 0 ; i < m ; i++){
			if( uf.isSameSet(m,i) ){
				status = true ;
				break ;
			}
		}
		if( status ){
			cout << "Tree can be saved :)" << "\n" ;
		} else {
			cout << "Tree can't be saved :(" << "\n" ;
		}
	}
	return 0 ;
}
