/* @author : mostafa
 * created : 2018-09-13 15:19
 */
#include <iostream>
#include <iomanip>
#include <map>
using namespace std ;
#define fi first 
#define se second


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(4) ;
    int tc ;
    cin >> tc ;
    cin.ignore();cin.ignore();
    map<string,int> mp ;
    int sum = 0 ;
    while( tc-- ){
        mp.clear();
        string line ;
        sum = 0 ;
        while( getline(cin,line) , !line.empty() ){
            mp[line]++ ;
            sum++ ;
        }
        for(auto it : mp){
            cout << it.fi << " " << 100.0 * it.se / sum << '\n' ;
        }
        if( tc ){
            cout << '\n' ;
        }
    }
	return 0 ;
}
