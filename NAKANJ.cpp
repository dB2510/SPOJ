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
	pair<int,int>src,des;
	// int src[2],des[2];
	char c;
	cin>>c;
	src.first=c-'a' +1;
	cin>>src.second;
	cin>>c;
	des.first=c-'a' +1;
	cin>>des.second;
	queue<pair<int,int>>q;
	bool visited[9][9];
	int distance[9][9];
	memset(visited,false,sizeof(visited));
	memset(distance,0,sizeof(distance));
	visited[src.first][src.second]=true;
	q.push(src);
	while(!q.empty())
	{
		pair<int,int>v;
		v.first=q.front().first;
		v.second=q.front().second;
		q.pop();
		for(int i=1;i<9;i++)
		{
			for(int j=1;j<9;j++)
			{
				if(i==(v.first+1) && j==(v.second+2) && !visited[i][j])
				{
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first+1) && j==(v.second-2)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first-1) && j==(v.second-2)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first-1) && j==(v.second+2)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}//
				else if(i==(v.first+2) && j==(v.second+1) && !visited[i][j])
				{
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first+2) && j==(v.second-1)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first-2) && j==(v.second-1)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
				else if (i==(v.first-2) && j==(v.second+1)  && !visited[i][j])
				{	
					visited[i][j]=true;
					distance[i][j]=distance[v.first][v.second]+1;
					q.push(make_pair(i,j));
				}
			}
		}
	}
	cout<<distance[des.first][des.second]<<endl;
}
return 0;
}
