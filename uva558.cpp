/* @author : mostafa
 * created : 2018-09-27 20:51
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
typedef vector<int> vi ;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc , V , E ;
    cin >> tc ;
    while( tc-- ){
        cin >> V >> E ;
        vector<vector<ii>> adjList (V);
        int u , v , w ;
        forn(i,E) cin >> u >> v >> w , adjList[u].pb({v,w});
        vi dist(V,INF);
        dist[0] = 0 ;
        bool conducted = true ;
        for(int i = 0 ; i < V-1 && conducted ; i++){
            bool conducted = false ;
            for(int j = 0 ; j < V ; j++){
                for(int k = 0 ; k < (int) adjList[j].size() ; k++){
                    ii d = adjList[j][k];
                    if( dist[d.fi] > dist[j] + d.se ){
                        dist[d.fi] = dist[j] + d.se ;
                        conducted = true ;
                    }
                }
            }
        }
        bool has_negative_cycle = false ;
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < (int)adjList[i].size() ; j++){
                ii d = adjList[i][j];
                if( dist[d.fi] > dist[i] + d.se ){
                    has_negative_cycle = true ;
                    break ;
                }
            }
        }
        has_negative_cycle ? cout << "possible\n" : cout << "not possible\n" ;
    }
    
	
    return 0 ;
}
