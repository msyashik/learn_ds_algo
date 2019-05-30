#include <bits/stdc++.h>

using namespace std;

vector< pair<int, pair<int, int> > >p;
vector<pair<int,int>>sb;
int par[105];
vector<int>vec[105];
int sum = 0;
int f = 0;
int n, e, a, b,cost,t;

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
		
		if(f == 0) sb.push_back(make_pair(a,b));
		
		int len = vec[v].size();
		for(int i = 0; i < len; i++)
		{
			par[vec[v][i]] = u;
			vec[u].push_back(vec[v][i]);
		}
		
	}
}

void init()
{
	for(int i = 1; i <= n; i++) par[i] = i;
}

void clee()
{
	for(int i = 1; i <= n; i++) vec[i].clear();
}

int main()
{   
    sum = 0;
    
    f = 0;
    
    cin >> n >> e;
    
    for(int i = 1; i <= n; i++) par[i] = i;
    
    for(int i = 1; i <= e; i++)
    {
		 cin >> a >> b >> cost;
		 p.push_back(make_pair(cost, make_pair(a,b)));
	}
	
	sort(p.begin(), p.end());
	
	int lenn = p.size();
	
	for(int i = 0; i < lenn; i++)
	{
		unions(p[i].second.first, p[i].second.second,p[i].first); 
	}
	
	cout << sum << " ";//cost of mst
	
	//second best mst
	
	f = 1;
	
	int len = sb.size();
	int ans = INT_MAX, anss = sum;
	
	for(int i = 0; i < len; i++)
	{
		init();
		clee();
		sum = 0;
		
		for(int j = 0; j < lenn; j++)
		{
			if(!(p[j].second.first == sb[i].first && p[j].second.second == sb[i].second))
			{
				unions(p[j].second.first, p[j].second.second,p[j].first);
			}
		}
		
		if(sum <= ans && sum >= anss) ans = sum;
	}
        cout << ans << endl;  //cost of second best mst
        
        sb.clear();	
        clee();
        p.clear();
    return 0;	
}
