/* @author : mostafa
 * created : 2018-09-15 20:49
 */
#include <iostream>
#include <string>
#include <queue>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    queue<int> lefts , rights ;
    int tc , l , m ;
    cin >> tc ;
    while( tc-- ){
        cin >> l >> m ;
        l *= 100 ;
        int len ;
        string dir ;
        forn(i,m){
            cin >> len >> dir ;
            dir == "left" ? lefts.push( {len} ) : rights.push( {len} ) ;
        }
        int num = 0 , sum = 0 , ans = 0 ;
        while( num < m ){
            sum = 0 ;
            int u = lefts.front();
            while( !lefts.empty() && sum + u <= l ){
                sum += u ;
                lefts.pop();
                u = lefts.front();
                num++ ;
            }
            ans++ ;
            sum = 0 ;

            int v = rights.front();
            while( !rights.empty() && sum + v <= l ){
                sum += v ;
                rights.pop();
                v = rights.front();
                num++ ;
            }
            if( sum > 0 || num < m ){
                ans++ ;
            }
        }
        cout << ans << '\n' ;
    }
	
	return 0 ;
}
