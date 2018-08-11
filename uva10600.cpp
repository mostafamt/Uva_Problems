/* @author : mostafa
 * created : 2018-08-10 15:38
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi ;
typedef vector<pair<int,ii> > viii ;

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

    void reset(int N)
    {
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
};


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , N , E ;
    viii edgeList ;
    cin >> tc ;
    while( tc-- ){
        cin >> N >> E ;
        int u , v , w ;
        int ans = 0 ;
        forn(i,E){
            cin >> u >> v >> w ;
            u-- ; v--;
            edgeList.pb( {w,{u,v}} );
            ans += w ;
        }
        sort( all(edgeList) );
        vi a ;
        int best = 0 ;
        UnionFind uf(N);
        int sz = (int)(edgeList.size() );
        for(int i = 0 ; i < sz ; i++){
            w = edgeList[i].fi ;
            u = edgeList[i].se.fi ;
            v = edgeList[i].se.se ;
            if( !uf.isSameSet(u,v) ){
                uf.unionSet(u,v);
                best += w ;
                a.pb( i );
            }
        }
        int second_best = INT_MAX ;
        for(int i = 0 ; i < (int)(a.size() ) ; i++){
            uf.reset(N);
            int sum = 0 ;
            int edges = 0 ;
            for(int j = 0 ; j < sz ; j++){
                w = edgeList[j].fi ;
                u = edgeList[j].se.fi ;
                v = edgeList[j].se.se ;
                if( !uf.isSameSet(u,v) && j != a[i] ){
                    uf.unionSet(u,v); 
                    sum += w ;
                    edges++ ;
                }
            }
            if( edges == N-1 ){
                second_best = min( second_best ,sum);
            }
        }
        cout << best << " " << second_best << '\n' ;
        edgeList.clear();
    }
    return 0 ;
}


