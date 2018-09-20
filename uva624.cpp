/* @author : mostafa
 * created : 2018-09-19 23:52
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int m , n , sum , ans ;
    string line ;
    while( getline(cin,line) ){
        stringstream ss ;
        ss << line ;
        ss >> m >> n ;
        int a[n] ;
        forn(i,n) ss >> a[i] ;

        ans = 0 ;
        vector<int> v , com ;
        for(int i = 0 ; i < ( 1 << n ) ; i++){
            sum = 0 ;
            v.clear();
            for(int j = 0 ; j < n ; j++){
                if( i & ( 1 << j ) ){
                    sum += a[j] ;
                    v.pb( a[j] );
                }
            }
            if( sum <= m && sum > ans ){
                ans = sum ; 
                com = v ;
            }
        }
        forn(i,(int)com.size()) cout << com[i] << " " ;
        cout << "sum:" << ans << '\n' ;
       
    }
	
    return 0 ;
}
