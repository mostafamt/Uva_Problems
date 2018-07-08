/* @author : mostafa
 * created : 2018-07-08 14:15
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ; 
    int size ;
    string s ;
    cin >> tc ; 
    for(int c = 1 ; c <= tc ; c++){
        cin >> size ;
        cin >> s ;
        int num = 0 , ans = 0 ;
        forn(i,size){
            if(s[i] == '.' && num == 0 ){
                num++ ;
            } else if( num > 0 ){
                num++ ;
            }

            if( num == 3 ){
                ans++ ;
                num = 0 ; 
            }
        }
        if( num > 0 ){
            ans++ ;
        }
        cout << "Case " << c << ": " << ans << '\n' ;
    }
    return 0 ;
}


