#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define Max 200

int smoke[Max][Max],color[Max][Max];

int mixtures(int p[],int i,int j)
{
	if(smoke[i][j]!=-1)
		return smoke[i][j];
	else
	{
		int smoke_mix=INT_MAX,temp;
		if(i==j)
			smoke[i][j]=0;
		else
		{
			f(k,i,j)
			{
				temp=mixtures(p,i,k)+mixtures(p,k+1,j)+ color[i][k]*color[k+1][j];
				if(smoke_mix>temp)
				{
					smoke_mix=temp;
					color[i][j]=(color[i][k]+color[k+1][j])%100;
				}
			}
			smoke[i][j]=smoke_mix;
		}
		return smoke[i][j];
	}
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
int n;
while(cin>>n)
{
	f(i,0,Max)
	f(j,0,Max)
	smoke[i][j]=-1;
	f(i,0,Max)
	f(j,0,Max)
	color[i][j];
	int p[n];
	f(i,0,n)
	cin>>p[i];
	f(i,0,n)
	color[i][i]=p[i];
	cout<<mixtures(p,0,n-1)<<endl;
}

return 0;
}
