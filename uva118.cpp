/* @author : mostafa
 * created : 2018-07-29 17:41
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std ;

string dir = "NESW";
int dx[] = { 0 , 1 , 0  , -1 };
int dy[] = { 1 , 0 , -1 , 0  };
bool scent[52][52];

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int X , Y , x , y , idx = 0 ;
    cin >> X >> Y ;
    char c ;
    string s ;
    while( cin >> x >> y >> c ){
        for(int i = 0 ; i < 4 ; i++){
            if( dir[i] == c ){
                idx = i ;
            }
        }
        cin >> s ;
        int size = (int)s.size();
        bool status = false ;
        for(int i = 0 ; i < size ; i++){
            if(s[i] == 'F'){
                x += dx[idx];
                y += dy[idx];
                if( y > Y || x > X || x < 0 || y < 0 ){
                    x -= dx[idx];
                    y -= dy[idx];
                    if( !scent[x][y] ){
                        scent[x][y] = true ;
                        status = true ;
                        break ;
                    } else {
                        // ignore that .
                        continue ;
                    }
                }
            } else if( s[i] == 'R'){
                idx = (idx+1)%4;
            } else {
                idx == 0 ? idx = 3 : idx-- ;
            }
        }
        cout << x << " " << y << " " << dir[idx] ; 
        status ? cout << " LOST\n" : cout << '\n' ;
    }

    return 0 ;
}


