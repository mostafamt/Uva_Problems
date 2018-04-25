#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std ;
#define debug(x) cout << "x = " << x << '\n' ;

int h , m ;
char c ;

int main()
{
	while(cin>>h>>c>>m , h||m )
	{
		double hd = (h*60+m) * 360.0/12/60 ;
		double md = m * 360/60 ;
		double d = max(hd-md , md-hd);
		cout<<fixed ;
		cout << setprecision(3) << min(d,360-d) << "\n" ;
	}

	return 0 ;
}
