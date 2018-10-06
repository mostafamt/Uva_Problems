/* @author : mostafa
 * created : 2018-10-06 03:39
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define iii tuple<int,int,int>
#define pb push_back
#define INF (int)1e9

vector<vector<iii>> adjList ;
map<string,int> mp ;
string from , to ;
int count ;


int Dijkstra()
{
    priority_queue< iii , vector<iii> , greater<iii> > pq ;
    vector<int> dist[count];
    forn(i,count) dist[i] = vector<int>(26,INF);
    forn(i,26){
        dist[ mp[from] ][i] = 0 ;
        pq.push( {0 , mp[from] , i } );
    }
    while( !pq.empty() ){
        iii fr = pq.top() ; pq.pop();
        int d1 = get<0>(fr);
        int u1 = get<1>(fr);
        int c1 = get<2>(fr);
        if( dist[u1][c1] < d1 ){
            continue ;
        }
        for(int j = 0 ; j < (int) adjList[u1].size() ; j++){
            iii tu = adjList[u1][j] ;
            int u2 = get<0>(tu);
            int d2 = get<1>(tu);
            int c2 = get<2>(tu);
            if( c1 != c2 && dist[u2][c2] > dist[u1][c1] + d2 ){
                dist[u2][c2] = dist[u1][c1] + d2 ;
                pq.push( {dist[u2][c2] , u2 , c2} );
            }
        }
    }
    int ans = INF ;
    forn(i,26){
        ans = min( ans , dist[ mp[to] ][i] ) ;
    }
    return ans ;
}

void addEdge( int u , int v , string word )
{
    int c = word[0] - 'a' ;
    int len = (int)word.size();
    adjList[u].pb( {v,len,c} );
    adjList[v].pb( {u,len,c} );
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n ;
    string s1 , s2 , w ;
    while( cin >> n , n ){
        adjList.clear();
        adjList.resize(2*n+1);
        mp.clear();
        count = 1 ;
        cin >> from >> to ;
        forn(i,n){
            cin >> s1 >> s2 >> w ;
            if( !mp[s1] ){
                mp[s1] = count++ ;
            }
            if( !mp[s2] ){
                mp[s2] = count++ ;
            }
            addEdge( mp[s1] , mp[s2] , w );
        }
        if( mp[from] == 0 || mp[to] == 0 ){
            cout << "impossivel\n" ;
            continue ;
        }
        int ans = Dijkstra();
        if( ans == INF ){
            cout << "impossivel\n" ;
        } else {
            cout << ans << '\n' ;
        }
    }
	
    return 0 ;
}






