/* @author : mostafa
 * created : 2019-02-06 10:31
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

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ; 
    cin >> tc ;
    while ( tc-- ){
		int n ;
		cin >> n ;
		int W = 0 ;
		int values[n + 1] , weights[n + 1];
		values[0] = weights[0] = 0 ;
		for(int i = 1 ; i < n + 1 ; i++){
			cin >> values[i] >> weights[i] ;
		}
		int m = 0 ;
		cin >> m ;
		int a[m];
		for(int i = 0 ; i < m ; i++){
			cin >> a[i] ;
			W = max( W , a[i] ) ;
		}
		int dp[n + 1][W + 1];
		for(int i = 0 ; i < n + 1 ; i++){
			dp[i][0] = 0 ;
		}
		for(int i = 0 ; i < W + 1 ; i++){
			dp[0][i] = 0 ;
		}
		for(int i = 1 ; i < n + 1 ; i++){
			for(int w = 1 ; w < W + 1 ; w++){
				if( weights[i] > w ) dp[i][w] = dp[i-1][w];
				else dp[i][w] = max( dp[i-1][w] , values[i] + dp[i-1][w-weights[i]] );
			}
		}
		int ans = 0 ;
		for(int i = 0 ; i < m ; i++){
			ans += dp[n][a[i]];
		}
		cout << ans << '\n' ;
	}
    return 0 ;
}

