/* @author : mostafa
 * created : 2018-09-20 23:11
 */
#include <iostream>
#include <cmath>
using namespace std ;

int ring[16], n ;


bool is_prime(int x)
{
    for(int i = 2 ; i <= (int)sqrt(x) ; i++){
        if( x % i == 0 ){
            return false ;
        }
    }
    return true ;
}

bool place(int r , int num)
{
    for(int i = 0 ; i < r ; i++){
        if( ring[i] == num ){
            return false ;
        }
    }
    return is_prime( num + ring[r-1] ) ? true : false ;
}


void backtrack(int r)
{
    if( r == n ){
        if( ! is_prime( ring[r-1] + 1) ){
            return ;
        }
        cout << "1" ;
        for(int i = 1 ; i < n ; i++){
            cout << " " << ring[i] ;
        }
        cout << '\n' ;
        return ;
    }
    for(int i = 2 ; i <= n ; i++){
        if( place(r,i) ){
            ring[r] = i ;
            backtrack(r+1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    ring[0] = 1 ;
    int c = 1 ;
    while( cin >> n ){
        if( c > 1 ){
            cout << '\n' ;
        }
        cout << "Case " << c++ << ":" << '\n' ;
        backtrack(1);
    }
	
    return 0 ;
}

