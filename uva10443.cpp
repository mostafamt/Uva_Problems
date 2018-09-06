/* @author : mostafa
 * created : 2018-09-06 00:32
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int today[100][100];
int tomorrow[100][100];
int r , c ;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int beat[200];

void fill_matches()
{
    beat['P'] = 'S' ;
    beat['R'] = 'P' ;
    beat['S'] = 'R' ;
}

bool valid(int y , int x )
{
    if( y < 0 || x < 0 || y == r || x == c ){
        return false ;
    }
    return true ;
}

bool is_neighbour(int u , int v)
{
    int wanted = beat[ today[u][v] ] ;
    for(int i = 0 ; i < 4 ; i++){
        int y = u + dy[i] ;
        int x = v + dx[i] ;
        if( valid(y,x) && today[y][x] == wanted ){
            return true ;
        }
    }
    return false ;
}


void process_per_day()
{
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if( is_neighbour(i,j) ){
                tomorrow[i][j] = beat[today[i][j]] ;
            } else {
                tomorrow[i][j] = today[i][j] ;
            }
        }
    }
    memcpy( today , tomorrow , sizeof tomorrow );
}

void print_grid()
{
    forn(i,r){
        forn(j,c){
            cout << (char)today[i][j] ;
        }
        cout << '\n' ;
    }
}

int main()
{
    cin.sync_with_stdio(false);
	cin.tie(0);
    fill_matches();
    int tc ,d ;
    string s ;
    cin >> tc ;
    while( tc-- ){
        cin >> r >> c >> d ;
        forn(i,r){
            cin >> s ;
            forn(j,c){
                today[i][j] = s[j] ;
            }
        }
        forn(i,d){
            process_per_day();
        }
        print_grid();
        if( tc ){
            cout << '\n' ;
        }
    }

	return 0;
}
