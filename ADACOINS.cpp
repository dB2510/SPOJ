#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define MAX 100001


int main() {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t=1;
// cin>>t;
while(t--)
{
	lli n,q;
	// cin>>n>>q;
	scanf("%lld%lld",&n,&q);
	bitset<MAX>bit;
	bit[0]=1;
	lli arr[n];
	f(i,0,n)
	scanf("%lld",&arr[i]);
	f(i,0,n)
	{
		bit = bit | bit << arr[i];
	}
	lli pre[MAX];
	pre[0]=0;
	f(i,1,bit.size())
	pre[i]=pre[i-1]+bit[i];
	while(q--)
	{
		lli l,r;
		// cin>>l>>r;
		scanf("%lld%lld",&l,&r);
		lli res=pre[r]-pre[l-1];
		printf("%lld\n",res);
	}
}
return 0;
}
