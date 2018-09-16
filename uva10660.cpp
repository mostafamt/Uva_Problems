/* @author : mostafa
 * created : 2018-09-16 06:10
 */
#include <iostream>
#include <cstring>
#include <climits>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int grid[5][5];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int tc ;
    cin >> tc ;
    while( tc-- ){
        memset( grid , 0 , sizeof grid );
        int n ;
        int r , c , val ;
        cin >> n ; 
        forn(i,n){
            cin >> r >> c >> val ;
            grid[r][c] = val ;
        }
        int ans = INT_MAX ;
        int arr[5]; 
        for(int i = 0 ; i < 21 ; i++){
            for(int j = i+1 ; j < 22 ; j++){
                for(int k = j+1 ; k < 23 ; k++){
                    for(int l = k+1 ; l < 24 ; l++){
                        for(int m = l+1 ; m < 25 ; m++){
                            int selected[5] = {i,j,k,l,m};

                            int sum = 0 ;
                            for(int o = 0 ; o < 5 ; o++){
                                for(int p = 0 ; p < 5 ; p++){
                                    // iterate through all city areas
                                    int mn = 10 ;
                                    if ( grid[o][p] ){
                                        // get the minimum distance to this area
                                        for(int q = 0 ; q < 5 ; q++){
                                            int w = selected[q];
                                            int u = w / 5 ;
                                            int v = w - 5 * u ;
                                            int dist = abs( u - o ) + abs( v - p );
                                            mn = min( mn , dist );
                                        }
                                        sum += mn * grid[o][p];
                                    }
                                }
                            }
                            if( sum < ans ){
                                ans = sum ;
                                memcpy( arr , selected , sizeof arr );
                            }
                        }
                    }
                }
            }
        }
        forn(i,5){
            if( i == 4 ){
                cout << arr[i] << '\n' ;
            } else {
                cout << arr[i] << " " ;
            }
        }
    }
	
	return 0 ;
}
