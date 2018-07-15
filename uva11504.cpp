/* @author : mostafa
 * created : 2018-07-15 06:16
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll ;

bool marked[100001];
vector<vector<int>>adjList (100001);
vector<int> order ;

void dfs(int u)
{
    marked[u] = true ;
    for(int v : adjList[u]){
        if(!marked[v]){
            dfs(v);
        }
    }
}


void topological_sort(int u)
{
    marked[u] = true ;
    for(int v : adjList[u]){
        if(!marked[v]){
            topological_sort(v);
        }
    }
    order.push_back(u);
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , n , m ;
    cin >> tc ;
    while( tc-- ){
        cin >> n >> m ;
        forn(i,n){
            adjList[i].clear();
        }
        int u , v ;
        forn(i,m){
            cin >> u >> v ;
            u-- , v-- ;
            adjList[u].push_back(v);
        }
        memset( marked , 0 , sizeof marked );
        for(int i = 0 ; i < n ; i++){
            if(!marked[i] ){
                topological_sort(i);
            }
        }
        int ans = 0 ;
        memset( marked , 0 , sizeof marked );
        int size = (int) order.size();
        for(int i = size-1 ; i >=0 ;i--){
            if(!marked[order[i]]){
                ans++;
                dfs(order[i]);
            }
        }
        cout << ans << '\n' ;
        order.clear();
    }
    return 0 ;
}


