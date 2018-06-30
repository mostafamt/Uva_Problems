/* @author : mostafa
 * created : 2018-06-30 17:30
 */
#include <iostream>
#include <bitset>
#include <string>
using namespace std ;
const int max_height = 20 ;


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , height , num ;
    cin >> tc ;
    while( tc-- ){
        cin >> height >> num ;
        string s = bitset<max_height>(num-1).to_string() ;
        int node = 1 ;
        for(int i = max_height-1 ; i > max_height-1-height+1 ; i--){
            node *= 2 ;
            if ( s[i] == '1' ){
                node++ ;
            }
        }
        cout << node << '\n' ;
    }
    return 0 ;
}


