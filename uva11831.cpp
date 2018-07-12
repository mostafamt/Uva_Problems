/* @author : mostafa
 * created : 2018-07-12 17:54
 */
#include <iostream>
#include <string>
using namespace std ;

char directions[] = {'N','L','S','O'};
int directions_size = 4 ;


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m , s ;
    int stickers = 0 ;
    while( cin >> n >> m >> s , n ){
        stickers = 0 ;
        string grid[n];
        int y = -1 , x = -1 , directions_idx = -1 ;
        bool found = false ;
        for(int i = 0 ; i < n ; i++){
            cin >> grid[i] ;
            for(int j = 0 ; j < m && !found ; j++){
                for(int k = 0 ; k < directions_size && !found ; k++){
                    if( grid[i][j] == directions[k] ){
                        y = i ;
                        x = j ;
                        directions_idx = k ;
                        found = true ;
                    }
                }
            }
        }
        string instructions ;
        cin >> instructions ;
        int size = (int)instructions.size();
        for(int i = 0 ;i < size ; i++){
            if( instructions[i] == 'D' ){
                directions_idx++ ;
                directions_idx %= 4 ;
            } else if( instructions[i] == 'E' ){
                directions_idx-- ;
                if( directions_idx < 0 ){
                    directions_idx = 3 ;
                }
            } else {
                if( directions_idx == 0 && y-1 >= 0 && grid[y-1][x] != '#' ){
                    y-- ;
                } else if( directions_idx == 1 && x+1 < m && grid[y][x+1] != '#'  ){
                    x++ ;
                } else if( directions_idx == 2 && y+1 < n && grid[y+1][x] != '#' ){
                    y++ ;
                } else if( directions_idx == 3 && x-1 >= 0 && grid[y][x-1] != '#' ){
                    x-- ;
                }
                if( grid[y][x] == '*'){
                    stickers++ ;
                    grid[y][x] = '.' ;
                }
            }
        }
        cout << stickers << '\n' ;
    }
    return 0 ;
}


