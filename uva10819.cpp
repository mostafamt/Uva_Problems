/* @author : mostafa
 * created : 2019-02-08 04:31
 */
#include <bits/stdc++.h>
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
const int N = 101 , M = 10001 ;
int weights[101] , values[101] ;
int n , m ; 
int dp[N][M];

int fun(int i, int w)
{
    if( w > m ){
        if( w - m > 200 ){
            return -1000 ;
        } else if( m <= 1800 ){
            return -1000 ;
        }
    }
    if( i == n ){
        if( w > m ){
            if( w - m > 200 ){
                return -1000 ;
            } else if( m <= 1800 || w <= 2000 ){
                return -1000 ;
            }
        }
        return 0 ;
    }
    if( dp[i][w] != -1 ){
        return dp[i][w] ;
    }
    int take = fun(i+1,w+weights[i]);
    int leave = fun(i+1, w);
    return dp[i][w] = max( leave , values[i]+take );
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while ( cin >> m >> n ){
        forn(i,n) cin >> weights[i] >> values[i] ;
        memset( dp , -1 , sizeof dp );
        int ans = fun(0,0);
        cout << ans << '\n' ;
    }
    return 0 ;
}

