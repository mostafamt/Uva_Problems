/* @author : mostafa
 * created : 2018-11-08 14:00
 */
#include <iostream>
#include <cstring>
#include <stack>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define V 21
#define MIN_PROFIT 1.01

double adjMat[V][V];
double profit[V][V][V];
int path[V][V][V];
// double profit[layer][from][to]

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n ;
    while( cin >> n ){
        forn(i,n){
            forn(j,n){
                if( i == j ){
                    adjMat[i][j] = 0 ;
                } else {
                    cin >> adjMat[i][j];
                }
            }
        }
        // clear profit
        memset( profit , 0 , sizeof profit );
        // copy adjMat to profit[1][i][j]
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                profit[1][i][j] = adjMat[i][j] ;
                path[1][i][j] = i ;
            }
        }
        for(int layer = 2 ; layer <= n ; layer++){
            for(int k = 0 ; k < n ; k++){
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        double tmp = profit[layer-1][i][k] * adjMat[k][j];
                        if( tmp > profit[layer][i][j] ){
                            profit[layer][i][j] = tmp ;
                            path[layer][i][j] = k ;
                        }
                    }
                }
            }
        }
        // search for the first optimal profit that has minimum transition "layer"
        bool status = false ;
        for(int transition = 2 ; transition <= n ; transition++){
            for(int i = 0 ; i < n ; i++){
                if( profit[transition][i][i] > MIN_PROFIT ){
                    status = true ;
                    stack<int> stk ;
                    stk.push( path[transition][i][i] );
                    for( int t = transition-1 ; t >= 1 ; t-- ){
                        stk.push( path[t][i][stk.top()] );
                    }
                    int common = stk.top() ;
                    while( !stk.empty() ){
                        cout << stk.top() + 1 << " " ;
                        stk.pop() ;
                    }
                    cout << common + 1 << '\n' ;
                    break ;
                }
            }
            if ( status ){
                break ;
            }
        }
        if (!status){
            cout << "no arbitrage sequence exists\n" ;
        }

    }
    
    return 0 ;
}




