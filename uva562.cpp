/* @author : mostafa
 * created : 2019-02-08 10:30
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

int n ;
int coins[100];
int dp[110][100*550];

int fun(int idx, int tot)
{
    if( idx == n ){
        return tot ;
    }
    if( dp[idx][tot] != -1 ){
        return dp[idx][tot];
    }
    int sum = fun( idx + 1 , tot + coins[idx] );
    int diff = fun( idx + 1 , abs( tot - coins[idx] ));
    return dp[idx][tot] = min( sum , diff );
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ;
    cin >> tc ;
    while( tc-- ){
        cin >> n ;
        forn(i,n) cin >> coins[i];
        memset( dp , -1 , sizeof dp );
        int ans = fun(0,0);
        cout << ans << '\n' ;
    }
    return 0 ;
}

