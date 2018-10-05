/* @author : mostafa
 * created : 2018-10-05 18:38
 */
#include <iostream>
#include <vector>
#include <string.h>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back
#define INF (int)1e9

vector<vector<int>> adjList ;
vector<int> Energy ;
vector<bool> marked ;
int n ;

bool reachable(int i)
{
    marked[i] = true ;
    if( i == n-1 ){
        return true ;
    }
    for(int j = 0 ; j < (int)adjList[i].size() ; j++){
        int f = adjList[i][j];
        if( !marked[f] && reachable(f) ){
            return true ;
        }
    }
    return false ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while( cin >> n , n != -1 ){
        adjList.clear();
        adjList.resize(n);
        Energy.clear();
        Energy.resize(n);
        int m , x ;
        forn(i,n){
            cin >> Energy[i] ;
            // invert signs to implement negative cycle
            Energy[i] *= -1 ;
            cin >> m ;
            forn(j,m){
                cin >> x ;
                x-- ;
                adjList[i].pb(x);
            }
        }
        // Bellman-Ford
        vector<int> dist(n,INF);
        dist[0] = -100 ;
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < (int) adjList[j].size() ; k++){
                    int f = adjList[j][k];
                    if( dist[j] + Energy[f] < 0 ){
                        dist[f] = min( dist[f] , dist[j] + Energy[f] );
                    }
                }
            }
        }
        bool status = false ;
        if( dist[n-1] < 0 ){
            status = true ;
        } else {
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < (int) adjList[i].size() ; j++){
                    int f = adjList[i][j] ;
                    // negative cycle && Energy must be < 0 
                    if( dist[i] + Energy[f] < 0 && dist[f] > dist[i] + Energy[f] ){
                        marked.clear();
                        marked.resize(n);
                        if( reachable(i) ){
                            status = true ;
                        }
                    }
                }
            }
        }
        status ? cout << "winnable\n": cout << "hopeless\n" ;
    }
    return 0 ;
}


