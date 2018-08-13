/* @author : mostafa
 * created : 2018-08-12 15:07
 */
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define MAX 51

// I have spent all the day in struggling with wrong answer for this problem .
// logic errors and subtle tricks are so hard to identify 
// good luck , i was here :) smile

int tmp[MAX][MAX];
int grid[MAX][MAX];
int dist[MAX][MAX][4];
int r , c ; 
int R , C ;
map<string,int> mp ;
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};
int d[] = {-1,1};

bool valid(int y , int x , int dir)
{
    if( y < 0 || x < 0 || y >= R || x >= C || grid[y][x] ){
        return false ;
    }
    return true ;
}

int bfs(int y , int x , int Y , int X , int dir)
{
    memset( dist , -1 , sizeof dist );
    queue<pair<ii,int> > q ;
    q.push( { {y,x},dir } );
    dist[y][x][dir] = 0 ;
    while( !q.empty() ){
        pair<ii,int> p = q.front() ; q.pop();
        int u = p.fi.fi , v = p.fi.se , w = p.se ;

        if( u == Y && v == X ){
            return dist[u][v][w] ;
        }
        // you can change your direction right or left
        for(int i = 0 ; i < 2 ; i++){
            int angle = w+d[i] ;
            if( angle < 0 ){
                angle = 3 ;
            } else if( angle > 3 ){
                angle = 0 ;
            }
            
            if( dist[u][v][angle] == -1 ){
                q.push( { {u,v} , angle } );
                dist[u][v][angle] = 1 + dist[u][v][w] ;
            }
            
        }
        // go 1 , 2 or 3 steps in one command
        for(int i = 1 ; i < 4 ; i++){
            int yy = u + i * dy[w] , xx = v + i * dx[w] ;
            if( valid( yy , xx , w ) ){
                if( dist[yy][xx][w] == -1 ){
                    q.push( { {yy,xx} , w }  );
                    dist[yy][xx][w] = 1 + dist[u][v][w] ;
                    if( yy == Y && xx == X ){
                        return dist[yy][xx][w] ;
                    }
                }
            } else {
                break ;
            }
        }
    }
    return -1 ;
}


void transform_input()
{
    R = r-1 ; 
    C = c-1 ;
    memset( grid , 0 , sizeof grid );

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            grid[i][j] = tmp[i][j] + tmp[i+1][j] + tmp[i][j+1] + tmp[i+1][j+1] ;
        }
    }
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    mp["west"] = 0 ; mp["north"] = 1 ;
    mp["east"] = 2 ; mp["south"] = 3 ;
    while( cin >> r >> c , r ){
        forn(i,r) forn(j,c) cin >> tmp[i][j] ;
        transform_input();

        int x , y , X , Y ;
        string dir ;
        cin >> y >> x >> Y >> X ;
        y-- ; x-- ; Y-- ; X--; 
        cin >> dir ;
        int ans = bfs( y , x , Y , X , mp[dir] );
        cout << ans <<'\n' ;
    }


    return 0 ;
}


