/* @author : mostafa
 * created : 2018-09-08 14:15
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;

const int max_time = 5*60*60 ;
int lights[110] ;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int idx = 0 ;
    while( cin >> lights[idx] , lights[idx] ){
        int mn = 102 ;
        mn = min( mn , lights[idx] );
        idx++ ;
        while( cin >> lights[idx] , lights[idx] ){
            mn = min( mn , lights[idx] );
            idx++ ;
        }
        int ans = 0 ;
        for(int n = 2 ; n * mn <= max_time ; n += 2 ){
            for(int i = n*mn ; i < n*mn + mn - 5 && i <= max_time ; i++){
                for(int j = 0 ; j < idx ; j++){
                    int d = i / lights[j] ;
                    if( d & 1 || i >= d*lights[j] + lights[j] - 5 ){
                        ans = -1 ;
                        break ;
                    }
                    ans = i ;
                }
                if( ans != -1 ){
                    break ;
                }
            }
            if( ans != -1 ){
                break ;
            }
        }
        if( ans != -1 ){
            // there is an intersection
            int u = ans ;
            int hour = u / 60 / 60 ;
            u -= hour * 60 * 60 ;
            if( hour / 10 ){
                cout << hour ;
            } else {
                cout << "0" << hour ;
            }
            cout << ":" ;
            int minutes = u / 60 ;
            u -= minutes * 60 ;
            if( minutes / 10 ){
                cout << minutes ;
            } else {
                cout << "0" << minutes ;
            }
            cout << ":" ;
            int seconds = u ;
            if( seconds / 10 ){
                cout << seconds ;
            } else {
                cout << "0" << seconds ;
            }
            cout << '\n' ;
        } else {
            cout << "Signals fail to synchronise in 5 hours\n" ;
        }
           

        idx = 0 ; 
        
    }
	
	return 0 ;
}



