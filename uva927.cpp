#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ; 
	cin >> tc ;
	while( tc-- ){
		int n , d , k ;
		cin >> n ;
		int a[n+1] ;
		for(int i = 0 ; i < n+1 ; i++){
			cin >> a[i] ;
		}
		cin >> d >> k ;
		int degree = 0 ;
		while( k > 0 ){
			degree++ ;
			k -= d * degree ;
		}
		long long int ans = 0 ;
		for( int i = 0 ; i < n+1 ; i++){
			ans += a[i] * pow(degree , i ) ;
		}
		cout << ans << "\n" ;
	}

	return 0 ;
}
