/* @author : mostafa
 * created : 2018-09-08 22:18
 */
#include <iostream>
using namespace std ;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
    int n ;
    while( cin >> n , n ){
        cout << "Printing order for " << n << " pages:\n" ;
        int sheets = ( n + 3 ) / 4 ;
        int blanks = sheets * 4 - n ;
        int faces = sheets*4 ;
        int pages[sheets*4+1] ;
        for(int i = 1 ; i <= faces ; i++){
            if( faces - i < blanks ){
                pages[i] = -1 ;
            } else {
                pages[i] = i ;
            }
        }
        int front = 1 , back = faces ;
        for(int sheet = 1 ; sheet <= sheets ; sheet++ , front++ , back-- ){
            // front
            if( pages[back] != -1 || pages[front] != -1){
                cout << "Sheet " << sheet << ", front: " ;
                pages[back] == -1 ? cout << "Blank" : cout << back ;
                cout << ", " ;
                pages[front] == -1 ? cout << "Blank" : cout << front ;
                cout << '\n' ;
            }
            front++ ; back-- ;
            // back
            if( pages[front] != -1 || pages[back] != -1 ){
                cout << "Sheet " << sheet << ", back : " ;
                pages[front] == -1 ? cout << "Blank" : cout << front ;
                cout << ", " ;
                pages[back] == -1 ? cout << "Blank" : cout << back ;
                cout << '\n' ;
            }
        }
        
    }
	
	return 0 ;
}
