#include <cstdio>
#include <cmath>
#include <vector>
using namespace std ;
#define pb push_back 
struct Point
{
	int x , y , z ;
	Point(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};
int dist(Point p1 , Point p2)
{
	return (int)sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y))+((p1.z-p2.z)*(p1.z-p2.z)));
}
int main()
{
	int x , y , z , d ,min , ans[10]={0};
	vector<Point> v;
	while(scanf("%d%d%d",&x,&y,&z)&&!(x==0&&y==0&&z==0))
		v.pb(Point(x,y,z));
	for (int i = 0; i < v.size(); ++i)
	{
		min = 10 ;
		for(int k = 0 ; k < v.size() ; k++)
		{
			if(i==k) continue ;
			d = dist(v[i],v[k]);
			if(d<min)  min = d ;
		}
		if(min<=9) ans[min]++ ;
	}
	for(int i = 0 ; i < 10 ; i++)
		printf("%4d",ans[i]);
	printf("\n");
	return 0;
}