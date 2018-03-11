#include<bits/stdc++.h>
using namespace std ;
int tc , n , m , x , y ;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//~ freopen("input.txt" , "r" , stdin);
	//~ freopen("output.txt", "w" , stdout);
	cin>>tc ;
	while(tc-->0)
	{
		cin>>n>>m ;
		n-=2 ;m-=2 ;
		x = n/3 ;
		if(n%3!=0) x++ ;
		y = m/3 ;
		if(m%3!=0) y++ ;
		cout<<x*y<<"\n";
	}
	return 0;
}

