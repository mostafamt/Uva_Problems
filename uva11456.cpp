/* @author : mostafa
 * created : 2019-02-04 03:19
 */
#include <iostream>
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
        int a[n] , inc[n] , dec[n] ;
        forn(i,n) cin >> a[i] ;
        for(int i = n-1 ; i >= 0 ; i--){
            inc[i] = 1 ;
            for(int j = i+1 ; j < n ; j++){
                if( a[i] < a[j] ){
                    inc[i] = max( inc[i] , inc[j] + 1 );
                }
            }
        }
        for(int i = n-1 ; i >= 0 ; i--){
            dec[i] = 1 ;
            for(int j = i+1 ; j < n ; j++){
                if( a[i] > a[j] ){
                    dec[i] = max( dec[i] , dec[j] + 1 );
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans = max( ans , inc[i] + dec[i] - 1 );
        }
        cout << ans << '\n' ;
    }
     
    return 0 ;
}

