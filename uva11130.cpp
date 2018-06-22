/* @author : mostafa
 * created : 2018-06-22 22:08
 */
#include <iostream>
#include <cmath>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
const double PI = 3.141592654 ;

int a , b , v , A , s ; 
int get_horizontal_touches(){
    int distance = v * s * sin(A*PI/180) / 2.0 ;
    int num = 0 ;
    if( distance >= b/2.0 ){
        distance -= b/2.0 ;
        num++ ;
        num += distance / b ;
    }
    return num ; 
}

int get_vertical_touches(){
    int distance = v * s * cos(A*PI/180) / 2.0 ;
    int num = 0 ;
    if( distance >= a / 2.0 ){
        distance -= a / 2.0 ;
        num++ ;
        num += distance / a ;
    }
    return num ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    while( cin >> a >> b >> v >> A >> s , a ){
        cout << get_vertical_touches() << " " << get_horizontal_touches() << "\n" ;
    }
    
    return 0 ;
}


