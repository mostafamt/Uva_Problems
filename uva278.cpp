/* @author : mostafa
 * created : 2018-12-09 01:24
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc , r , c , ans ;
    char p ;
    cin >> tc ;
    cin.ignore();
    string s ;
    while( tc-- ){
        getline(cin,s);
        stringstream ss ;
        ss << s ;
        ss >> p ;
        ss >> r >> c ;
        switch( p ){
            case 'k' :
                ans = ( ( r * c ) + 1 ) / 2 ;
                break ;
            case 'K' :
                ans = ( (r+1)/2 ) * ( (c+1)/2 ) ;
                break ;
            default :
                ans = min(r,c);
                break ;
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}

