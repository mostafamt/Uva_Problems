/* @author : mostafa
 * created : 2018-07-12 16:48
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n ;
    char c ;
    int u , v , successful , unsuccessful ;
    string s ; 
    cin >> tc ;
    getline(cin , s ); getline(cin , s );
    s.clear();
    int num = 0 ;
    while( tc-- ){
        if( num > 0 ){
            cout << '\n' ;
        }
        num++ ;
        cin >> n ;
        getline(cin,s);
        s.clear();
        UnionFind uf(n+1);
        successful = unsuccessful = 0 ;
        while( getline(cin,s) , s.size() > 3 ){
            stringstream ss ;
            ss << s ;
            s.clear();
            ss >> c >> u >> v ;
            if( c == 'c' ){
                uf.unionSet(u,v);
            } else {
                uf.isSameSet(u,v) ? successful++ : unsuccessful++ ;
            }
        }
        s.clear();
        cout << successful << "," << unsuccessful << '\n' ;
        
    }
    return 0 ;
}


