/* @author : mostafa
 * created : 2018-08-05 15:43
 */
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , x , y ;
    bool is_stk , is_q , is_pq ;
    while( cin >> n ){
        is_stk = is_q = is_pq = true ;
        stack<int> stk ;
        queue<int> q ;
        priority_queue<int> pq ;
        while( n-- ){
            cin >> x >> y ;
            if( x == 1 ){
                if( is_stk ){
                    stk.push(y);
                } 
                if( is_q ){
                    q.push(y);
                }
                if( is_pq ){
                    pq.push(y);
                }
            } else{
                if( is_stk ){
                    if( !stk.empty() && stk.top() == y ){
                        stk.pop();
                    } else {
                        is_stk = false ;
                    }
                }
                if( is_q ){
                    if( !q.empty() && q.front() == y ){
                        q.pop();
                    } else {
                        is_q = false ;
                    }
                }
                if( is_pq ){
                    if( !pq.empty() && pq.top() == y ){
                        pq.pop();
                    } else {
                        is_pq = false ;
                    }
                }
            }
        }
        if( is_stk + is_q + is_pq  >= 2 ){
            cout << "not sure" ;
        } else if( is_stk ){
            cout << "stack" ;
        } else if( is_q ){
            cout << "queue" ;
        } else if( is_pq ){
            cout << "priority queue" ;
        } else {
            cout << "impossible" ; 
        }
        cout << '\n' ;
    }
    return 0 ;
}


