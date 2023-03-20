#include<bits/stdc++.h>

using namespace std;

typedef pair <int , int > pi;
typedef pair <int , pi> ppi;
vector < ppi > edges;
vector < ppi > mst;
vector<int>parent;
vector<int>conex;
int V, E;

int pai (int v)
{
	while(v != parent[v])
		v = parent[v];
  return v;
}
 
void insert(int i, int j)
{
	if(conex[j] > 0)
	{
		conex[i] += conex[j];
		conex[j] = 0;
	}
	conex[i]++;
	parent[j] = i;
}

int kruskal()
{
	sort(edges.begin(), edges.end());
	vector< ppi > :: iterator it;

	for(it = edges.begin(); it != edges.end(); ++it)
	{
		int u = it->second.first;
		int v = it->second.second;
		int j = pai(parent[u]);
		int k = pai(parent[v]);

		if(j == k)
		{
			continue;
		}

		else
		{
			if(conex[j] >= conex[k])
				insert(j,k);

			else
				insert(k,j);

			mst.push_back(make_pair(it->first, make_pair(u , v)));
		}
	}

	int k = 0;
	for(it = mst.begin(); it != mst.end(); ++it)
	{
		k += it->first;
	}
	return k;
}

int main ()
{

	cin >> V >> E;

	edges.reserve( E );
	mst.reserve( V-1 );
	conex.resize(V,0);
	parent.resize(V);

	for(int i = 0; i < V; ++i)
	{
    parent[i] = i;
	}

	for(int i = 0; i < E; ++i)
	{
		int from, to, weight;

		cin >> from >> to >> weight;

		edges.push_back( make_pair(weight, make_pair((from-1), (to-1))));
	}

	cout << kruskal() << endl;

}
