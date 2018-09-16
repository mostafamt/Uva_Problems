/* @author : mostafa
 * created : 2018-09-16 03:47
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int k ;
    vector<ii> v ;
    while( cin >> k ){
        v.clear();
        for(int i = k+1 ; i <= 2*k ; i++){
            // 1/k+1
            // get the complement
            int g = __gcd( i - k , i * k );
            if( g == ( i - k ) ){
                v.pb( {i*k/g,i} );
            }

        }
        int sz = (int)v.size();
        cout << sz << '\n' ;
        forn(i,sz){
            cout << "1/" << k << " = " << 1 << "/" << v[i].fi << " + " ;
            cout << "1/" << v[i].se << '\n' ;
        }
    }
	return 0 ;
}
