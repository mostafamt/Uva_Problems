#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define MAX (int)(1e4+4)
typedef long long ll ;

ll a[MAX] , x ;

int main()
{
	int i = 0 ;
	while(scanf("%lld",&x) == 1)
	{
		a[i++] = x ;
		sort(a,a+i);
		if(i%2==0)
			printf("%lld\n" , ( a[i/2-1] + a[i/2] ) / 2 );
		else
			printf("%lld\n" , a[i/2] );
	}
	return 0 ;
}
