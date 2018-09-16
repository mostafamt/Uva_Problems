/* @author : mostafa
 * created : 2018-09-15 03:34
 */
#include <iostream>
#include <string>
#include <queue>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    queue< ii > lefts , rights ;
    int tc , n , t , m , var ;
    string dir ;
    cin >> tc ;
    int idx ;
    while (tc--){
        cin >> n >> t >> m ;
        idx = 0 ;
        forn(i,m){
            cin >> var >> dir ;
            dir == "left" ? lefts.push( {var,idx++}  ) : rights.push({var,idx++});
        }
        ii a[n] ;
        int ans[m] , sz , now = 0 , num = 0 ;
        while( num < m ){
            sz = 0 ;
            int u = lefts.front().fi , v = rights.front().fi ;
            if( !lefts.empty() && ( u <= now || rights.empty() || u <= v ) ){
                if( u <= now ){
                    while( !lefts.empty() && lefts.front().fi <= now && sz < n ){
                        a[sz++] = lefts.front();
                        lefts.pop();
                    }
                } else {
                    while( !lefts.empty() && lefts.front().fi == u && sz < n ){
                        a[sz++] = lefts.front();
                        lefts.pop();
                    }
                    now = u ;
                }
            } else {
                now = max( now , v );
            } 

            now += t ;
            num += sz ;

            forn(j,sz){
                ans[ a[j].se ] = now ;
            }

            sz = 0 ;
            u = lefts.front().fi , v = rights.front().fi ;
            if( !rights.empty() && ( v <= now || lefts.empty() || v <= u ) ){                 
                if( v <= now ){
                    while( !rights.empty() && rights.front().fi <= now && sz < n ){
                        a[sz++] = rights.front();
                        rights.pop();
                    }
                } else {
                    while( !rights.empty() && rights.front().fi == v && sz < n ){
                        a[sz++] = rights.front();
                        rights.pop();
                    }
                    now = v ;
                }
            } else {
                now = max( now , u );
            }
            now += t ;
            num += sz ;

            forn(j,sz){
                ans[ a[j].se ] = now ;
            }
        }   
        forn(i,m){
            cout << ans[i] << '\n' ;
        }
        if( tc ){
            cout << '\n' ;
        }
    }
	
	return 0 ;
}
