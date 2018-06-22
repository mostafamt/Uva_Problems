/* @author : mostafa
 * created : 2018-06-22 09:07
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    string s ;
    while( getline( cin , s ) ,  s != "0" ){
        int size = s.size();
        int sum = 0 ;
        for( int i = 0 ; i < size ; i++ ){
            sum += ( s[i] - '0' ) * ( pow(2,size-i) - 1 ) ;
        }
        cout << sum << "\n" ;
        s.clear();
    }
    return 0 ;
}


