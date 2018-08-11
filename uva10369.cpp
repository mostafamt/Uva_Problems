/* @author : mostafa
 * created : 2018-08-10 13:54
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
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
};

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    cout << fixed << setprecision(2) ;
    int tc , s , p ;
    vector<pair<double,ii> > edgeList ; 
    cin >> tc ;
    while( tc-- ){
        cin >> s >> p ;
        ii a[p];
        forn(i,p){
            cin >> a[i].fi >> a[i].se ;
        }
        for(int i = 0 ; i < p ; i++){
            for(int j = i+1 ; j < p ; j++){
                int x = a[i].fi - a[j].fi ;
                int y = a[i].se - a[j].se ;
                double w = sqrt( x*x + y*y );
                edgeList.pb( {w,{i,j}} );
            }
        }
        int num = 1 ;
        double ans = 0 ;
        sort( all(edgeList) );
        UnionFind uf(p);
        int sz = (int)( edgeList.size() );
        for(int i = 0 ; i < sz ; i++){
            double w = edgeList[i].fi ;
            int u = edgeList[i].se.fi ;
            int v = edgeList[i].se.se ;
            if( !uf.isSameSet(u,v) ){
                uf.unionSet(u,v);
                if( num++ == p-s ){
                    ans = w ;
                    break ;
                }
            }
        }
        cout << ans << '\n' ;
        edgeList.clear();
    }
    return 0 ;
}


