/* @author : mostafa
 * created : 2018-09-14 12:59
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int tc , x , m , n , sg , sb ;
    cin >> tc ;
    priority_queue<int> greens ;
    priority_queue<int> blues ;
    while( tc-- ){
        cin >> n >> sg >> sb ;
        while(sg--){
            cin >> x ;
            greens.push(x);
        }
        while(sb--){
            cin >> x ;
            blues.push(x);
        }
        int res_green[n];
        int res_blue[n];
        while( !( greens.empty() || blues.empty() ) ){
            m = 0 ;
            for(int i = 0 ; i < n ; i++){
                int u = greens.top();
                int v = blues.top();
                if( u >= v ){
                    res_green[i] = u - v ;
                    res_blue[i] = 0 ;
                } else {
                    res_blue[i] = v - u ;
                    res_green[i] = 0 ;
                }
                m++ ;
                
                greens.pop();
                blues.pop();
                if( greens.empty() || blues.empty() ){
                    break ;
                }
            }
            forn(i,m){
                if( res_green[i] ){
                    greens.push( res_green[i] );
                }
                if( res_blue[i] ){
                    blues.push( res_blue[i] );
                }
            }
        }
        if( greens.empty() && blues.empty() ){
            cout << "green and blue died\n" ;
        } else if( blues.empty() ){
            cout << "green wins\n" ;
            while( !greens.empty() ){
                cout << greens.top() << '\n' ;
                greens.pop();
            } 
        } else {
            cout << "blue wins\n" ;
            while( !blues.empty() ){
                cout << blues.top() << '\n' ;
                blues.pop();
            } 
        }
        if( tc ){
            cout << '\n' ;
        }
    }
	
	return 0 ;
}
