/* @author : mostafa
 * created : 2018-08-09 17:17
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;
#define PB push_back
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define viii vector<iii>
#define fi first 
#define se second
#define all(x)   (x).begin(),(x).end() 
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
    int tc , n , r ;
    vector< pair< double , pair<int,int> > > edgeList ;
    cin >> tc ;
    for(int t = 1 ; t <= tc ; t++){
        cin >> n >> r ;
        ii a[n];
        for(int i = 0 ; i < n ; i++){
            cin >> a[i].fi >> a[i].se ;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int x = a[i].fi - a[j].fi , y = a[i].se - a[j].se ;
                double w = sqrt( x*x + y*y );
                edgeList.PB( { w , {i,j} } );
            }
        }
        int num_of_state = 1 ;
        double X = 0 , Y = 0 ;
        sort( all(edgeList) );
        UnionFind uf(n);
        for(auto it : edgeList){
            double w = it.fi ; 
            int u = it.se.fi , v = it.se.se ;
            if( !uf.isSameSet(u,v) ){
                uf.unionSet(u,v);
                if( w <= r ){
                    X += w ;
                } else {
                    num_of_state++ ;
                    Y += w ;
                }
            }
        }
        cout << "Case #" << t << ": " ;
        cout << num_of_state << " " << round(X) << " " << round(Y) << '\n' ;
        edgeList.clear();
    }
    return 0 ;
}


