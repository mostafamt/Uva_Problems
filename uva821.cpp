/* @author : mostafa
 * created : 2018-10-25 13:58
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include <set>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MAX 101
#define INF (int)1e9
typedef long long ll ;

int adjMat[MAX][MAX];
set<int> nodes ;

void init()
{
    memset( adjMat , 0 , sizeof adjMat );
    nodes.clear();
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            adjMat[i][j] = INF ;
        }
        adjMat[i][i] = 0 ;
    }
}

void floyed_warshall( int n )
{
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                adjMat[i][j] = min( adjMat[i][j] , adjMat[i][k] + adjMat[k][j] );
            }
        } 
    }
}

int get_sum(int n)
{
    int sum = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if( adjMat[i][j] != INF ){
                sum += adjMat[i][j] ;
            }
        }
    }
    return sum ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    int x , y , c = 1 ;
    while( cin >> x >> y , x || y ){
        int n = 0 ; 
        n = max( n , max( x , y ) );
        init();
        adjMat[x][y] = 1 ;
        nodes.insert(x);  nodes.insert(y);
        while( cin >> x >> y , x || y ){
            n = max( n , max( x , y ) );
            adjMat[x][y] = 1 ;
            nodes.insert(x);  nodes.insert(y);
        }
        n++ ;
        floyed_warshall(n);

        int sum = get_sum(n);
        int cnt = nodes.size();

        cout << "Case "<< c++ <<": average length between pages = ";
        cout << sum / (double)( cnt * (cnt-1) ) ;
        cout << " clicks" << '\n' ;

    }
    return 0 ;
}










