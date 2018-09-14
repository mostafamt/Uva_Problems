/* @author : mostafa
 * created : 2018-09-14 21:58
 */
#include <iostream>
#include <unordered_map>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int tc , n , x , first , last , ans ;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    unordered_map<int,int> mp ;
    cin >> tc ;
    while( tc-- ){
        mp.clear();
        cin >> n ;
        first = last = 1 ;
        ans = 0 ;
        forn(i,n){
            cin >> x ;
            if( mp[x] && mp[x] >= first ){
                ans = max( ans , last - first );
                first = mp[x] + 1 ;
            }
            mp[x] = last++ ;
        }
        cout << max( ans , last - first ) << '\n' ;
    }
	return 0 ;
}
