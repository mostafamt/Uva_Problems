/* @author : mostafa
 * created : 2018-09-14 07:00
 */
#include <iostream>
#include <unordered_set>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n , m , x , ans ;
    unordered_set<int> a ;
    while( cin >> n >> m , n ){
        a.clear();
        ans = 0 ;
        forn(i,n){
            cin >> x ;
            a.insert(x);
        }
        forn(i,m){
            cin >> x ;
            if( a.find(x) != a.end() ){
                ans++ ;
            }
        }
        cout << ans << '\n' ;
    }
	
	return 0 ;
}
