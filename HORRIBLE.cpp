#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

lli tree[400020],lazy[400020];

void push(lli v,lli tl,lli tr)
{
	if(lazy[v])
	{
		tree[v]+=(tr-tl+1)*lazy[v];
		if(tr!=tl)
		{
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}
}

void update(lli v,lli tl,lli tr,lli l,lli r,lli add)
{
	push(v,tl,tr);
	if(l>r)
	{
		return;
	}
	if(l==tl && r==tr)
	{
		tree[v]+=(r-l+1)*add;
		if(tl!=tr)
		{
			lazy[2*v]+=add;
			lazy[2*v+1]+=add;
		}
		return;
	}
	else
	{
		lli mid=(tl+tr)/2;
		update(2*v,tl,mid,l,min(r,mid),add);
		update(2*v+1,mid+1,tr,max(l,mid+1),r,add);
		tree[v]=tree[2*v]+tree[2*v+1];
	}
}

lli query(lli v,lli tl,lli tr,lli l,lli r)
{
	push(v,tl,tr);
	if(l>r)
		return 0;
	if(l<=tl && tr<=r)
		return tree[v];
	lli mid=(tl+tr)/2;
	lli ans1=query(2*v,tl,mid,l,min(r,mid));
	lli ans2=query(2*v+1,mid+1,tr,max(l,mid+1),r);
	return ans1 + ans2;
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
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	lli n,q;
	cin>>n>>q;
	while(q--)
	{
		lli type;
		cin>>type;
		if(type==0)
		{
			lli l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			update(1,0,n-1,l,r,x);
		}
		if(type==1)
		{
			lli l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<query(1,0,n-1,l,r)<<endl;
		}
	}
	// for(lli i=0;i<8;i++)
	// 	cout<<query(1,0,n-1,i,i)<<endl;
	// cout<<query(1,0,n-1,3,7);
}
return 0;
}
