#include <iostream>
#include <vector>

using namespace std ;
int dfs(int u);

vector<int> graph ;
vector<bool> visited ;
vector<int> lengths ;

int main()
{
	int TC , N , u , v ;
	cin>>TC ;
	for(int k = 1 ; k <= TC ; k++)
	{
		cin>>N ;
		graph.assign(N,-1);
		visited.assign(N,false);
		lengths.assign(N,-1);
		for(int i = 0 ; i < N ; i++)
		{
			cin>>u>>v ;
			graph[u-1] = v-1 ;
		}
		int maxLength = -1 , vertex = -1 ;
		for(int i = 0 ; i < N ; i++)
		{
			if(lengths[i]==-1) dfs(i);
			if(lengths[i]>maxLength)
			{
				maxLength = lengths[i];
				vertex = i ;
			}
		}
		cout<<"Case "<<k<<": "<<vertex+1<<endl ;
	}
	return 0 ;
}

int dfs(int u)
{
	int sum = 0 ;
	visited[u] = true ;
	if(!visited[graph[u]])
		sum += 1 + dfs(graph[u]);
	visited[u] = false ;
	return lengths[u] = sum ;
}


