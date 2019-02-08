/* @author : mostafa
 * created : 2019-02-08 11:20
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

const int N = 50 ;
int t , w , n ;
int depth[N] , gold[N] , times[N];
int dp[N][1010];
int Next[N][1010];

int fun(int idx , int tm , int cnt)
{
    if( tm > t ){
        return INT_MIN ;
    }
    if( idx == n ){
        if( tm > t ){
            return INT_MIN ;
        }
        return 0 ;
    }
    if( dp[idx][tm] != -1 ){
        return dp[idx][tm] ;
    }
    int take = gold[idx] + fun( idx + 1 , tm + times[idx] , cnt + 1 );
    int leave = fun( idx + 1 , tm , cnt );
    int max = 0 ;
    if( take >= leave ){
        max = take ;
        Next[idx][tm] = tm + times[idx] ;
    } else {
        max = leave ;
        Next[idx][tm] = tm ;
    }
    return dp[idx][tm] = max ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int q = 0 ;
    while( cin >> t >> w ){
        if( q ){
            cout << '\n' ;
        }
        q++;
        cin >> n ;
        forn(i,n) cin >> depth[i] >> gold[i] , times[i] = 3 * w * depth[i];
        memset( dp , -1 , sizeof dp );
        memset( Next , 0 , sizeof Next );
        int ans = fun(0,0,0);
        cout << ans << '\n' ;
        int tm = 0 ;
        vector<int> v ;
        for(int i = 0 ; i < n ; i++){
            if( Next[i][tm] != tm ){
                v.pb( i );
            }
            tm = Next[i][tm];
        }
        int sz = (int)v.size();
        cout << sz << '\n' ;
        for(int i = 0 ; i < sz ; i++){
            cout << depth[v[i]] << " " << gold[v[i]] << '\n' ;
        }
    }
    
    return 0 ;
}

