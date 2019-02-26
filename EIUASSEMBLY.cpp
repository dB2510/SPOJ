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
lli t;
cin>>t;
while(t--)
{
	lli n,m;
	cin>>n>>m;
	vector<pair<lli,lli>> v;
	f(i,0,n)
	{
		lli x,y;
		cin>>x>>y;
		v.pb(mp(x,y));
	}

	lli start=0, end=LLONG_MAX/10,mid,ans=-1;
	while(start<end)
	{
		mid=(start+end)>>1;
		bool flag=true;
		lli need=0;
		f(i,0,n)
		{
			lli d=mid-v[i].first;
			if(d>0)
				need+=d*v[i].second;
			if(need>m)
				flag=false;
		}
		if(flag)
		{
			start=mid+1;
			ans=max(ans,mid);
		}
		else
			end=mid;
	}
	cout<<ans<<endl;
}
return 0;
}
