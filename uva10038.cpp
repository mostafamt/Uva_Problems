#include <cstdio>
#include <cmath>
#include <array>
using namespace std ;
#define for(i,start,end,move) for(int i = start ; i < end ; i+=move)
int n , pre , x ;
char input ;
bool is_jolly ;
array<bool,3010> diff ;
int main()
{
	while(scanf("%d",&n)==1)
	{
		diff.fill(false);
		is_jolly = true ;
		scanf("%d",&pre);
		for(i,0,n-1,1)
		{
			scanf("%d",&x);
			if(abs(x-pre)<=n-1)
				diff[abs(x-pre)] = true ;
			pre = x ;
		}
		for(i,1,n,1)
			if(!diff[i])
				is_jolly = false ;
		printf( is_jolly ? "Jolly\n" : "Not jolly\n" );
	}
	return 0 ;
}
