/* @author : mostafa
 * created : 2018-10-06 00:44
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <cstring>
#include <queue>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define iii tuple<int,int,int>
#define pb push_back
#define INF (int)1e9
typedef vector<int> vi ;

vector<vector<iii>> adjList ;
int t[100];

void addEdge( int from , int to , int dist , int color)
{
    adjList[from].pb( {to,dist,color} );
    adjList[to].pb( {from,dist,color} );
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n , k ;
    string line ;
    vi a ;
    int zero_floor_color = -1 ;
    while( cin >> n >> k ){
        adjList.clear();
        adjList.resize(100);
        memset( t , 0 , sizeof t );
        forn(i,n) cin >> t[i] ;
        cin.ignore();
        forn(c,n){
            getline( cin , line );
            stringstream ss ;
            ss << line ;
            int x ;
            a.clear();
            while( ss >> x ){
                if( x == 0 ){
                    zero_floor_color = c ;
                }
                a.pb(x);
            }
            int sz = (int)a.size();
            for(int i = 0 ; i < sz ; i++){
                for(int j = i+1 ; j < sz ; j++){
                    int from = a[i] , to = a[j] ;
                    int dist = ( a[j] - a[i] ) * t[c] ;
                    int color = c ;
                    addEdge( from , to , dist , color );
                }
            }
        }
        if( zero_floor_color == -1 ){
            cout << "IMPOSSIBLE\n" ;
            continue ;
        } else if( k == 0 ){
            cout << 0 << '\n' ;
            continue ;
        }
        // Dijkstra's algorithm
        priority_queue<iii,vector<iii> , greater<iii> > pq ;
        pq.push( {0,0,zero_floor_color} );
        vi dist(100,INF);
        dist[0] = 0 ;
        while( !pq.empty() ){
            iii front = pq.top(); pq.pop();
            int d1 = get<0>(front);
            int from = get<1>(front);
            int c1 = get<2>(front);
            if( d1 > dist[from] ){
                continue ;
            } 
            for(int j = 0 ; j < (int)adjList[from].size() ; j++){
                iii tu = adjList[from][j];
                int to = get<0>(tu);
                int d2 = get<1>(tu);
                int c2 = get<2>(tu);
                int transition = 0 ;
                if( c1 != c2 && from != 0 ){
                    transition = 60 ;
                } 

                if( dist[to] > dist[from] + d2 + transition ){
                    dist[to] = dist[from] + d2 + transition ;
                    pq.push( {dist[to] , to , c2 } );
                }
            }
        }
        if( dist[k] == INF ){
            cout << "IMPOSSIBLE\n" ;
        } else {
            cout << dist[k] << '\n' ;
        }
    }
	
    return 0 ;
}





