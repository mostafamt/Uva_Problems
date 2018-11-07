/* @author : mostafa
 * created : 2018-11-07 20:50
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define INF (int)1e9
#define MAX 100

int adjMat[100][100];

void clear()
{
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            adjMat[i][j] = INF ;
        }
        adjMat[i][i] = 0 ;
    }
}

void floyd()
{
    for(int k = 0 ; k < MAX ; k++){
        for(int i = 0 ; i < MAX ; i++){
            for(int j = 0 ; j < MAX ; j++){
                adjMat[i][j] = min( adjMat[i][j] , adjMat[i][k] + adjMat[k][j] );
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ;
    cin >> tc ;
    for(int t = 1 ; t <= tc ; t++){
        clear();
        int N , E ;
        cin >> N >> E ;
        forn(i,E){
            int u , v ;
            cin >> u >> v ;
            adjMat[u][v] = adjMat[v][u] = 1 ;
        }
        int s , d ;
        cin >> s >> d  ;
        floyd();
        int ans = 0 ;
        for(int i = 0 ; i < N ; i++){
            if( adjMat[s][i] + adjMat[i][d] > ans ){
                ans = adjMat[s][i] + adjMat[i][d] ;
            }
        }
        cout << "Case " << t << ": " << ans << '\n' ;
    }
    return 0 ;
}

