/* @author : mostafa
 * created : 2018-08-08 20:27
 */
#include <iostream>
#include <stack>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , c = 1 ;
    while( cin >> n , n ){
        cout << "Case " << c++ << ":" << '\n' ;
        int pre , x , from , to ;
        cin >> pre ;
        from = to = pre ;
        for(int i = 1 ; i < n ; i++){
            cin >> x ;
            if( x - pre == 1 ){
                to = x ;
            } else {
                if( to - from == 0 ){
                    cout << "0" << from << '\n' ;
                } else {
                    int u = from , v = to ;
                    stack<int> s ;
                    while( u != v ){
                        u /= 10 ;
                        int rem = v %10 ;
                        s.push(rem);
                        v /= 10 ;
                    }
                    cout << "0" << from << "-" ;
                    while( !s.empty() ){
                        int y = s.top();
                        s.pop();
                        cout << y ;
                    }
                    cout << '\n' ;
                }
                from = to = x ;
            }
            pre = x ;
        }
        if( to - from == 0 ){
            cout << "0" << from << '\n' ;
        } else {
            int u = from , v = to ;
            stack<int> s ;
            while( u != v ){
                u /= 10 ;
                int rem = v %10 ;
                s.push(rem);
                v /= 10 ;
            }
            cout << "0" << from << "-" ;
            while( !s.empty() ){
                int y = s.top();
                s.pop();
                cout << y ;
            }
            cout << '\n' ;
        }
        cout << '\n' ;
    }
    return 0 ;
}


