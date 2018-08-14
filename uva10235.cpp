/* @author : mostafa
 * created : 2018-08-13 20:27
 */
#include <iostream>
#include <sstream>
using namespace std ;
#define pb push_back
#define MAX 1000001

bool a[ MAX+1 ];

int reverse(int n)
{
    stringstream ss ;
    ss << n ;
    string s , rev ;
    ss >> s ;
    int sz = (int)s.size(); 
    for(int i = sz-1 ; i >= 0 ; i--){
        char c = s[i] ;
        rev.pb(c);
    }
    ss.clear();
    int ans ;
    ss << rev ;
    ss >> ans ;
    return ans  ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;

    for(int k = 2 ; k <= MAX / k ; k++){
        if( !a[k] ){
            for(int i = k ; i <= MAX / k ; i++){
                a[ k*i ] = true ;
            }
        }
    }
    int n ;
    while( cin >> n ){
        cout << n << " is " ;
        int r = reverse(n);
        a[n] ? cout << "not prime." : a[r] || n == r ? cout << "prime." : cout << "emirp." ;
        cout << '\n' ;
    }

     
    return 0 ;
}


