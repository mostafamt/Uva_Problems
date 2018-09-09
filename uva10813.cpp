/* @author : mostafa
 * created : 2018-09-09 15:11
 */
#include <iostream>
#include <cstring>
#include <map>
using namespace std ;
#define ii pair<int,int>
#define fi first 
#define se second

int card[5][5];
int mark[5][5];
int found[76];

bool check()
{
    int sum_horizontal = 0 ;
    int sum_vertical[5];
    memset( sum_vertical , 0 , sizeof sum_vertical );
    int sum_main_diagonal = 0 ;
    int sum_secondary_diagonal = 0 ;
    for(int i = 0 , j = 0 ; i < 5 ; i++){
        sum_horizontal = 0 ;
        for( j = 0 ; j < 5 ; j++){
            sum_horizontal += mark[i][j];
            sum_vertical[i] += mark[j][i];
            if( i == j ){
                sum_main_diagonal += mark[i][j];
            }
            if( i == 5-j-1 ){
                sum_secondary_diagonal += mark[i][j];
            }
        }
        if( sum_horizontal >= 5 || ( sum_horizontal >= 4 && i == 2 ) ){
            return true ;
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        if( sum_vertical[i] >= 5 || ( sum_vertical[i] >= 4 && i == 2 ) ){
            return true ;
        }
    }
    if( sum_main_diagonal >= 4 || sum_secondary_diagonal >= 4 ){
        return true ;
    }
    return false ;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    map<int,ii> mp ;
    int tc ;
    cin >> tc ;
    while( tc-- ){
        mp.clear();
        memset( mark , 0 , sizeof mark );
        memset( found , 0 , sizeof found );
        for(int i = 0 ; i < 5 ; i++){
            for(int j = 0 ; j < 5 ; j++){
                if( i == 2 && j == 2 ){
                    continue ;
                }
                cin >> card[i][j] ;
                found[card[i][j]]++ ;
                mp[card[i][j]] = {i,j};
            }
        }
        int num ;
        int ans = 0 ;
        for(int i = 0 ; i < 75 ; i++){
            cin >> num ;
            if( ans ){
                continue ;
            }
            if( found[num] ){
                int x = mp[num].fi ;
                int y = mp[num].se ;
                if( mark[x][y] ){
                    continue ;
                }
                mark[x][y]++ ;
                if( check() ){
                    ans = i+1 ;
                }
            }
        }
        cout << "BINGO after " << ans << " numbers announced" << '\n' ;
    }
	return 0 ;
}
