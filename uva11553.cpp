/* @author : mostafa
 * created : 2018-09-19 09:11
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define all(x) (x).begin(),(x).end()


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc , n , ans ;
    cin >> tc ;
    while( tc-- ){
        cin >> n ;
        int a[n][n] ;
        vector<int> p (n) ;
        for(int i = 0 ; i < n ; i++){
            p[i] = i ;
            for(int j = 0 ; j < n ; j++){
                cin >> a[i][j] ;
            }
        }
        ans = INT_MAX ;
        bool marked[n];
        do{
            memset( marked , false , sizeof marked );
            int sum = 0 ;
            for(int i = 0 ; i < n ; i++){
                int mn = INT_MAX , column = -1 ;
                for(int j = 0 ; j < n ; j++){
                    if( !marked[j] && a[p[i]][j] < mn ){
                        mn = a[p[i]][j] ;
                        column = j ;
                    }
                }
                marked[column] = true ;
                sum += mn ;
            }
            ans = min( sum , ans );
        } while( next_permutation( all(p) ) );
        cout << ans << '\n' ;
    }
	
    return 0 ;
}
