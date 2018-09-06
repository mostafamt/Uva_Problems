/* @author : mostafa
 * created : 2018-09-06 14:34
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std ;
#define pb push_back
#define all(x) (x).begin(),(x).end()

int main()
{
    cin.sync_with_stdio(false);
	cin.tie(0);
    int tc ;
    cin >> tc ;
    vector<string> a , b ;
    cin.ignore();
    cin.ignore();
    while( tc-- ){
        string line ;
        a.clear();
        b.clear();
        while( getline(cin,line) && !line.empty() ){
            b.pb(line);
        }
        sort( all(b) );
        int sz = (int)b.size() ;
        for(int i = 0 ; i < sz ; i++){
            string s ;
            for(int j = 0 ; j < (int)b[i].size() ; j++){
                if( b[i][j] != ' ' ){
                    s.pb(b[i][j]);
                }
            }
            sort( all(s) );
            a.pb(s);
        }
        for(int i = 0 ; i < sz ; i++){
            for(int j = i+1 ; j < sz ; j++){
                if( a[i] == a[j] ){
                    cout << b[i] << " = " << b[j] << '\n' ;
                }
            }
        }
        if( tc ){
            cout << '\n' ;
        }
    }
	return 0;
}
