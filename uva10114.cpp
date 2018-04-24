#include <iostream>
#include <cstring>
using namespace std ;
#define debug(x)  cout<<"x = " << x << '\n' ;
#define MAX 101

double months[MAX];
int m , q , ind ;
double per_month , ivalue ,dep ;

int main()
{
	while(cin>>m>>per_month>>ivalue>>q , m>0)
	{
		ind = 0 ;
		memset(months , 0 , sizeof(months) );
		while(q-->0)
		{
			cin>>ind>>dep ;
			months[ind] = dep ;
		}
		for(int i = 0 ; i < MAX ; i++)
			if(months[i]==0.0)
				months[i] = months[i-1] ;
		ind = 0 ;
		double car_worth = ivalue ;
		double car_buyer = ivalue+per_month - ((ivalue+per_month)*months[ind]) ;
		double monthly_payment = ivalue / m ;
		while(car_worth > car_buyer)
		{
			car_worth -= monthly_payment ;
			car_buyer -= car_buyer*months[++ind] ;
		}
		cout << ind ;
		if(ind==1)cout<<" month\n";
		else        cout<<" months\n";
	}
}
