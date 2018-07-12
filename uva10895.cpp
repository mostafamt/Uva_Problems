/* @author : mostafa
 * created : 2018-07-12 02:12
 */
#include <iostream>
#include <cstring>
using namespace std ;
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m ;
    while( cin >> n >> m ){
        int matrix[n][m] ;
        int matrix_transpose[m][n] ;
        memset( matrix , 0 , sizeof matrix );
        memset( matrix_transpose , 0 , sizeof matrix_transpose );
        int num = 0 , x ;
        for(int i = 0 ; i < n ; i++){
            cin >> num ;
            int a[num] ;
            forn(j,num) cin >> a[j] ;
            forn(j,num){
                cin >> x ;
                matrix[i][a[j]-1] = x ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                matrix_transpose[j][i] = matrix[i][j] ;
            }
        }

        /* cout << "*************MATRIX TRANSPOSE******************\n" ; */
        /* for(int i = 0 ; i < m ; i++){ */
        /*     for(int j = 0 ; j < n ; j++){ */
        /*         cout << matrix_transpose[i][j] << " " ; */
        /*     } */
        /*     cout << '\n' ; */
        /* } */
        /* cout << "**************THE END***********************\n" ; */


        cout << m << " " << n << '\n' ;
        for(int i = 0 ; i < m ; i++){
            int a[n] , b[n] , idx = 0 ;
            for(int j = 0 ; j < n ; j++){
                if( matrix_transpose[i][j] != 0 ){
                    a[idx] = j+1 ;
                    b[idx] = matrix_transpose[i][j] ;
                    idx++ ;
                }
            }
            cout << idx ;
            for(int j = 0 ; j < idx ; j++){
                cout << " " << a[j] ;
            }
            cout << '\n' ;
            for(int j = 0 ; j < idx ; j++){
                if( j+1 == idx ){
                    cout << b[j] ;
                } else {
                    cout << b[j] << " " ;
                }
            }
            cout << '\n' ;
        }
        
    }
    return 0 ;
}


