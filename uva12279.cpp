#include <iostream>
using namespace std ;
int n , x , ans , i = 1 ;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true)
	{
		ans = 0 ;
		cin>>n ;
		if(n==0) break ;
		while(n--)
		{
			cin>>x ; 
			x > 0 ? ans++ : ans-- ;
		}
		cout<<"Case "<<i++<<": "<<ans<<"\n";
	}
	return 0;
}