#include<bits/stdc++.h>

using namespace std;

int V, E;
typedef pair<int,int> pi;
vector<list<pi>>graph;
const int inf = 0x3f3f3f3f;
vector<bool>inMST;
vector<int>key;
vector<int>parent;


int prim(int source)
{
  priority_queue< pi > pq;
  pq.push(make_pair(0,source));
  key[source] = 0;
  list<pi>::iterator it;

  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    if(inMST[u] == true)
      continue;

    inMST[u] = true;

    for(it = graph[u].begin(); it!=graph[u].end(); ++it)
    {
      int v = it->first;
      int w = it->second;

      if((inMST[v] == false) && (key[v] > w))
      {
        key[v] = w;
        parent[v] = u;
        pq.push(make_pair(-key[v],v));
      }
    }
  }

  int k = 0;
  for(int i = 0; i <= V; ++i)
  {
    k += key[i];
  }
  return k;
}

int main()
{

  cin >> V >> E;

  graph.resize(V);
  inMST.resize(V,false);
  parent.resize(V, -1);
  key.resize(V,inf);

  for(int i = 0; i < E; ++i)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[(from-1)].push_back(make_pair((to-1),weight));
    graph[(to-1)].push_back(make_pair((from-1),weight));
  }

  int ans = prim(0);

  cout << ans << endl;

}
