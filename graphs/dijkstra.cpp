#include<bits/stdc++.h>

using namespace std;

int V, E;
const int inf = 0x3f3f3f3f;
typedef pair < int, int > pi;
vector < list < pi > > graph;
vector < int > dist;
vector < bool > visited;

void dijkstra (int source)
{
	priority_queue< pi > pq;
	pq.push( make_pair ( 0, source) );
	dist[source] = 0;

	list< pi > :: iterator it;

	while(!pq.empty())
	{
		int v = pq.top().second;

		pq.pop();

		for(it = graph[v].begin(); it != graph[v].end(); ++it)
		{
			int weight = it->first;
			int u = it->second;

			if(dist[u] >  ( weight + dist[v] ))
			{
				dist[u] = weight + dist[v];
				pq.push( make_pair (-dist[u], u) );
			}
		}
	}
}

int main ()
{
  cin >> V >> E;
	
	dist.resize(V,inf);
	visited.resize(V,false);
	graph.resize(V);

	for(int i = 0; i < E; ++i)
	{
		int from,to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back( make_pair( weight, to ) );
		graph[to].push_back( make_pair ( weight, from ) );
	}
	
	dijkstra(3);
	
}