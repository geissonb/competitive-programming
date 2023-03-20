#include<bits/stdc++.h>

using namespace std;

int main () 
{

	int n, C;
	
	while(true)
	{
		cin >> n; 
		if(n == 0)
			break;
		cin >> C;	
				
		vector<int> valor(n);
		vector<int> peso(n);
		vector< vector <int> > Mochila(n+1, vector<int>(C+1, 0));
		map<pair<int, int>, list < int > > itens_mochila;
		list< int > aux;
				
		for(int i = 0; i<n; ++i)
		{
			cin >> valor[i];
			cin >> peso[i];
		}
		
		for(int Column = 0; Column <= C; ++Column)
		{
			for(int row = 0; row <= n; ++row)
			{
			
				if(row == 0)
					continue;
								
				int x = Mochila[(row-1)][Column];
				aux = itens_mochila[make_pair(row-1,Column)];

				if((Column-peso[(row-1)]) >= 0)
				{
					int y = Mochila[(row-1)][(Column-peso[(row-1)])] + valor[(row-1)];
					if(x<y)
					{
						x = y;
						aux = itens_mochila[make_pair(row-1,Column-peso[(row-1)])];
						aux.push_back(valor[row-1]);
					}
				}		
				Mochila[row][Column] = x;
				itens_mochila[make_pair(row,Column)] = aux;
				aux.clear();
			}
		} 

		/*for(int i = 0; i<=n; ++i)
		{
			for(int j = 0; j<=C; ++j)
			{
				Mochila[i][j] /10 >= 1 ? (cout << Mochila[i][j] << " | ") :  ( cout << Mochila[i][j] << "  | " );
			}
			cout << endl;
		}*/
		cout << Mochila[n][C] << " min." << endl;
		aux = itens_mochila[make_pair(n,C)];

		list<int> :: iterator it;

		int i = 1;
		int j = aux.size();

		cout << '[';

		for(it = aux.begin(); it!=aux.end(); it++, ++i)
		{
			if (i != j)
				cout << *it << ',';
			else
				cout << *it << ']' << endl;	

		}
		aux.clear();
		valor.clear();
		peso.clear();
		Mochila.clear();
	}	
}
