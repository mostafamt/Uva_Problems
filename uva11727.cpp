#include <iostream>
#include <algorithm>
using namespace std ;
int tc , arr[3];
int main()
{
	cin>>tc ;
	for(int i = 1 ; i <= tc ; i++)
	{
		for(int k = 0 ; k < 3 ; k++)
			cin>>arr[k];
		sort(arr,arr+3);
		cout<<"Case "<<i<<": "<<arr[1]<<"\n";
	}
	return 0 ;
}
