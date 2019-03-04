#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
// #define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

struct data
{
	lli max_pre_sum;
	lli max_suff_sum;
	lli total_sum;
	lli max_sub_sum;
};

data tree[400000];

data combine(data a,data b)
{
	data res;
	res.max_pre_sum=max(a.max_pre_sum,a.total_sum+b.max_pre_sum);
	res.max_suff_sum=max(b.max_suff_sum,b.total_sum+a.max_suff_sum);
	res.total_sum=a.total_sum+b.total_sum;
	res.max_sub_sum=max(max(a.max_sub_sum,b.max_sub_sum),a.max_suff_sum+b.max_pre_sum);
	return res;
}

data make_data(lli val)
{
	data a;
	a.total_sum=val;
	// lli zero=0;
	a.max_suff_sum=a.max_pre_sum=a.max_sub_sum=val;
	return a;
}

void build(lli arr[],lli v,lli tl,lli tr)
{
	if(tr==tl)
	{
		tree[v]=make_data(arr[tl]);
	}
	else
	{
		lli mid=(tl+tr)/2;
		build(arr,2*v,tl,mid);
		build(arr,2*v+1,mid+1,tr);
		tree[v]=combine(tree[2*v],tree[2*v+1]);
	}
}

data query(lli v,lli tl,lli tr,lli l,lli r)
{
	if(l>r)
	{
		data t;
		t.max_pre_sum=t.max_suff_sum=t.max_sub_sum=INT_MIN;
		t.total_sum=0;
		return t;
	}
	if(tl==l && tr==r)
	{
		return tree[v];
	}
	else
	{
		lli mid=(tl+tr)/2;
		data q1=query(2*v,tl,mid,l,min(mid,r));
		data q2=query(2*v+1,mid+1,tr,max(l,mid+1),r);
		return combine(q1,q2);
	}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

lli n,q;
cin>>n;
lli arr[n];
for(lli i=0;i<n;i++)
cin>>arr[i];
// lli presum[n];
// presum[0]=arr[0];
// for(lli i=0;i<n;i++)
// presum[i]=presum[i-1]+arr[i];
build(arr,1,0,n-1);
cin>>q;
while(q--)
{
	lli l,r;
	cin>>l>>r;
	l--;
	r--;
	cout<<query(1,0,n-1,l,r).max_sub_sum<<endl;
}
return 0;
}
