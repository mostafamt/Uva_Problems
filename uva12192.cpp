/* @author : mostafa
 * created : 2018-07-01 12:42
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m , q , x , y ;
    while( cin >> n >> m , n ){
        vector< vector<int> > a( n , vector<int>(m) ) ;
        forn(i,n)forn(j,m) cin >> a[i][j] ;
        cin >> q ;
        while( q-- ){
            cin >> x >> y ;
            int max_size = 0 ;
            forn(i,n){
                auto it = lower_bound( a[i].begin() , a[i].end() , x );
                int pos = it - a[i].begin() ;
                int size = 0 ;
                int ii = i ;
                while( ii < n && pos < m && a[ii][pos] >= x && a[ii][pos] <= y ){
                    size++ , ii++ , pos++ ;
                }
                max_size = max(size , max_size);
            }
            cout << max_size << '\n' ; 
        }
        cout << "-\n" ;
    }
    return 0 ;
}


