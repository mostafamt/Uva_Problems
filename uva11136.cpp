/* @author : mostafa
 * created : 2018-09-14 05:27
 */
#include <iostream>
#include <set>
using namespace std ;
#define fi first 
typedef long long ll ;


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int n , k , x ;
    ll ans ;
    multiset<int> a ;
    while( cin >> n , n ){
        a.clear();
        ans = 0L ;
        for(int i = 0 ; i < n ; i++){
            cin >> k ;
            while(k--){
                cin >> x ;
                a.insert(x);
            }
            auto it_mn = a.begin() ;
            auto it_mx = --a.end() ;
            ans += *it_mx - *it_mn ;
            a.erase(it_mn);
            a.erase(it_mx);
        }
        cout << ans << '\n' ;
    }
	return 0 ;
}
