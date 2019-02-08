/* @author : mostafa
 * created : 2019-02-08 09:10
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

const int N = 100 ;
const int M = 550 * 100 ;
int dp[N][M];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc ;
    while( tc-- ){
        int n ;
        cin >> n ;
        int a[n];
        forn(i,n) cin >> a[i];
        memset( dp , 0 , sizeof dp );
        dp[0][a[0]] = 1 ;
        int ans = a[0] ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < 500 * n ; j++){
                if( dp[i-1][j] ){
                    int sum = j + a[i] ;
                    int diff = abs( j - a[i] );
                    dp[i][sum] = dp[i][diff] = 1 ;
                    if( i == n-1 ){
                        ans = min( ans , min( diff , sum) );
                    }
                }
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}

