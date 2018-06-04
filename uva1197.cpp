#include <iostream>
#include <vector>
using namespace std ;
typedef vector<int> vi ;

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
	int n , m , k , x , y ;
	while( cin >> n >> m , n ){
		UnionFind uf(n+1) ;
		while(m--){
			cin >> k ;
			cin >> y ;
			while(--k){
				cin >> x ;
				uf.unionSet(x,y) ;
			}
		}
		int sum = 1 ;
		int x = uf.findSet(0) ;
		for(int i = 1 ; i <= n ; i++){
			if( x == uf.findSet(i) ){
				sum++ ;
			}
		}
		cout << sum << "\n" ;
	}
	return 0 ;
}
