#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f 
#define watch(x)  cerr << (#x) << " = " << (x) << "\n" ;
using namespace std ;
typedef long long ll ;
typedef pair<int,int> ii ;
typedef pair<int,ii> iii ;
typedef vector<int> vi ;
typedef vector<ii> vii ;
typedef vector<iii> viii ;
const double pi = 2 * acos(0.0);


int main()
{
	string str = "420" ;
	auto in = istringstream{str} ;
	int x ;
	in >> x ;
	watch(x);

	return 0 ;
}

