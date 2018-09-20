/* @author : mostafa
 * created : 2018-09-20 00:34
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
#define pb push_back
const int MAX = 20 ;

bool marked[MAX];
int a[MAX];
int m , n , ans ;
vector<int> com ;

void choose(int idx , int sum , int total)
{
    if( total > m ){
        return ;
    }
    if( total <= m && total > ans ){
        ans = total ;
        com.clear();
        forn(i,n) if(marked[i]) com.pb(a[i]);
    }

    if( idx == n ){
        return ;
    }
    marked[idx] = true ;
    choose( idx+1 , sum + 1 , total + a[idx] );
    marked[idx] = false ;
    choose( idx+1 , sum , total );
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    string line ;
    while( getline(cin,line) ){
        stringstream ss ;
        ss << line ;
        ss >> m >> n ;
        forn(i,n) ss >> a[i] ;
        ans = 0 ;
        choose(0,0,0);
        forn(i,(int)com.size()) cout << com[i] << " " ;
        cout << "sum:" << ans << '\n' ;
    }
	
    return 0 ;
}
