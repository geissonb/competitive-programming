#include<bits/stdc++.h>

using namespace std;

int ldm(multiset<int>& S, multiset<int>& S1, multiset<int>& S2)
{
	int s1, s2, dif;
	
	if( S.size() == 1)
	{
		S1.clear();		
		S1.insert(*S.begin());
		S2.clear();
		return *S.begin();
	}
	else
	{
		s1 = *S.rbegin();
		S.erase(S.find(*S.rbegin()));
		s2 = *S.rbegin();
		S.erase(S.find(*S.rbegin()));
		dif = s1 - s2;
		S.insert(dif);
		
		int m_dif = ldm(S,S1,S2);
		
		if(S1.find(dif) == S1.end())
		{
			swap(S1,S2);
		}
		S1.erase(S1.find(dif));
		S1.insert(s1);
		S2.insert(s2);
		
		return m_dif;
	}
}

int main ()
{
	multiset <int> S, S1, S2;
	
	int N, k;
	
	cin >> N;
	
	for(int m = 0; m < N; ++m)
	{
		cin >> k;
		
		for(int i = 0; i < k; ++i)
		{
			int j; 
			cin >> j;
			S.insert(j);
		}
		
		cout << ldm(S, S1, S2) << endl;
		
		multiset<int> :: iterator it;
		
		for (it=S1.begin(); it!=S1.end(); ++it)
		{
			cout << *it << ' ';
		}
		
		cout << endl;
		
		for (it=S2.begin(); it!=S2.end(); ++it)
		{
			cout << *it << ' ';
		}

		S.clear();
		S1.clear();
		S2.clear();
		
		cout << endl;
	}
}
