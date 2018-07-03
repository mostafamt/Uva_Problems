/* @author : mostafa
 * created : 2018-07-03 08:31
 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<'\n'
#define time cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'
#define forn(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll ;

int a[1005] ;
int idx ;
int acc[1005] ;

int how_many(const int max_size)
{
    int num = 0 , sum = 0 , pre = 0 ;
    while( num < idx ){
        int current = pre + max_size ;
        int low = 0 , high = idx ;
        
        while( low <= high ){
            int mid = (low+high) >> 1 ;

            if( acc[mid] <= current && ( mid+1 == idx || acc[mid+1] > current  ) ){
                sum++ ;
                pre = acc[mid] ;
                num = mid+1 ;
                break ;
            } else if( acc[mid] > current ){
                high = mid ;
            } else {
                low = mid ;
            }
        }

    }
    return sum ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m ;
    while( cin >> n >> m ){
        int low = 0 , high = 0 ;
        idx = 0 ; 
        forn(i,n){
            cin >> a[i] ;
            low = max(a[i] ,low);
            high += a[i] ; 
            acc[i] = a[i] ;
            if( i > 0 ){
                acc[i] += acc[i-1] ;
            }
            idx++ ;
        }

        int mid = 0 ;
        while( low <= high ){
            mid = (low+high) >> 1 ;
            int val = how_many(mid);
            
            if( val <=  m && ( mid <= low || how_many(mid-1) > m ) ){
                break ;
            } else if( val > m ){
                low = mid + 1 ;
            } else {
                high = mid - 1 ;
            }
        }
        cout << mid << '\n' ;
    }
    return 0 ;
}


