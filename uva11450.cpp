/* @author : mostafa
 * created : 2018-08-04 16:13
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define M 201
#define C 21
typedef long long ll ;

int memo[C][M] ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc , m , c , k , x ;
    cin >> tc ;
    while( tc-- ){
        memset( memo , 0 , sizeof memo );
        cin >> m >> c ;
        for(int i = 0 ; i < c ; i++){
            cin >> k ;
            for(int j = 0 ; j < k ; j++){
                cin >> x ;
                if( i > 0 ){
                    for(int l = 1 ; l < 201 ; l++){
                        if( memo[i-1][l] > 0 ){
                            int money = l + x ;
                            if( money <= m ){
                                memo[i][money] = 1 ;
                            }
                        }
                    }
                } else {
                    if( x <= m ){
                        memo[i][x] = 1 ;
                    }
                }
            }
        }
        int max = 0 ;
        for(int i = M-1 ; i > 0 ; i--){
            if( memo[c-1][i] > 0 ){
                max = i ;
                break ;
            }
        }
        max == 0 ? cout << "no solution\n" : cout << max << '\n' ;
    }
    return 0 ;
}


