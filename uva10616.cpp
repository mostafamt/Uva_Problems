/* @author : mostafa
 * created : 2019-02-07 04:23
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;

const int N = 202 ;
const int D = 22 ;
const int M = 12 ;

int a[210];
int n , q ;
int d , m ; 
int memo[N][D][M];

int fix(int x)
{
    return (x%d+d) % d ;
}

int dp(int idx , int sum , int cur)
{
    if( cur == m ){
        return sum % d == 0 ? 1 : 0 ;
    }
    if( idx == n ){
        return 0 ;
    }
    if( memo[idx][sum][cur] != -1 ){
        return memo[idx][sum][cur];
    }
    int take = dp( idx + 1 , fix( sum + a[idx] ) , cur + 1 );
    int leave = dp( idx + 1 , sum , cur );
    return memo[idx][sum][cur] = take + leave ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc = 0 ;
    while( cin >> n >> q , n ){
        cout << "SET " << ++tc << ":"<< '\n' ;
        forn(i,n) cin >> a[i] ;
        for(int Q = 1 ; Q <= q ; Q++){
            cin >> d >> m ;
            memset( memo , -1 , sizeof memo );
            int ans = dp(0,0,0);
            cout << "QUERY " << Q << ": " << ans << '\n' ;
        }
    }
     
    return 0 ;
}
