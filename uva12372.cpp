#include <iostream>
using namespace std ;
int tc , x , y , z ;
int main()
{
	cin>>tc ;
	for(int i = 1 ; i <= tc ; i++)
	{
		cin>>x>>y>>z ;
		if(x<=20&&y<=20&&z<=20)
			cout<<"Case "<<i<<": "<<"good"<<"\n";
		else
			cout<<"Case "<<i<<": "<<"bad"<<"\n";
	}
	return 0 ;
}