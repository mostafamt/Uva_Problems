/* @author : mostafa
 * created : 2018-06-14 02:20
 */
#include <iostream>
#include <vector> 
#include <algorithm>
#include <cstring>
using namespace std ;
#define debug(x) cerr<<#x<<" is "<<x<<"\n"
#define NUM 8
#define pb push_back

int b[] = {0,4,7,5,2,6,1,3};

bool table[8][8] ;

bool check_duplicate(int a[] , int n)
{
	int tmp[8] ;
	for(int i = 0 ; i < n ; i++){ tmp[i] = a[i]; }
	sort( tmp , tmp+n );

	for(int i = 1 ; i < n ; i++){
		if( tmp[i] == tmp[i-1] ){
			return true ;
		}
	}
	return false ;
}


void solve( int a[] , int u , int v , int &nc)
{
	memset( table , 0 , sizeof(table) );
	bool state = true ;
	for(int i = 0 ; i < 8 && state ; i++){
		if( !table[a[i]][i] ){
			// mark column 
			for(int j = 0 ; j < 8 ; j++){
				table[j][i] = true ;
			}
			// mark row 
			for(int j = 0 ; j < 8 ; j++){
				table[a[i]][j] = true ;
			}
			// mark diagonal 
			int y = a[i] , x = i ;
			for( ; x>=0&&y>=0&&x<8&&y<8 ; x+=1 , y+=1 ){
				table[y][x] = true ;
			}
			y = a[i] , x = i ;
			for( ; x>=0&&y>=0&&x<8&&y<8 ; x+=1 , y-=1 ){
				table[y][x] = true ;
			}
			y = a[i] , x = i ;
			for( ; x>=0&&y>=0&&x<8&&y<8 ; x-=1 , y+=1 ){
				table[y][x] = true ;
			}
			y = a[i] , x = i ;
			for( ; x>=0&&y>=0&&x<8&&y<8 ; x-=1 , y-=1 ){
				table[y][x] = true ;
			}
		} else {
			state = false ;
		}
	}
	if( state ){
		if( u-1 == a[v-1] ){
			if( nc > 9 ){
				cout << nc++ ;
			} else {
				cout << " " << nc++ ;
			}
			for(int i = 0 ; i < 5 ; i++){ cout << " "; }
			for(int i = 0 ; i < 8 ; i++){
				cout << " " << a[i]+1 ;
			}
			cout << "\n" ;
		}
	}

}



int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	int tc ; 
	cin >> tc ;
	string s ;
	int arr[8] ;
	int sum = 0 ;
	while( tc-- ){
		getline( cin , s );
		int y , x , nc = 1 ;
		cin >> y >> x ;
		cout << "SOLN" ;
		for(int i = 0 ; i < 7 ; i++){cout<<" ";}
		cout <<  "COLUMN\n";
		cout << " #" ;
		for(int i = 0 ; i < 5 ; i++){ cout << " "; } 
		for(int i = 1 ; i <= 8 ; i++){
			cout << " " <<i ;
		}
		cout << "\n\n" ;
		for(int a = 0 ; a <  NUM ; a++){ arr[0] = a ;
			for(int b = 0 ; b < NUM ; b++){ arr[1]=b ;
				if( !check_duplicate(arr,2) )
				for(int c = 0 ; c < NUM ; c++){ arr[2]=c ;
					if( !check_duplicate(arr,3) )
					for(int d = 0 ; d < NUM ; d++){ arr[3]=d;
						if( !check_duplicate(arr,4) )
						for(int e = 0 ; e < NUM ; e++){arr[4]=e ;
							if( !check_duplicate(arr,5) )
							for(int f = 0 ; f < NUM ; f++){arr[5]=f ;
								if( !check_duplicate(arr,6) )
								for(int g = 0 ; g < NUM ; g++){arr[6]=g ;
									if( !check_duplicate(arr,7) )
									for(int h = 0 ; h < NUM ; h++){arr[7]=h ;
										if( !check_duplicate(arr,8) ){
											sum++ ;
											solve( arr , y , x , nc );
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if( tc > 0 ){
			cout << "\n" ;
		}
	}
    return 0 ;
}


