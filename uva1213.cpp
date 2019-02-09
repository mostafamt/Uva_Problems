/* @author : mostafa
 * created : 2019-02-09 03:10
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
#define N 1121
typedef long long ll ;

bitset<N> bs ;
vector<int> primes ;
int n , k ;
int memo[187][15][N];

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0 ;
    for(int i = 2 ; i < N ; i++){
        if( bs[i] ){
            primes.pb( i );
            for(int j = i+i ; j < N ; j += i ){
                bs[j] = 0 ;
            }
        }
    }
}

int dp(int idx , int cnt , int sum)
{
    if( cnt == k && sum == n ){
        return 1 ;
    } else if( cnt > k || sum > n ){
        return 0 ;
    }
    if( idx >= 187 || primes[idx] > n ){
        if( cnt == k && sum == n ){
            return 1 ;
        }
        return 0 ;
    }
    if( memo[idx][cnt][sum] != -1 ){
        return memo[idx][cnt][sum];
    }
    int leave = dp( idx + 1 , cnt , sum );
    int take = dp( idx + 1 , cnt + 1 , sum + primes[idx] );
    return memo[idx][cnt][sum] = leave + take ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    sieve();
    while( cin >> n >> k , n ){
        memset( memo , -1 , sizeof memo );
        int ans = dp( 0 , 0 , 0 );
        cout << ans << '\n' ;
    }
    
    return 0 ;
}

