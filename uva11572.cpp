/* @author : mostafa
 * created : 2018-09-14 14:27
 */
#include <iostream>
#include <algorithm>
#include <set>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int tc , n , x , ans , sum ;
    set<int> a ;
    cin >> tc ;
    while( tc-- ){
        ans = sum = 0 ;
        int idx = 0 ;
        cin >> n ;
        int arr[n];
        forn(i,n){
            cin >> x ;
            arr[i] = x ;
            if( a.find(x) == a.end() ){
                a.insert(x);
                sum++ ;
            } else {
                while( arr[idx] != x ){
                    a.erase(arr[idx++]);
                    sum-- ;
                }
                idx++ ;
            }
            ans = max( ans , sum );
        }
        a.clear();
        cout << ans << '\n' ;
    }
	return 0 ;
}
