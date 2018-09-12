/* @author : mostafa
 * created : 2018-09-11 15:35
 */
#include <iostream>
using namespace std ;
#define ii pair<int,int>
#define fi first 
#define se second

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n ;
    string line ;
    bool status = true ;
    ii ans = {1,10};
    while( cin >> n , n ){
        cin.ignore();
        getline(cin,line);

        if( line == "too high"){
            if( status ){
                ans.se = min( ans.se , n-1 );
            }
            if( status && ans.fi > ans.se ){
                status = false ;
            }
        } else if( line == "too low" ){
            if( status ){
                ans.fi = max( ans.fi , n+1 );
            }
            if( status && ans.fi > ans.se ){
                status = false ;
            }
        } else {
            if( n < ans.fi || n > ans.se ){
                status = false ;
            }
            if( status ){
                cout << "Stan may be honest\n" ;
            }else {
                cout << "Stan is dishonest\n" ;
            }
            // reset
            ans = {1,10};
            status = true ;
        }
    }
	
	return 0 ;
}
