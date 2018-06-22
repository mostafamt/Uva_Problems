/* @author : mostafa
 * created : 2018-06-22 09:39
 */
#include <iostream>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

bool binary[100] ;
int idx ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int N ;
    while( cin >> N , N ){
        idx = 0 ;
        int n = N ;
        while( n ){
            binary[idx++] = n % 2 ;
            n /= 2 ;
        }
        int ones = 0 ;
        cout << "The parity of " ;
        for(int i = idx - 1 ; i >= 0 ; i--){
            cout << binary[i] ;
            ones += binary[i] ;
        }
        cout << " is " << ones << " (mod 2).\n" ; 
    }
    
    return 0 ;
}


