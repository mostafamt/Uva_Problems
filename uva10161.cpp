/* @author : mostafa
 * created : 2018-06-26 10:08
 */
#include <iostream>
#include <cmath>
using namespace std ;

void print( int x , int y )
{
    cout << x << " " << y << '\n' ;
}


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n , n ){
        int level = sqrt(n);
        int remainder = n - level*level ;
        if( level % 2 ==  0 ){
            int x = level ,  y = 1 ;
            if( remainder <= 0 ){
                print(x,y) ;
                continue ;
            }
            x++ ; remainder -= 1 ;
            if( remainder <= 0 ){
                print(x,y);
                continue ;
            }
            y += level ; remainder -= level ;
            if( remainder <= 0 ){
                remainder += level ;
                y -= level ;
                print(x,y+remainder) ;
                continue ;
            }
            x -= level ; remainder -= level ;
            if( remainder <= 0 ){
                remainder += level ;
                x += level ;
                print(x-remainder,y);
                continue ;
            }
        } else {
            int x = 1 , y = level ;
            if( remainder <= 0 ){
                print(x,y) ;
                continue ;
            } 
            y++ ; remainder -= 1 ;
            if( remainder <= 0 ){
                print(x,y);
                continue ;
            }
            x += level ; remainder -= level ;
            if( remainder <= 0 ){
                remainder += level ;
                x -= level ;
                print(x+remainder,y);
                continue ;
            }
            y -= level ; remainder -= level ;
            if( remainder <= 0 ){
                remainder += level ;
                y += level ;
                print(x,y);
                continue ;
            }
        }
    }
    
    return 0 ;
}


