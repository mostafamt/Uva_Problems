/* @author : mostafa
 * created : 2018-07-04 03:11
 */
#include <iostream>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

bool can(int a[] , int size , int k)
{
    int pre = 0 ;
    forn(i,size){
        int diff = a[i] - pre ;
        if( diff == k ){
            k-- ;
        } else if( k < diff ){
            return false ;
        }
        pre = a[i] ;
    }
    return true ;
}


int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    forn(c,tc){
        int n ;
        cin >> n ;
        int a[n] , low = 0 , pre = 0 , diff ;
        forn(i,n){
            cin >> a[i] ;
            diff = a[i] - pre ;
            low = max(diff,low);
            pre = a[i] ;
        }
        if( can(a,n,low) ){
            cout << "Case " << c+1 << ": " << low << '\n' ;
        } else {
            cout << "Case " << c+1 << ": " << low+1 << '\n' ;
        }
    }
    return 0 ;
}


