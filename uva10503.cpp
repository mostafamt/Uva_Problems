/* @author : mostafa
 * created : 2018-09-21 03:27
 */
#include <iostream>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second

ii l , r ;
vector<ii> dominoes ;
int n , m ;
bool used[14] , found ;

void backtrack(int last , int num)
{
    if( num == n ){
        if( last == r.fi ){
            found = true ;
        }
        return ;
    }
    for(int i = 0 ; i < m ; i++){
        if( !used[i] && !found ){
            if( dominoes[i].fi == last ){
                used[i] = true ;
                backtrack( dominoes[i].se , num + 1 );
                used[i] = false ;
            } else if ( dominoes[i].se == last ){
                used[i] = true ;
                backtrack( dominoes[i].fi , num + 1 );
                used[i] = false ;
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while( cin >> n , n ){
        found = false ;
        cin >> m ;
        cin >> l.fi >> l.se ;
        cin >> r.fi >> r.se ;
        dominoes.resize(m);
        forn(i,m) cin >> dominoes[i].fi >> dominoes[i].se ;
        backtrack(l.se , 0 );
        found ? cout << "YES\n" : cout << "NO\n" ;
        
    }
	
    return 0 ;
}
