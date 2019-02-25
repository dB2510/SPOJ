#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

lli strength[10000000],original[10000000];
bool visited[10000000];

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t;
cin>>t;
while(t--)
{
	lli n,r,sol;
	cin>>n>>r>>sol;
	vector<vector<lli>>adj(n+1);
	f(i,0,r)
	{
		lli x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	f(i,0,n+1)
	{
		visited[i]=false;
		strength[i]=-1;
		original[i]=-1;
	}
	f(i,0,sol)
	{
		lli x,str;
		cin>>x>>str;
		strength[x]=str;
		original[x]=str;
	}
	queue<lli>q;
	// memset(visited,false,sizeof(visited));
	bool safe=true;
	q.push(1);
	visited[1]=true;
	while(!q.empty())
	{
		lli origin=q.front();
		q.pop();
		for(auto i:adj[origin])
		{
			if(!visited[i])
				q.push(i);
			visited[i]=true;
			if(strength[origin]<strength[i]-1 && original[origin]==-1)
				strength[origin]=strength[i]-1;
			if(original[i]==-1)
				strength[i]=max(strength[i],strength[origin]-1);
		}
	}

	f(i,1,n+1)
	{
		if(strength[i]<0)
		{
			safe=false;
			break;
		}	
		// cout<<strength[i]<<" ";

	}
	if(safe)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

return 0;
}
