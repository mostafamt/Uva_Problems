/* @author : mostafa
 * created : 2019-02-07 10:44
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

const int W = 10010 ;
const int N = 101 ;
int dp[N][W];
int weights[N] , values[N];
int m , n ;

int fun(int idx , int w)
{
    if( w > m && m <= 1800 ){
        return -1000 ;
    }
    if( w > m + 200 ){
        return -1000 ;
    }
    if( idx == n ){
        if( w > m && w <= 2000 ){
            return -10000 ;
        }
        return 0 ;
    }
    if( dp[idx][w] != -1 ){
        return dp[idx][w] ;
    }
    int take = fun(idx+1 , weights[idx]+w);
    int leave = fun( idx+1 , w );
    return dp[idx][w] = max( values[idx] + take , leave );
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while( cin >> m >> n ){
        memset( dp , -1 , sizeof dp );
        forn(i,n) cin >> weights[i] >> values[i] ;
        int ans = fun(0,0);
        cout << ans << '\n' ;
    }
    return 0 ;
}

