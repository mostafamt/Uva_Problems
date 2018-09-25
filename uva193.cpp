/* @author : mostafa
 * created : 2018-09-21 09:56
 */
#include <iostream>
#include <vector>
#include <bitset>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;

vector<int> cur_blacks , best_blacks ;
bitset<102> black ;
vector<vector<int>> adjList ;
int V , E ;


bool can_be_black(int v)
{
    for(int w : adjList[v] ){
        if( black[w] ){
            return false ;
        }
    }
    return true ;
}

void backtrack(int cur)
{
    if( cur == V ){
        if( cur_blacks.size() > best_blacks.size() ){
            best_blacks = cur_blacks ;
        }
        return ;
    }
    if( V - cur + cur_blacks.size() <= best_blacks.size() ){
        return ; // no need to check other vertices ,thus return 
    }
    if( can_be_black(cur) ){
        cur_blacks.pb(cur);
        black[cur] = true ;
        backtrack(cur+1);
        cur_blacks.pop_back();
        black[cur] = false ;
    }
    backtrack(cur+1);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc , u , v ;
    cin >> tc ;
    while (tc--){
        cin >> V >> E ;
        adjList.clear();
        adjList.resize(V);
        best_blacks.clear();
        for(int i = 0 ; i < E ; i++){
            cin >> u >> v ;
            u--; v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        backtrack(0);
        int sz = (int)best_blacks.size();
        cout << sz << '\n' ;
        for(int i = 0 ; i < sz ; i++){
            if( i == sz -1 ){
                cout << best_blacks[i] + 1 << '\n' ;
            } else {
                cout << best_blacks[i] + 1 << " " ;
            }
        }
    }
	
    return 0 ;
}



