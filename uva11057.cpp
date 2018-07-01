/* @author : mostafa
 * created : 2018-06-30 20:20
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    while( cin >> n ){
        vector<int> a(n) ;
        forn(i,n){
            cin >> a[i] ;
        }
        sort( a.begin() , a.end() );
        int m ;
        cin >> m ;
        bool twice = m%2==0 ? true : false ;
        if ( twice ){
            int key = m/2 ;
            auto it = lower_bound( a.begin() , a.end() , key );
            int p = it - a.begin() ;
            if ( a[p] == key && a[p+1] == key  ){
                twice = true ;
            } else {
                twice = false ;
            }
        }
        int book1 = 0 , book2 = 0 ;
        int min_diff = INT_MAX ;
        int max_sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            if ( a[i] > m ){
                break ;
            }
            int key = m - a[i] ;
            auto it = lower_bound( a.begin() , a.end() , key );
            int pos = it - a.begin() ;
            while( a[pos] < key ){
                pos-- ;
            }
            if ( pos == i  ){
                pos-- ;
            }
            if ( pos < 0 ){
                continue ;
            }
            int sum = a[i] + a[pos];
            int diff = max(a[i],a[pos]);
            
            if ( sum <= m && sum > max_sum ){
                max_sum = sum ; 
                min_diff = diff ;
                book1 = a[i] ;
                book2 = a[pos] ;
            } else if ( sum <= m && sum == max_sum ){
                if ( diff < min_diff ){
                    min_diff = diff ;
                    book1 = a[i] ;
                    book2 = a[pos] ;
                }
            }
        }
        int mn = min(book1,book2);
        int mx = max(book1,book2);
        cout << "Peter should buy books whose prices are " << mn << " and "<< mx <<".\n\n" ;
        string str ;
        getline( cin , str );
    }
    return 0 ;
}


