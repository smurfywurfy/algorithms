/*input
4 2
1 2
2 3


*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vll vector<ll>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 9000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define sz(x)  ((ll)x.size())
#define DEBUG
#ifdef DEBUG
#define watch(x) cout << (#x) << " is " << (x) << endl
#else 
#define watch(x)
#endif
#define N 200002

using namespace std;

vll adj[N];
ll col[N];

void dfs(ll v)
{
	for(auto x: adj[v])
	{
		if(col[x]==-1)
		{
			col[x] = col[v]^1;
			dfs(x);
		}
		else if(col[x]^col[v]!=1)
		{
			cout << -1 << endl;
			exit(0);
		}
	}
}

int main()
{
	fastio
	ll T=1,n,m;string str;
	// cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
			cin >> p >> q;
			adj[p].eb(q);
			adj[q].eb(p);

		}
		mem(col,-1);
		for (int i = 1; i <= n; ++i)
		{
			if(col[i]==-1)
			{
				col[i]=0;
				dfs(i);
			}
		}

		vll x,y;
		for (int i = 1; i <= n; ++i)
		{
			if(col[i]) y.eb(i);
			else x.eb(i);
		}
		cout << x.size() << endl;
		for(auto t: x)
		{
			cout << t << " ";
		}cout << endl;

		cout << y.size() << endl;
		for(auto t: y)
		{
			cout << t << " ";
		}cout << endl;
		
	}
	return 0;
}