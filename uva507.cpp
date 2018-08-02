/* @author : mostafa
 * created : 2018-08-02 23:50
 */
#include <iostream>
using namespace std ;

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int tc ;
    cin >> tc ;
    for(int route = 1 ; route <= tc ; route++){
        int n , x ;
        int sum = 0L , ans = 0L ;
        int from = -1 , to = -1 , tmp_from = -1 , tmp_to = -1 ;
        bool status = true ;
        cin >> n ;
        for(int i = 1 ; i < n ; i++){
            cin >> x ;
            if( sum + x < 0 ){
                sum = 0 ;
                status = true ;
            } else {
                if( status ){
                    tmp_from = i ;
                    status = false ;
                }
                sum += x ;
                tmp_to = i+1 ;
                if( sum > ans ){
                    ans = sum ;
                    from = tmp_from ;
                    to = tmp_to ;
                } else if( sum == ans && (tmp_to-tmp_from) > (to-from) ){
                    from = tmp_from ;
                    to = tmp_to ;
                }
            }
        }
        if( ans > 0 ){
            cout << "The nicest part of route "<< 
                route <<" is between stops "<< from <<" and " << to << '\n' ;  
        } else {
            cout << "Route " << route << " has no nice parts\n";
        }
    }
    return 0 ;
}


