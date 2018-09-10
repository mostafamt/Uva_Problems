/* @author : mostafa
 * created : 2018-09-09 18:57
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std ;

int game[25];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    string line ;
    while( getline(cin,line) , line != "Game Over" ){
        stringstream ss ;
        ss << line ;
        int n = 0 ;
        char c ;
        while( ss >> c ){
            game[n++] = (int)c ;
        }
        int sum = 0 ;
        for(int round = 1 , i = 0 , roll = 0 ; round <= 10 ; i++ ){
            if( game[i] == 'X' ){
                sum += 10 ;
                if( game[i+2] == '/' ){
                    sum += 10 ;
                } else {
                    for(int j = i+1 ; j < i+3 ; j++){
                        if( game[j] == 'X' ){
                            sum += 10 ;
                        } else {
                            sum += game[j] - '0' ;
                        }
                    }
                }
                roll = 2 ;
            } else if( game[i] == '/' ){
                sum += 10 - game[i-1] + '0' ;
                if( game[i+1] == 'X' ){
                    sum += 10 ;
                } else {
                    sum += game[i+1] - '0' ;
                }
                roll++ ;
            } else {
                sum += game[i] - '0' ;
                roll++ ;
            } 
            if( roll == 2 ){
                round++ ;
                roll = 0 ;
            }
        }
        cout << sum << '\n' ;
    }
	return 0 ;
}
