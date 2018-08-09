/* @author : mostafa
 * created : 2018-08-05 15:03
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef vector<int> vi ;

class UnionFind {
private:
	vi p , rank , num ;
	int numSets ;
public:
	UnionFind(int N){
		numSets = N ;
		rank.assign(N,0);
		p.assign(N,0);
        num.assign(N,1);
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
                num[x] += num[y] ;
			} else{
				p[x] = y ;
                num[y] += num[x];
				if( rank[x] == rank[y] ){
					rank[y]++ ;
				}
			}
		}
	}

    // return number of elements in this set
    int get_num(int u){
        return num[u] ;
    }

	int numDisjointSets(){
		return numSets ;
	}
};

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    map<string,int> mp ;
    while( tc-- ){
        mp.clear();
        int m ;
        cin >> m ;
        string u , v ;
        int count = 0 ;
        UnionFind uf(2*m);
        forn(i,m) {
            cin >> u >> v ;
            if( mp[u] == 0 ){
                mp[u] = ++count ;
            }
            if( mp[v] == 0 ){
                mp[v] = ++count ;
            }
            uf.unionSet(mp[u] , mp[v] );
            int w = uf.findSet(mp[u]);
            int sum  = uf.get_num(w);
            cout << sum << '\n' ;
        }
    }
    return 0 ;
}


