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
	int n , m , x , y ,c = 1 ;
	while(cin>>n>>m , n ){
		UnionFind uf(n);
		while(m--){
			cin >> x >> y ;
			uf.unionSet(x-1,y-1) ;
		}
		cout << "Case "<< c++ << ": " << uf.numDisjointSets() << "\n" ;
	}
	return 0 ;
}
