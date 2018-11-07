/* @author : mostafa
 * created : 2018-10-25 15:26
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back
#define MAX 26
#define INF (int)1e9

int adjMat1[MAX][MAX];
int adjMat2[MAX][MAX];

void clear()
{
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            adjMat1[i][j] = INF ;
            adjMat2[i][j] = INF ;
        }
        adjMat1[i][i] = 0 ;
        adjMat2[i][i] = 0 ;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n ; 
    while( cin >> n , n ){
        clear();
        char x , y , u , v ;
        int w ;
        int q , r ;

        forn(i,n){
            cin >> x >> y >> u >> v >> w ;
            q = u - 'A' ;
            r = v - 'A' ;
            if( x =='Y' ){
                adjMat1[q][r] = min( adjMat1[q][r] ,w) ;
                if( y == 'B' ){
                    adjMat1[r][q] = min( adjMat1[r][q] ,w) ;
                }
            } else {
                adjMat2[q][r] = min( adjMat2[q][r] ,w) ;
                if( y == 'B' ){
                    adjMat2[r][q] = min( adjMat2[r][q] ,w) ;
                }
            }
        }
        cin >> u >> v ;
        q = u - 'A' ;
        r = v - 'A' ;
        for(int k = 0 ; k < MAX ; k++){
            for(int i = 0 ; i < MAX ; i++){
                for(int j = 0 ; j < MAX ; j++){
                    adjMat1[i][j] = min( adjMat1[i][j] , adjMat1[i][k] + adjMat1[k][j] );
                    adjMat2[i][j] = min( adjMat2[i][j] , adjMat2[i][k] + adjMat2[k][j] );
                }
            }
        }
        vector<int> nodes ;
        int min_energy = INF ;
        for(int i = 0 ; i < MAX ; i++){
            int sum = adjMat1[q][i] + adjMat2[r][i] ;
            if( min_energy != INF && sum == min_energy ){
                nodes.pb(i);
            } else if( min_energy > sum ){
                nodes.clear();
                min_energy = sum ;
                nodes.pb( i );
            }
        }
        if( min_energy == INF ){
            cout << "You will never meet." << '\n' ;
        } else{
            cout << min_energy ;
            for(int i : nodes){
                cout << " " << (char) (i + 'A')  ;
            }
            cout << '\n' ;
        }
    }
    return 0 ;
}

