/* @author : mostafa
 * created : 2018-09-28 11:34
 */
#include <iostream>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define INF (int)1e9
#define ll long long 

vector<vector<ii>> adjList ;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n , s = 1 ;
    while ( cin >> n ){
        adjList.clear();
        adjList.resize(n);
        int a[n];
        forn(i,n) cin >> a[i];
        int E ;
        cin >> E ;
        int u , v ;
        forn(i,E){
            cin >> u >> v ;
            u--;v--;
            int d = a[v] - a[u] ;
            d = d * d * d ;
            adjList[u].pb( {v,d} );
        }
        vector<int> dist (n,INF);
        if(n) dist[0] = 0 ;
        /* dist[0] = 0 ; */
        bool modified = true ;
        for(int i = 0 ; i < n-1 && modified ; i++){
            modified = false ;
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < (int)adjList[j].size() ; k++){
                    ii h = adjList[j][k] ;
                    if( dist[h.fi] > dist[j] + h.se && dist[j] != INF ){
                        dist[h.fi] = dist[j] + h.se ;
                        modified = true ;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < (int) adjList[i].size() ; j++){
                ii h = adjList[i][j];
                if( dist[h.fi] > dist[i] + h.se && dist[i] != INF ){
                    dist[h.fi] = -INF ;
                }
            }
        }
        int q ;
        cin >> q ;
        int x ;
        cout << "Set #" << s++ << '\n' ;
        while( q-- ){
            cin >> x ;
            dist[x-1] < 3 || dist[x-1] == INF ? 
                cout << "?" : cout << dist[x-1] ;
            cout << '\n' ;
        }
    }
	
    return 0 ;
}
