/* @author : mostafa
 * created : 2018-08-08 23:40
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;

// 65 , 97
bool my_fun(char a , char b)
{
    char lowerA = a , lowerB = b ;
    if( lowerA < 97 ){
        lowerA += 32 ;
    }
    if( lowerB < 97 ){
        lowerB += 32 ;
    }
    if( lowerA != lowerB ){
        return lowerA < lowerB ;
    } else {
        return a < b ;
    }
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while( n-- ){
        string s ;
        cin >> s ;
        sort( s.begin() , s.end() , my_fun );
        do{
            cout << s << '\n' ;
        } while( next_permutation(s.begin() , s.end() , my_fun )) ;
    }
    return 0 ;
}


