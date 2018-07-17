/* @author : mostafa
 * created : 2018-07-17 17:28
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef vector<int> vi ;

vector<pair<int,pair<int,int>>> edgeList ;


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
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int V , E ;
    while( cin >> V >> E , V ){
        int u , v , w ;
        edgeList.clear();
        forn(i,E){
            cin >> u >> v >> w ;
            edgeList.push_back( {w,{u,v}} );
        }
        sort( edgeList.begin() , edgeList.end() );
        UnionFind uf(V);
        vector<int> ans ;
        forn(i,E){
            pair<int,pair<int,int>> p = edgeList[i];
            int weight = p.first , x = p.second.first , y = p.second.second ;
            if( !uf.isSameSet(x,y) ){
                uf.unionSet(x,y);
            } else {
                ans.push_back(weight);
            }
        }
        int size = (int)ans.size();
        if( size == 0 ){
            cout << "forest\n" ;
        } else {
            for(int i = 0 ; i < size ; i++){
                if( i+1 == size ){
                    cout << ans[i] << '\n' ;
                } else {
                    cout << ans[i] << " " ;
                }
            }
        }
    }
     
    return 0 ;
}


