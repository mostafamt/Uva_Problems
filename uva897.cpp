/* @author : mostafa
 * created : 2018-08-25 07:12
 */
#include <iostream>
#include <cmath>
using namespace std ;

int a[] = {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
int sz = 22 ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n , n ){
        int ans = 0 ;
        if( n < 991 ){
            int p = log10(n);
            int to = pow(10,p+1);
            for(int i = 0 ; i < sz ; i++){
                if( a[i] > n && a[i] < to ){
                    ans = a[i] ;
                    break ;
                }
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}

