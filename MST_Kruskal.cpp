//MST(Kruskal)

#include <bits/stdc++.h>

using namespace std;

vector< pair<int, pair<int, int> > >p;
int par[100];
vector<int>vec[100];
int sum = 0;

int fr(int r)
{
	if(par[r] == r) return r;
	return par[r] = fr(par[r]);
}


void unions(int a, int b, int cost)
{
	int u = fr(a);
	int v = fr(b);
	
	if(u != v)
	{
		par[v] = u;
		vec[u].push_back(v);
		sum += cost;
		int len = vec[v].size();
		for(int i = 0; i < len; i++)
		{
			par[vec[v][i]] = u;
			vec[u].push_back(vec[v][i]);
		}
		
	}
}

int main()
{
    int n, e, a[200005], b[200005], cost[200005];
    
    cin >> n >> e;
    
    for(int i = 1; i <= n; i++) par[i] = i;
    
    for(int i = 1; i <= e; i++)
    {
		 cin >> a[i] >> b[i] >> cost[i];
		 p.push_back(make_pair(cost[i], make_pair(a[i],b[i])));
	}
	
	sort(p.begin(), p.end());
	
	int lenn = p.size();
	
	for(int i = 0; i < lenn; i++)
	{
		unions(p[i].second.first, p[i].second.second,p[i].first); 
	}
	
	cout << sum << "\n";
    return 0;	
}
