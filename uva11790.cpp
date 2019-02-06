/* @author : mostafa
 * created : 2019-02-06 08:00
 */
#include <bits/stdc++.h>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll ;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tc ;
    cin >> tc ;
    for(int t = 1 ; t <= tc ; t++){
		int n ;
		cin >> n ;
		int heights[n] , weights[n] ;
		forn(i,n) cin >> heights[i] ;
		forn(i,n) cin >> weights[i] ;
		int dp_i[n] , dp_d[n];
		int max_increasing = 0 , max_decreasing = 0 ;
		for(int i = 0 ; i < n ; i++){
			int temp = dp_i[i] = dp_d[i] = weights[i] ;
			for(int j = 0 ; j < i ; j++){
				if( heights[i] > heights[j] ){
					dp_i[i] = max( dp_i[i] , dp_i[j] + temp );
				}
				if( heights[i] < heights[j] ){
					dp_d[i] = max( dp_d[i] , dp_d[j] + temp );
				}
			}
			max_increasing = max( max_increasing , dp_i[i] );
			max_decreasing = max( max_decreasing , dp_d[i] );
		}
		cout << "Case " << t << ". " ;
		if( max_increasing >= max_decreasing ){
			cout << "Increasing (" << max_increasing << "). ";
			cout << "Decreasing (" << max_decreasing << ")." ;
		} else {
			cout << "Decreasing (" << max_decreasing << "). " ;
			cout << "Increasing (" << max_increasing << ").";
		}
		cout << '\n' ;
		
	}
    
    return 0 ;
}

