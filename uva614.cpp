/* @author : mostafa
 * created : 2018-07-30 16:20
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

// believe it or not , i take 2days to accept this problem 
// form first implementation , every thing is correct 
// the bug was i changed sizeof grid and sizeof path with sizeof marked in memset function
// it still give me WA until i found thid bug

int grid[15][15];
bool marked[15][15];
int path[15][15];
int y , x , sx , sy , tx , ty ;
bool reached ;
int num ;


bool check_left(int u ,int v)
{
    if( v == 0 || grid[u][v-1] == 1 || grid[u][v-1] == 3 ){
        return false ;
    }
    return true ;
}

bool check_up(int u , int v)
{
    if( u == 0 || grid[u-1][v] == 2 || grid[u-1][v] == 3 ){
        return false ;
    }
    return true ;
}

bool check_right(int u , int v)
{
    if( v == x-1 || grid[u][v] == 1 || grid[u][v] == 3 ){
        return false ;
    }
    return true ;
}

bool check_down(int u , int v)
{
    if( u == y-1 || grid[u][v] == 2 || grid[u][v] == 3 ){
        return false ;
    }
    return true ;
}


void dfs(int u , int v)
{
    //reached
    if( u == ty && v == tx ){
        path[u][v] = ++num ;
        reached = true ;
        return ;
    }
    marked[u][v] = true ;
    // left
    if( !reached && check_left(u,v) && !marked[u][v-1] ){
        path[u][v] = ++num ;
        dfs(u,v-1);
        if(!reached){
            path[u][v] -= num-- ;
        }
    }
    // up 
    if( !reached && check_up(u,v) && !marked[u-1][v] ){
        path[u][v] = ++num ;
        dfs(u-1,v);
        if(!reached){
            path[u][v] -= num-- ;
        }
    }
    // right 
    if( !reached && check_right(u,v) && !marked[u][v+1] ){
        path[u][v] = ++num ;
        dfs(u,v+1);
        if(!reached){
            path[u][v] -= num-- ;
        }
    }
    // down 
    if( !reached && check_down(u,v) && !marked[u+1][v] ){
        path[u][v] = ++num ;
        dfs(u+1,v);
        if(!reached){
            path[u][v] -= num-- ;
        }
    }
}

int get_size(int n)
{
    int size = 1 ;
    while( n/10 ){
        n /= 10 ;
        size++ ;
    }
    return size ;
}


void format_output()
{
    cout << "+" ;
    for(int i = 0 ; i < x ; i++){
        cout << "---+" ;
    }
    cout << '\n' ;
    for(int i = 0 ; i < y ; i++){
        cout << "|" ;
        for(int j = 0 ; j < x ; j++){
            if( path[i][j] == 0 ){
                if( marked[i][j] ){
                    cout << "???" ;
                } else {
                    cout << "   " ;
                }
            } else {
                int size = 3 - get_size(path[i][j]);
                for(int t = 0 ; t < size ; t++){
                    cout << " " ;
                }
                cout << path[i][j] ;
            }
            if( grid[i][j] == 1 || grid[i][j] == 3 || j == x-1 ){
                cout << "|" ;
            } else {
                cout << " " ;
            }
        }
        cout << "\n+" ;
        for(int j = 0 ; j < x ; j++){
            if( i == y-1 || grid[i][j] == 2 || grid[i][j] == 3 ){
                cout << "---+" ;
            } else {
                cout << "   +";
            }
        }
        cout << '\n' ;
    }
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int maze = 1 ;
    while( cin >> y >> x >> sy >> sx >> ty >> tx , y ){
        sy-- ; sx-- ; ty-- ; tx-- ;
        memset(marked , 0 , sizeof marked);
        memset(grid , 0 , sizeof grid);
        memset(path , 0 , sizeof path);
        num = 0 ;
        reached = false ;
        forn(i,y){
            forn(j,x){
                cin >> grid[i][j] ;
            }
        }
        reached = false ;
        dfs(sy,sx);
        cout << "Maze " << maze++ << '\n' ;
        cout << '\n' ;
        format_output();
        cout << '\n' << '\n' ;
    }
    return 0 ;
}


