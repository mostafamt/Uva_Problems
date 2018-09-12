/* @author : mostafa
 * created : 2018-09-11 17:04
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n ;
    int game = 1 ;
    while( cin >> n , n ){
        cout << "Game " << game++ << ":" << '\n' ;
        int a[n];
        forn(i,n) cin >> a[i] ;
        while( true ){
            int b[n] , strong = 0 , weak = 0 , num[10];
            bool mark[n];
            memset( mark , false , sizeof mark );
            forn(i,n) cin >> b[i] ;
            if( b[0] == 0 ){
                break ;
            }
            memset( num , 0 , sizeof num );
            forn(i,n) a[i] == b[i] ? mark[i] = true , strong++ : num[a[i]]++ ;
            forn(i,n) if( !mark[i] && num[b[i]] ) num[b[i]]-- , weak++ ;
            cout << "    (" << strong << "," << weak << ")" << '\n' ;
        }
    }
	return 0 ;
}
