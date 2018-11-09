/* @author : mostafa
 * created : 2018-11-09 05:59
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define M 55
#define INF (int)1e9
typedef vector<int> vi ;

map<string,int> mp ;
int adjMat[M][M];


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

void reset()
{
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < M ; j++){
            adjMat[i][j] = INF ;
        }
        adjMat[i][i] = 0 ;
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n , m ;
    int c = 0 ;
    while( cin >> n >> m , n ){
        c++ ;
        reset();
        mp.clear();
        UnionFind uf(n);
        string from , to ;
        int count = 1 ;
        forn(i,m){
            cin >> from >> to ;
            if( !mp[from] ){
                mp[from] = count++ ;
            }
            if( !mp[to] ){
                mp[to] = count++ ;
            }
            adjMat[mp[from]][mp[to]] = adjMat[mp[to]][mp[from]] = 1 ;
            int u = mp[from]-1 , v = mp[to] -1 ;
            uf.unionSet( u , v );
        }
        cout << "Network " << c << ": " ;
        if( uf.numDisjointSets() > 1 ){
            cout << "DISCONNECTED" << '\n' ;
            cout << '\n' ;
            continue ;
        }
        for(int k = 0 ; k < count ; k++){
            for(int i = 0 ; i < count ; i++){
                for(int j = 0 ; j < count ; j++){
                    int tmp = adjMat[i][k] + adjMat[k][j] ;
                    if( tmp < adjMat[i][j] ){
                        adjMat[i][j] = tmp ;
                    }
                }
            }
        }
        int ans = -1 ;
        for(int i = 0 ; i < count ; i++){
            for(int j = 0 ; j < count ; j++){
                if( adjMat[i][j] != INF ){
                    ans = max( ans , adjMat[i][j] );
                }
            }
        }
        cout << ans << '\n' ;
        cout << '\n' ;
    }
     
    return 0 ;
}

