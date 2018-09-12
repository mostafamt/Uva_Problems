/* @author : mostafa
 * created : 2018-09-11 17:39
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n , m ;
    while( cin >> n >> m , n ){
        bool found[n+1] ;
        memset( found , false , sizeof found );
        int balls[m];
        forn(i,m) cin >> balls[i] , found[balls[i]] = true ;
        for(int i = 0 ; i < m ; i++){
            for(int j = i+1 ; j < m ; j++){
                int val = abs( balls[i] - balls[j]  );
                found[val] = true ;
            }
        }
        bool status = true ;
        forn(i,n+1) if( !found[i] ) status = false ;
        status ? cout << "Y\n" : cout << "N\n" ;
    }
	return 0 ;
}
