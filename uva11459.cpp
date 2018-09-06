/* @author : mostafa
 * created : 2018-09-05 22:33
 */
#include <iostream>
#include <cstring>
using namespace std ;

int grid[100];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int tc ;
    int a , b , c , x , y ;
    cin >> tc ;
    while( tc-- ){
        memset( grid , 0 , sizeof grid );
        cin >> a >> b >> c ;
        int player[a] ;
        memset( player , 0 , sizeof player );
        while( b-- ){
            cin >> x >> y ;
            grid[x] = y ;
        }
        int idx = 0 ;
        bool status = false ;
        for(int i = 0 ; i < c ; i++){
            cin >> x ;
            if( status ){
                continue ;
            }
            player[idx] == 0 ? player[idx] += x+1 : player[idx] += x ;
            if( grid[ player[idx] ] ){
                player[idx] = grid[ player[idx] ];
            }
            if( player[idx] >= 100 ){
                status = true ;
            }
            idx++ ;
            if( idx == a ){
                idx = 0 ;
            }
        }
        for(int i = 0 ; i < a ; i++){
            cout << "Position of player " << i+1 << " is " << player[i] << "." << '\n' ;
        }
    }
	return 0;
}
