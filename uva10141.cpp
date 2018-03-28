#include <iostream>
#include <string>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
using namespace std ;
int rs , ps , i , j , cur_req , best_req ;
double cur_price , best_price ;
string str , p_name , ans ;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c = 1 ;
	while(1)
	{
		cin>>rs>>ps ;
		best_req = -1 , best_price = 0 ;
		if(rs==0)
		   	break ;
		cin.ignore();
		rep(i,rs)
			getline(cin,str);
		rep(i,ps)
		{
			getline(cin,p_name);
			cin>>cur_price>>cur_req ;
			cin.ignore();
			rep(j,cur_req)
				getline(cin,str);
			if(cur_req>best_req || (cur_req == best_req && cur_price < best_price ) )
			{
				ans = p_name ;
				best_req = cur_req ;
				best_price = cur_price ;
			}
		}
		if(c!=1)cout<<"\n";
		cout<<"RFP #"<<c++<<"\n"<<ans<<"\n";
	}
	return 0 ;
}






