/* @author : mostafa
 * created : 2018-10-15 18:23
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define INF (int)1e9
typedef long long ll ;
typedef vector<int> vi ;

int n , m , s , t , p ;
vector<vector<ii>> adjList1 , adjList2 ;
vector<int> dist1 , dist2 ;

vector<int> dijkstra(int source , vector<vector<ii>> & adjList )
{
    vi dist(n,INF);
    priority_queue<ii,vector<ii>,greater<ii>> pq ;
    dist[source] = 0 ;
    pq.push( {0,source} );
    while( !pq.empty() ){
        ii front = pq.top(); pq.pop();
        int d1 = front.fi ;
        int v1 = front.se ;
        if( dist[v1] < d1 ){
            continue ;
        }
        for(int i = 0 ; i < (int)adjList[v1].size() ; i++){
            ii h = adjList[v1][i];
            int v2 = h.fi ;
            int d2 = h.se ;
            if( dist[v1] + d2 < dist[v2] ){
                dist[v2] = dist[v1] + d2 ;
                pq.push( {dist[v2] , v2} );
            }
        }
    }
    return dist ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ;
    cin >> tc ;
    while( tc-- ){
        cin >> n >> m >> s >> t >> p ;
        s--; t--;
        adjList1.clear();
        adjList2.clear();
        adjList1.resize(n);
        adjList2.resize(n);
        int u , v , w ;
        forn(i,m){
            cin >> u >> v >> w ;
            u--; v--;
            adjList1[u].pb( {v,w} );
            adjList2[v].pb( {u,w} );
        }
        vector<int> dist1 = dijkstra(s,adjList1);
        vector<int> dist2 = dijkstra(t,adjList2);
        int max_toll = -1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < (int)adjList1[i].size() ; j++){
                int from = i , to = adjList1[i][j].fi ;
                int weight = adjList1[i][j].se ;
                if( dist1[from] + weight + dist2[to] <= p ){
                    max_toll = max( max_toll , weight );
                } 
            }
        }
        cout << max_toll << '\n' ;
    }
     
    return 0 ;
}

