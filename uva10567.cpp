/* @author : mostafa
 * created : 2018-09-26 07:06
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()

vector<vector<int> > v (58);

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s ;
    cin >> s ;
    forn(i,(int)s.size()){
        v[s[i]-'A'].pb(i);
    }
    int q ;
    cin >> q ;
    while( q-- ){
        cin >> s ;
        int lower = 0 , first = -1 , end = -1 ;
        bool status = true ;
        forn(i,(int)s.size()){
            int x = s[i] - 'A'  ;
            auto it = lower_bound( all(v[x]) , lower );
            if( it == v[x].end() ){
                status = false ;
                break ;
            } else {
                int idx = it - v[x].begin() ;
                int val = v[x][idx];
                if( val < lower ){
                    status = false ;
                    break ;
                }
                lower = val + 1 ;
                if( first == -1 ){
                    first = end = val ;
                } else {
                    end = val ;
                }
            }
        }
        if( status ){
            cout << "Matched " << first << " " << end << '\n' ; 
        } else {
            cout << "Not matched" << '\n' ;
        }
    }
	
    
    return 0 ;
}




