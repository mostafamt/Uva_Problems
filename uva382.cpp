/* @author : mostafa
 * created : 2018-06-21 05:46
 */
#include <cstdio>
#include <cmath>
using namespace std ;

int main()
{
    int n ;
	printf("PERFECTION OUTPUT\n");
	while( scanf("%d",&n) , n ){
		int sum = 0 ;
		for(int i = 1 ; i <= (int)sqrt(n) ; i++){
			if( n % i == 0 ){
				if( i != n ) {
					sum += i ;
				}
				n/i != n && n/i != i ? sum += n/i : sum += 0 ;
			}
		}
		if( n > sum ){
			printf("%5d  DEFICIENT\n", n );
		} else if( n < sum ){
			printf("%5d  ABUNDANT\n" , n );
		} else {
			printf("%5d  PERFECT\n"  , n );
		}
	}
	printf("END OF OUTPUT\n");
    return 0 ;
}


