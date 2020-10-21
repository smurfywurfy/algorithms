vll adj[N];
ll vis[N];

void dfs(ll cur)
{
	vis[cur]=1;

	for(auto x: adj[cur])
	{
		if(!vis[x])
		{
			dfs(x);
		}
	}
}

