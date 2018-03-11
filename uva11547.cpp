#include <bits/stdc++.h>
using namespace std ;
int tc , n ;
int main()
{
	cin>>tc;
	while(tc--)
	{
		cin>>n ;
		cout<<abs(((((n*567/9)+7492)*235/47)-498)%100/10)<<"\n" ;
	}
	return 0 ;
}

