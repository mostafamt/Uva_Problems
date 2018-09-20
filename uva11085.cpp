/* @author : mostafa
 * created : 2018-09-20 02:33
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;

vector<int> v ;
bool mark[8][8] ;
vector<vector<int>> p ;
int a[8] , c ;
string line ;

bool check()
{
    for(int i = 0 ; i < 8 ; i++){
        int y = v[i] , x = i ;
            // check diganoals X
        for(int k = y-1 , l = x-1 ; k >= 0 && k < 8 && l >= 0 && l < 8 ; k--,l--){
            if( mark[k][l] ) return false ;
        }
        for(int k = y-1 , l = x+1 ; k >= 0 && k < 8 && l >= 0 && l < 8 ; k--,l++){
            if( mark[k][l] ) return false ;
        }
        for(int k = y+1 , l = x+1 ; k >= 0 && k < 8 && l >= 0 && l < 8 ; k++,l++){
            if( mark[k][l] ) return false ;
        }
        for(int k = y+1 , l = x-1 ; k >= 0 && k < 8 && l >= 0 && l < 8 ; k++,l--){
            if( mark[k][l] ) return false ;
        }
    }
    return true ;
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    forn(i,8) v.pb(i);
    int sum = 0 ;
    do{
        memset( mark , false , sizeof mark );
        for(int i = 0 ; i < 8 ; i++){
            mark[v[i]][i] = true ;
        }
        if( check() ){
            p.pb(v);
            sum++ ;
        }
    } while( next_permutation(all(v)) );

    while( getline(cin,line) ){
        stringstream ss ;
        ss << line ;
        forn(i,8) ss >> a[i] , a[i]--;
        int ans = 8 ;
        for(int i = 0 ; i < sum ; i++){
            vector<int> b = p[i];
            int moves = 0 ;
            for(int j = 0 ; j < 8 ; j++){
                if( a[j]-b[j] ) moves++ ;
            }
            ans = min( ans , moves );
        }
        cout << "Case " << ++c << ": " << ans << '\n' ;
    }

    return 0 ;
}
