/* @author : mostafa
 * created : 2018-09-14 16:13
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std ;
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    priority_queue< iii, vector<iii> , greater<iii> > pq ;
    string reg ;
    int id , p , k ;
    while( cin >> reg , reg != "#" ){
        cin >> id >> p ;
        pq.push({{p,id},p});
    }
    cin >> k ;
    while(k--){
        iii i = pq.top();
        int u = i.fi.fi ;
        int v = i.fi.se ;
        int w = i.se ;
        pq.pop();
        cout << v << '\n' ;
        pq.push( {{u+w ,v},w} );
    }
	
	return 0 ;
}
