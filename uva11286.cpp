/* @author : mostafa
 * created : 2018-09-13 15:40
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std ;
#define all(x) (x).begin(),(x).end()


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    map< vector<int> , int > mp ;
    vector<int> a (5) ;
    int n ;
    while( cin >> n , n ){
        int mx = 0 , ans = 0 ;
        mp.clear();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 5 ; j++){
                cin >> a[j] ;
            }
            sort( all(a) );
            mp[a]++ ;
            if( mp[a] > mx ){
                mx = mp[a] ;
                ans = mp[a] ;
            } else if( mp[a] == mx ){
                ans += mp[a] ;
            }
        }
        cout << ans << '\n' ;
    }
	return 0 ;
}
