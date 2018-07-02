/* @author : mostafa
 * created : 2018-07-02 13:57
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define EPS 0.000000005
#define PI 3.14159265


int p , q , r , s , t , u ;

double F( double x )
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    cout << fixed ;
    cout << setprecision(4) ;
    while( cin >> p >> q >> r >> s >> t >> u ){
        double low = 0.0 , high = 1.0 ;
        double x1 = F(low);
        double x2 = F(high);

        if( x1 * x2 > 0 ){
            cout << "No solution\n" ;
        } else if( abs(x1-0.0) <= EPS ){
            cout << low << '\n' ;
        } else if( abs(x2-0.0) <= EPS ){
            cout << high << '\n' ;
        } else{
            bool state = true ;
            if( x1 > 0 ){
                state = false , low = 1.0 , high = 0.0 ;
            }
            for(int i = 0 ; i < 30 ; i++){
                double mid = ( low + high ) / 2.0 ;
                double val = F(mid);
                    if( val > 0 ){
                        high = mid ;
                    } else {
                        low = mid ;
                    }
            }
            cout << high << '\n' ;
        }
    }
    return 0 ;
}


