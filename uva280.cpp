/* @author : mostafa
 * created : 2018-07-30 14:14
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std ;

vector<vector<int> > adjList ;
vector<bool> marked ;

int dfs(int u)
{
    marked[u] = true ;
    int sum = 1 ;
    for(int v : adjList[u]){
        if( !marked[v] ){
            sum += dfs(v);
        }
    }
    return sum ; 
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n , n ){
        adjList.resize(n+1);
        adjList.clear();
        string s ;
        cin.ignore();
        while( getline(cin,s) , s[0] != '0' ){
            stringstream ss ;
            ss << s ;
            int u , v ;
            ss >> u ;
            while( ss >> v , v ){
                adjList[u].push_back(v);
            }
        }
        int q , x ;
        cin >> q ;
        while( q-- ){
            marked.assign(n+1 , false );
            cin >> x ;
            int sum = 0 ;
            for(int y : adjList[x]){
                if( !marked[y] ){
                    sum += dfs(y);
                }
            }
            cout << n - sum ;
            for(int i = 1 ; i <= n ; i++){
                if(!marked[i]){
                    cout << " " << i ;
                }
            }
            cout << '\n' ; 
        }
    }
    return 0 ;
}


