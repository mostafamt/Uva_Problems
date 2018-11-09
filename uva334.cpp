/* @author : mostafa
 * created : 2018-11-09 04:41
 */
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define fi first 
#define se second
#define pb push_back
#define N 202

map <string,int> mp ;
string table[N];

int adjMat[N][N];
vector<pair<string,string>> ans ;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n ;
    int c = 0 ;
    while ( cin >> n , n ){
        c++ ;
        memset( adjMat , 0 , sizeof adjMat );
        mp.clear();
        int count = 1 ;
        forn(i,n){
            int m ;
            cin >> m ; 
            bool status = false ;
            string from , to ;
            for(int j = 0 ; j < m ; j++){
                if( !status ){
                    status = true ;
                    cin >> from ;
                    table[count] = from ;
                    mp[from] = count++ ;
                } else {
                    cin >> to ;
                    if( !mp[to] ){
                        table[count] = to ;
                        mp[to] = count++ ;
                    }
                    adjMat[mp[from]][mp[to]] = 1 ;
                    from = to ;
                }
            }
        }
        int q ; cin >> q ;
        forn(i,q){
            string from ,to ;
            cin >> from >> to ;
            adjMat[mp[from]][mp[to]] = 1 ;
        }

        for(int k = 0 ; k < count ; k++){
            for(int i = 0 ; i < count ; i++){
                for(int j = 0 ; j < count ; j++){
                    adjMat[i][j] |= ( adjMat[i][k] & adjMat[k][j] );
                }
            }
        }
        ans.clear();
        for(int i = 1 ; i < count ; i++){
            for(int j = 1 ; j < count ; j++){
                if( i == j ){
                    continue ;
                }
                if( i >= j && adjMat[i][j] == 0 && adjMat[j][i] == 0 ){
                    ans.pb( { table[i] , table[j] } );
                }
            }
        }
        int sz = ans.size();
        cout << "Case " << c << ", " ;
        if( sz == 0 ){
            cout << "no concurrent events." << '\n' ;
        } else if( sz == 1 ){
            cout << sz << " concurrent events:" << '\n' ;
            cout << "(" << ans[0].fi << "," << ans[0].se << ") \n" ;
        } else {
            cout << sz << " concurrent events:" << '\n' ; 
            cout << "(" << ans[0].fi << "," << ans[0].se << ") " ;
            cout << "(" << ans[1].fi << "," << ans[1].se << ") \n" ;
        }

    }
     
    return 0 ;
}

