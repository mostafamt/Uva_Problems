/* @author : mostafa
 * created : 2018-06-12 02:31
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std ;
#define SIZE 62
#define debug(x) cerr << #x << " is " << x << "\n"

int combination[SIZE][SIZE][SIZE] ;

bool contain( const int space[] , int size , int key )
{
	for(int i = 0 ; i < size ; i++){
		if( space[i] == key ){
			return true ;
		}
	}
	return false ;
}

int main()
{
    cin.sync_with_stdio(false) ;
    cin.tie(0) ;
	set<int> myset ;
	set<int>::iterator it ;
    int space[SIZE] ;
	int idx = 0 ;
		;
	for( int i = 1 ; i <= 3 ; i++){
		for(int j = 1 ; j <= 20 ; j++){
			if( !contain( space , idx , i*j ) ){ 
				space[idx++] = i*j ;
			}
		}
	}
	space[idx++] = 0 ;
	space[idx++] = 50 ;
	int n ;
	while( cin >> n , n > 0 ){
		int num_of_permutation = 0 ;
		int num_of_combination = 0 ;
		memset( combination , 0 , sizeof(combination) ); 
		for(int i = 0 ; i < idx ; i++){
			for(int j = 0 ; j < idx ; j++){
				for(int k = 0 ; k < idx ; k++){
					if( space[i] + space[j] + space[k] == n ){
						num_of_permutation++ ;
						int a [] = { space[i] , space[j] , space[k] };
						sort(a , a+3 );
						if( combination[a[2]][a[1]][a[0]] == 0 ){
							combination[a[2]][a[1]][a[0]]++ ;
							num_of_combination++ ;
						}
					}
				}
			}
		}
		if( num_of_permutation == 0 ){
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
		} else {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << num_of_combination  << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << num_of_permutation  << ".\n";
		}
		for(int i = 0 ; i < 70 ; i++){
			cout << "*" ;
		}
		cout << "\n" ;
	}
	cout << "END OF OUTPUT\n" ;
    return 0 ;
}


