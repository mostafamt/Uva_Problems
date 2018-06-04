#include <iostream>
#include <vector>
#include <cstring>
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
	int tc , n , m , x , y ;
	cin >> tc ;
	while(tc--){
		cin >> n >> m ;
		UnionFind uf(n+1) ;
		while(m--){
			cin >> x >> y ;
			uf.unionSet(x,y) ;
		}
		int a[n+1] ;
		memset( a , 0 , sizeof(a) ) ;
		int max = 1 ;
		for(int i = 0 ; i <= n ; i++){
			int u = uf.findSet(i) ;
			a[u]++ ;
			if(a[u] > max){
				max = a[u] ;
			}
		}
		cout << max << "\n" ;
	}
	return 0 ;
}
