/* @author : mostafa
 * created : 2018-09-11 04:45
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int XY[] = {1,2,6,5};
int YZ[] = {1,4,6,3};
int xy[4] ;
int yz[4] ;

void reset()
{
    memcpy( xy , XY , sizeof XY );
    memcpy( yz , YZ , sizeof YZ );
}

void shift_right(int a[] , int n )
{
    int tmp = a[n-1];
    for(int i = n-2 ; i >= 0 ; i--){
        a[i+1] = a[i];
    }
    a[0] = tmp ;
}

void shift_left(int a[] , int n)
{
    int tmp = a[0];
    for(int i = 1 ; i < n ; i++){
        a[i-1] = a[i] ;
    }
    a[n-1] = tmp ;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n ;
    string roll ;
    while( cin >> n , n ){
        reset();
        forn(i,n){
            cin >> roll ;
            if( roll == "north" ){
                shift_right(xy,4);
                yz[0] = xy[0];
                yz[2] = xy[2];
            } else if( roll == "south" ){
                shift_left(xy,4);
                yz[0] = xy[0];
                yz[2] = xy[2];
            } else if( roll == "east" ){
                shift_right(yz,4);
                xy[0] = yz[0];
                xy[2] = yz[2];
            } else {
                shift_left(yz,4);
                xy[0] = yz[0];
                xy[2] = yz[2];
            }
        }
        cout << xy[0] << '\n' ;
    }
	return 0 ;
}
