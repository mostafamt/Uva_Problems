/* @author : mostafa
 * created : 2018-08-23 07:56
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;
#define dd pair<double,double>
#define fi first 
#define se second
#define PI acos(-1)
typedef long long ll ;



dd get_coordinates(ll cell)
{
    int level = sqrt(cell);
    double height = cos(PI/6); // cos(30)
    double y = height * level ;
    int remain = cell - level * level + 1 ;
    double from_base = height / 3.0 ;  // triangle median divide 1 : 2 from base
    double from_head = height / 3.0 * 2.0 ;
    remain % 2 == 1 ? y += from_head : y += from_base ;
    double x = ( level + 1 ) * -0.5 + remain * 0.5 ;
    return make_pair(x,y) ;
}

double get_dis(dd p1 , dd p2)
{
    double y = p1.fi - p2.fi ;
    double x = p1.se - p2.se ;
    return hypot(y,x);
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    cout << fixed ;
    cout << setprecision(3);
    ll cell1 , cell2 ;
    while( cin >> cell1 >> cell2 ){
        dd p1 = get_coordinates(cell1);
        dd p2 = get_coordinates(cell2);
        double dis = get_dis(p1,p2);
        cout << dis << '\n' ;
    }
    return 0 ;
}


