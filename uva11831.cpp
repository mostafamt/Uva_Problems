/* @author : mostafa
 * created : 2019-02-01 03:58
 */
#include <iostream>
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
#define MX 110
typedef long long ll ;

char map[MX][MX];
int N , M , S ;
int ans ;
int dirY[] = { -1 , 0 , 1 , 0 };
int dirX[] = { 0 , 1 , 0 , -1 };

bool check(int y , int x )
{
    if( y == N || x == M || y == -1 || x == -1 || map[y][x] == '#' ){
        return false ;
    }
    if( map[y][x] == '*' ){
        ans++ ;
        map[y][x] = '.' ;
    }
    return true ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while( cin >> N >> M >> S , N ){
        int y = 0 , x = 0 ;
        int dir = 0 ;
        ans = 0 ;
        forn(i,N) forn(j,M){
            cin >> map[i][j] ;
            if( map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'L' || map[i][j] == 'O' ){
                y = i , x = j ;
                if( map[i][j] == 'N' ) dir = 0 ;
                else if ( map[i][j] == 'L' ) dir = 1 ;
                else if ( map[i][j] == 'S' ) dir = 2 ;
                else dir = 3 ;
                map[i][j] = '.' ;
            }
        }
        string s ;
        cin >> s ;
        forn(i,S){
            if ( s[i] == 'F' ){
                int tmpY = y , tmpX = x ;
                y += dirY[dir];
                x += dirX[dir];
                if( !check(y,x) ){
                    y = tmpY , x = tmpX ;
                }
            } else if ( s[i] == 'D' ){
                dir++ ;
                if ( dir == 4 ) dir = 0 ;
            } else {
                dir-- ;
                if( dir == -1 ) dir = 3 ;
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}

