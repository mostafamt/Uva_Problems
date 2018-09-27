/* @author : mostafa
 * created : 2018-09-27 08:45
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define INF (int)1e9
typedef vector<int> vi ;
vector<vector<ii> > adjList ;
int r , c ;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

bool valid(int y , int x)
{
    if( y >= r || y < 0 || x >= c || x < 0 ){
        return false ;
    }
    return true ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ;
    cin >> tc ;
    while( tc-- ){
        cin >> r >> c ;
        adjList.clear();
        adjList.resize(r*c);
        int a[r][c];
        forn(i,r) forn(j,c) cin >> a[i][j] ;
        forn(i,r) forn(j,c){
            int from = i * c + j ;
            forn(k,4){
                int y = i+dy[k] , x = j+dx[k];
                if( valid(y,x) ){
                    int to = y * c + x ;
                    adjList[from].pb( {to,a[y][x]} );
                }
            }
        }
        vi dist(r*c,INF); dist[0] = a[0][0];
        priority_queue< ii , vector<ii> , greater<ii> > pq ;
        pq.push( {a[0][0],0} );

        while( !pq.empty() ){
            ii front = pq.top() ; pq.pop();
            int d = front.fi , u = front.se ;
            if( d > dist[u] ){
                continue ;
            }
            for(int j = 0 ; j < (int)adjList[u].size() ; j++){
                ii v = adjList[u][j];
                if( dist[v.first] > dist[u] + v.second ){
                    dist[v.first] = dist[u] + v.second ;
                    pq.push( { dist[v.first] , v.first } );
                }
            }
        }
        cout << dist[r*c-1] << '\n' ;
    }
    return 0 ;
}
