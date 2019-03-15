#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin>>t;
    while(t--)
    {
    	int m,n;
    	cin>>m>>n;
    	char graph[m][n];
    	pair<int,int>src,des;
    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cin>>graph[i][j];
    			if(graph[i][j]=='$')
    			{
    				src.first=i;
    				src.second=j;
    			}
    			if(graph[i][j]=='#')
    			{
    				des.first=i;
    				des.second=j;
    			}
    		}
    	}
    	int distance[m][n];
    	memset(distance,0,sizeof(distance));
    	bool visited[m][n];
    	memset(visited,false,sizeof(visited));
    	queue<pair<int,int>>q;
    	q.push(src);
    	while(!q.empty())
    	{
    		pair<int,int>v;
    		v.first=q.front().first;
    		v.second=q.front().second;
    		q.pop();
    		for(int i=0;i<m;i++)
    		{
    			for(int j=0;j<n;j++)
    			{
    				if(i==v.first+1 && j==v.second && graph[i][j]!='*' && !visited[i][j])
    				{
    					visited[i][j]=true;
    					q.push(mp(i,j));
    					distance[i][j]=distance[v.first][v.second]+1;
    				}
    				if(i==v.first && j==v.second+1 && graph[i][j]!='*' && !visited[i][j])
    				{
    					visited[i][j]=true;
    					q.push(mp(i,j));
    					distance[i][j]=distance[v.first][v.second]+1;
    				}
    				if(i==v.first-1 && j==v.second && graph[i][j]!='*' && !visited[i][j])
    				{
    					visited[i][j]=true;
    					q.push(mp(i,j));
    					distance[i][j]=distance[v.first][v.second]+1;
    				}
    				if(i==v.first && j==v.second-1 && graph[i][j]!='*' && !visited[i][j])
    				{
    					visited[i][j]=true;
    					q.push(mp(i,j));
    					distance[i][j]=distance[v.first][v.second]+1;
    				}
    			}
    		}	
    	}
    	if(distance[des.first][des.second]==0)
    		cout<<"-1"<<endl;
    	else
    		cout<<distance[des.first][des.second]<<endl;
    }
return 0;
}
