#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
vector<list< pi > > graph;
vector<int> parent;
vector<int> sequence;
int V,E;

void dfs(int source)
{
  int seq = 0;

  stack<int> s;

  s.push(source);
  parent[source] = -1;
  sequence[source] = 0;

  while(!s.empty())
  {
    int v = s.top();
    s.pop();

    if (v != source)
    {
      seq = sequence[parent[v]];
      sequence[v] = ++seq;
    }

    list< pi > :: iterator it;

    for(it = graph[v].begin(); it != graph[v].end(); ++it)
    {
      if(parent[it->second] == -2)
      {
        s.push(it->second);
        parent[it->second] = v;
      }
    }
  }
}

int main ()
{

	cin >> V >> E;

	parent.resize(V,-2);
	sequence.resize(V,0);
	graph.resize(V);

	for(int i = 0; i < E; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back(make_pair(weight,to));
		graph[to].push_back(make_pair(weight,from));
	}

	dfs(3);

	for(int i = 0; i < V; ++i)
	{
    cout << i << " -> " << parent[i] << " : " << sequence[i] << endl;
	}
}
