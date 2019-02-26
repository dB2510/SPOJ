#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair
bool mycomp(const pair<lli,lli> &a, 
              const pair<lli,lli> &b) 
{ 
    return (a.second < b.second); 
} 

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
	lli n,start,end;
	cin>>n;
	vector<pair<lli,lli>>v;
	f(i,0,n)
	{
		cin>>start>>end;
		// v[i].first=start;
		// v[i].second=second;
		v.pb(mp(start,end));
	}
	sort(v.begin(),v.end(),mycomp);
	lli temp=v[0].second,count=1;
	f(i,1,n)
	{
		if(temp<=v[i].first)
		{
			temp=v[i].second;
			count++;
		}
	}
	cout<<count<<endl;
}

return 0;
}
