
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
vector<list< pi > > graph;
vector<int> parent;
vector<int> sequence;
int V,E;

void bfs(int source)
{
  int seq = 1;

  queue<int> q;

  q.push(source);
  parent[source] = -1;
  sequence[source] = seq;

  while(!q.empty())
  {
    int v = q.front();
    q.pop();
    list< pair<int,int> > :: iterator it;

  for(it = graph[v].begin(); it != graph[v].end(); ++it)
    {
      if(parent[it->first] == -2)
      {
        seq++;
        q.push(it->first);
        parent[it->first] = v;
        sequence[it->first] = seq;
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
		graph[from].push_back(make_pair(to,weight));
		graph[to].push_back(make_pair(from,weight));
	}

	bfs(3);

	for(int i = 0; i < V; ++i)
	{
    cout
    cout << i << "-> " << parent[i] << " : " << sequence[i] << endl;
	}
}
