#include <bits/stdc++.h>

using namespace std;

int dp[100][1000];
int coin[100];
int n;

int  k;

int call(int i, int amount)
{
	if(i >= n)
	{
		if(amount == k) return 1;
		else return 0;
	}
	
	int ret1 = 0, ret2 = 0;
	
	if(dp[i][amount] != -1) {return dp[i][amount];}
	
	if (amount +coin[i] <= k ) 
	{
		
		ret1 = call(i, amount + coin[i]);
    }
    ret2 = call(i+1, amount);
    
    return dp[i][amount] = ret1 | ret2;
}

int main()
{
	cin >> n >> k;
	
	for(int i  = 0; i < n; i++) cin >> coin[i];
	
	memset(dp, -1, sizeof(dp));
	
	cout << call(0, 0)<< "\n";	
	
	return 0;
}
