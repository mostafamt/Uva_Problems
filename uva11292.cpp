/* @author : mostafa
 * created : 2018-07-08 15:40
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m ;
    while( cin >> n >> m , n ){
        int dragon[n] , knights[m] ;
        forn(i,n) cin >> dragon[i] ;
        forn(i,m) cin >> knights[i] ;
        sort( dragon , dragon+n );
        sort( knights , knights+m );
        
        int sum = 0 , ans = 0 ;
        for(int i = 0 , j = 0 ; i < n && j < m ; ){
            if( knights[j] >= dragon[i] ){
                sum += knights[j] ;
                ans++ , i++ , j++ ;
            } else {
                j++ ;
            }
            if( j >= m ){
                break ;
            }
        }

        if( ans == n ){
            cout << sum << '\n' ;
        } else {
            cout << "Loowater is doomed!\n" ;
        }
    }
    return 0 ;
}


