#include<bits/stdc++.h>

using namespace std;

typedef pair < int, int > pi;
vector < list < pi > > graph;
map < pi, int > edge;
vector < bool > visited;
int V, E;

int dfs(int source)
{
	stack < int > s;
	list < pi > :: iterator it;
	int ans = 0;

	visited[source] = true;
	s.push(source);

	while(!s.empty())
	{
		int u = s.top();
		s.pop();

		for( it = graph[u].begin(); it != graph[u].end(); it++)
		{
			ans += it->second;
			
			if(visited[it->first] == true )
				continue;
			else
			{
				visited[it->first] = true;
				s.push(it->first);
			}
		}
	}

	return ans;

}


int main ()
{
	int N, s;
	
	cin >> N;

	for( int j = 0; j < N; ++j)
	{
		cin >> s >> V >> E;

		graph.resize(V);
		visited.resize(V, false);
		
		for(int i = 0; i < E; ++i)
		{
			int from, to;
			cin >> from >> to;

			if(edge[make_pair(from,to)] == 1)
				continue;
			else
			{
				graph[from].push_back(make_pair(to, 1));
				graph[to].push_back(make_pair(from, 1));
				edge[make_pair(from,to)] = 1;
				edge[make_pair(to,from)] = 1;
			}
		}
		
		cout << dfs(s) << endl;
		
		graph.clear();
		visited.clear();
		edge.clear();	
	}
}
