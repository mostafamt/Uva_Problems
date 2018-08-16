/* @author : mostafa
 * created : 2018-08-15 17:14
 */
#include <iostream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define fi first 
#define se second
#define MAX 110600

ii a[MAX] ;
int x , y , idx ;

void update_coordinates()
{
    a[idx++] = {x,y};
}

void down()
{
    y++ ;
    update_coordinates();
}

void down_left()
{
    x--;
    y++;
    update_coordinates();
}

void up_left()
{
    x-- ;
    update_coordinates();
}

void up()
{
    y-- ;
    update_coordinates();
}

void up_right()
{
    x++ ;
    y-- ;
    update_coordinates();
}

void down_right()
{
    x++ ;
    update_coordinates();
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    idx = 1 ; 
    x = 0 ; 
    y = 0 ;
    a[idx++] = {x,y};
    int step = 0 ;
    while( step++ < 185 ){
        forn(i,step)   down();
        forn(i,step-1) down_left();
        forn(i,step)   up_left();
        forn(i,step)   up();
        forn(i,step)   up_right();
        forn(i,step)   down_right();
    }
    int n ;
    while( cin >> n ){
        cout << a[n].fi << " " << a[n].se << '\n' ;
    }
    return 0 ;
}


