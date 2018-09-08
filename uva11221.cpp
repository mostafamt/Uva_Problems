/* @author : mostafa
 * created : 2018-09-08 02:21
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std ;
#define pb push_back


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int tc ;
    cin >> tc ;
    cin.ignore();
    for(int t = 1 ; t <= tc ; t++){
        cout << "Case #" << t << ":" << '\n' ;
        string line ;
        getline(cin,line);
        string extracted ;
        for(int i = 0 ; i < (int)line.size() ; i++){
            if( line[i] >= 'a' &&  line[i] <= 'z' ){
                extracted.pb(line[i]);
            }
        }
        int n = sqrt((int)extracted.size());
        if( n*n != (int)extracted.size() ){
            cout << "No magic :(" << '\n' ;
            continue ;
        } 
        int grid[n][n];
        for(int i = 0 , idx = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++,idx++){
                grid[i][j] = extracted[idx] ; 
            }
        }
        bool status = true ;
        for(int i = 0 ; i < ( n + 1 ) / 2 ; i++){
            for(int j = 0 ; j < ( n + 1 ) / 2 ; j++){
                if( grid[i][j] != grid[n-i-1][n-j-1] ){
                    status = false ;
                    break ;
                }
                if( grid[j][i] != grid[n-j-1][n-i-1] ){
                    status = false ;
                    break ;
                }
            }
        }
        status ? cout << n << '\n' : cout << "No magic :(" << '\n' ;
    }
	
	return 0 ;
}
