/* @author : mostafa
 * created : 2018-08-07 00:16
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ; cin >> tc ;
    while( tc-- ){
        int n ; cin >> n ;
        int a[2*n][2*n];
        int dp[n][n] ;
        int c[n][n];
        forn(i,n) forn(j,n) cin >> a[i][j] ;
        forn(i,n) forn(j,n) a[n+i][j] = a[i][n+j] = a[n+i][n+j] = a[i][j] ;
        int ans = a[0][0] ;
        forn(i,n) forn(j,n){
            for(int u = i , q = 0 ; u < i+n && q < n ; u++ , q++){
                for(int v = j , w = 0 ; v < j+n && w < n ; v++ , w++){
                    c[q][w] = a[u][v];
                }
            }
            dp[0][0] = c[0][0];
            for(int u = 1 ; u < n ; u++){
                dp[0][u] = dp[0][u-1] + c[0][u];
                dp[u][0] = dp[u-1][0] + c[u][0];
            }
            for(int u = 1 ; u < n ; u++){
                for(int v = 1 ; v < n ; v++){
                    dp[u][v] = c[u][v] + dp[u-1][v] + dp[u][v-1] - dp[u-1][v-1];
                }
            }

            for(int u = 0 ; u < n ; u++){
                for(int v = 0 ; v < n ; v++){
                    ans = max( ans , dp[u][v] );
                }
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}


