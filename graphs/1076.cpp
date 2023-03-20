#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
vector<bool> verify;
int V,E;

int dfs(int source)
{
  int k = 0;
  stack<int> s;

  s.push(source);
  verify[source] = true;

  while(!s.empty())
  {
    int v = s.top();
    s.pop();
    if (v != source)
      k++;

    list<int> :: iterator it;

    for(it = graph[v].begin(); it != graph[v].end(); ++it)
    {
      if(verify[*it] == false)
      {
        verify[*it] = true;
        s.push(*it);
        k++;
      }
    }
  }

  verify.clear();
  graph.clear();

  return k;
}

int main ()
{
  int N,s;
  cin >> N;
  for(int j = 0; j < N; ++j)
  {
    cin >> s;
    cin >> V >> E;

    verify.resize(V,false);
    graph.resize(V);

    for(int i = 0; i < E; ++i)
    {
      int from, to;
      cin >> from >> to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    //int ans = dfs(s);
    cout << dfs(s) << endl;
  }
}
