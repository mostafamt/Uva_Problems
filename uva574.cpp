/* @author : mostafa
 * created : 2018-09-21 01:57
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back

int a[12];
int freq[12];
int t , n ;
set<vector<int>> st ;
bool found ;

void backtrack(int idx , int sum)
{
    if( sum == t ){
        vector<int> v ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < freq[i] ; j++){
                v.pb(a[i]);
            }
        }
        if( st.find(v) == st.end() ){
            found = true ;
            st.insert(v);
            int sz = (int)v.size();
            for(int i = 0 ; i < sz ; i++){
                if( i == sz -1 ){
                    cout << v[i] << '\n' ;
                } else {
                    cout << v[i] << "+" ;
                }
            }
        }
        return ;
    }

    for(int i = idx ; i < n ; i++){
        if( sum + a[i] <= t ){
            freq[i]++ ;
            backtrack( i+1 , sum + a[i] );
            freq[i]-- ;
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    while ( cin >> t >> n , n ){
        st.clear();
        found = false ;
        cout << "Sums of " << t << ":" << '\n' ;
        forn(i,n) cin >> a[i] ;
        backtrack( 0 , 0 );
        if( !found ){
            cout << "NONE" << '\n' ;
        }
    }
	
    return 0 ;
}
