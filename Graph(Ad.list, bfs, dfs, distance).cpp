#include <bits/stdc++.h>

using namespace std;

int dist[1000];
int visited[1000];
vector<int>v[1000];
queue<int>q;

//CLI = Command Line Interface

class graph
{
    public:    	
    
	void add_edge(int a, int b);
	void print_list(int n);
	void dfs(int n);
	void bfs(int src);
	void print_distance(int n);
};

class CLI
{	
	public:
	
	graph g1;
	
	void adj_list(int n)
	{
		cout << "Adjacency List\n";	
	    	
	    g1.print_list(n);
	
	    cout << "\n";
	
    }
    
    void dfs(int n)
    {
	    memset(visited, 0, sizeof(visited));
	
	    cout << "DFS\n";
	
	    for(int i = 1; i <= n; i++)
	    {
		if(visited[i] == 0)
		{
			cout << i << " ";
			g1.dfs(i);
		}
	    }
	
	    cout << "\n\n";
	}
	
	void bfs()
	{
		memset(visited, 0, sizeof(visited));
	
	    cout << "\nBFS\n";
	
	    g1.bfs(1);
	
	    cout << "\n\n";
	}
	
	void distance(int n)
	{
		cout << "\nDistance\n";
	
	    g1.print_distance(n);
	
	    cout << "\n";
	}
	
	void edges(int e)
	{
		int a, b;
		
		for(int i = 1; i <= e; i++)
	    {
		
		cin >> a >> b;
		
		g1.add_edge(a,b);
		
	    }
		
		cout << "\n";
	}
    
};

void graph :: add_edge(int a, int b)
{
	v[a].push_back(b);
	v[b].push_back(a);
}

void graph :: print_list(int n)
{
	for(int i = 1; i <= n; i++)
	{
		int len = v[i].size();
		
		cout << i << ": ";
		
		for(int j = 0; j < len; j++)
		{
			cout << v[i][j] << " ";
		}
		
		cout << "\n";
	}
	
}

void graph :: dfs(int n)
{
    visited[n] = 1;
    
    int len = v[n].size();
    
    for(int i = 0; i < len; i++)
    {
	    int ans = v[n][i];
	    
	    if(visited[ans] == 0)
	    {
			cout << ans << " ";
			dfs(ans);
		}
	}
}

void graph :: bfs(int src)
{
	
    q.push(src);
    
    visited[src] = 1;
    
    dist[src] = 0;
    
    while(!q.empty())
    {
		int top = q.front();
		cout << top << " ";
		q.pop();
		
		
		int len = v[top].size();
		
		for(int i = 0; i < len; i++)
		{
			int ans = v[top][i];
			if(visited[ans] == 0)
			{
				q.push(ans);
				visited[ans] = 1;
				dist[ans] = dist[top] + 1;
			}
		}
	}
}

void graph :: print_distance(int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << i  << " " << dist[i] << "\n";
	}
}

int main()
{
	CLI c;
	
	int n, e, number;
	
	cout << "Enter total number of Nodes\n";
	
	cin >> n;
	
	cout << "Enter total number of Edges\n";
	
	cin >> e;
	
	cout << "Enter the nodes you want to connect\n";
	
	c.edges(e);
	
	while(1)
	{
	
	cout << "Enter 1 to print the Adjacency list\n";
	cout << "Enter 2 to print the Depth First Search(DFS)\n";
	cout << "Enter 3 to print the Breadth First Search(BFS)\n";
	cout << "Enter 4 to print the Distance of the nodes\n";
	cout << "Enter 5 to Exit\n";
	
	cin >> number;
	
	switch(number)
	{
		
	case 1:
	
	c.adj_list(n);
	
	break;
	
    case 2:
	
	c.dfs(n);
	
    break;
    
    case 3:
		
	c.bfs();
	
    break;
    
    case 4:
		
	c.distance(n);
	
    break;
    
    default:
		exit(1);
    
    }
    
}
	
	return 0;
}
