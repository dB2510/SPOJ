#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

struct square
{
	lli sq;
	lli number;
	lli lazy;
	lli lazyset;
};

square tree[400001];

void buildTree(lli arr[],lli v,lli tl,lli tr)
{
	if(tl==tr)
	{
		tree[v].number=arr[tl];
		tree[v].sq=arr[tl]*arr[tl];
		tree[v].lazy=0;
		tree[v].lazyset=0;
	}
	else
	{
		lli mid=(tl+tr)/2;
		buildTree(arr,2*v,tl,mid);
		buildTree(arr,2*v+1,mid+1,tr);
		tree[v].sq=tree[2*v].sq + tree[2*v+1].sq;
		tree[v].number=tree[2*v].number + tree[2*v+1].number;
		tree[v].lazy=0;
		tree[v].lazyset=0;
	}
}

void push(lli v,lli tl,lli tr)
{
	lli mid=(tl+tr)/2;
	if(tree[v].lazyset)
	{
		tree[2*v].lazy=0;
		tree[2*v+1].lazy=0;
		tree[2*v].sq=(mid-tl+1)*tree[v].lazyset*tree[v].lazyset;
		tree[2*v].number=(mid-tl+1)*tree[v].lazyset;
		tree[2*v+1].sq=(tr-mid)*tree[v].lazyset*tree[v].lazyset;
		tree[2*v+1].number=(tr-mid)*tree[v].lazyset;
		tree[2*v].lazyset=tree[v].lazyset;
		tree[2*v+1].lazyset=tree[v].lazyset;
		tree[v].lazyset=0;
	}
	if(tree[v].lazy)
	{
		tree[2*v].sq+=tree[2*v].number*(2*tree[v].lazy) + (mid-tl+1)*tree[v].lazyset*tree[v].lazyset;
		tree[2*v+1].sq+=tree[2*v+1].number*(2*tree[v].lazy) + (tr-mid)*tree[v].lazyset*tree[v].lazyset;	
		tree[2*v].number+=(mid-tl+1)*tree[v].lazyset;
		tree[2*v+1].number+=(tr-mid)*tree[v].lazyset;
		tree[2*v].lazy+=tree[v].lazy;
		tree[2*v+1].lazy+=tree[v].lazy;
		tree[v].lazy=0;
	}
}

void updateRange(lli v,lli tl,lli tr,lli l,lli r,lli add)
{
	if(l>r)
		return;
	if(tl==l && tr==r)
	{
		tree[v].sq+=((r-l+1)*add*add + 2*tree[v].number*add);
		tree[v].number+=(r-l+1)*add;
		tree[v].lazy=add;

	}
	else
	{
		push(v,tl,tr);
		lli mid=(tl+tr)/2;
		updateRange(2*v,tl,mid,l,min(r,mid),add);
		updateRange(2*v+1,mid+1,tr,max(l,mid+1),r,add);
		tree[v].sq=tree[2*v].sq + tree[2*v+1].sq;
		tree[v].number=tree[2*v].number + tree[2*v+1].number;
	}
}


void updateAssign(lli v,lli tl,lli tr,lli l,lli r,lli assign)
{
	if(l>r)
	{
		return;
	}
	if(tl==l && tr==r)
	{
		tree[v].sq=(r-l+1)*assign*assign;
		tree[v].number=(r-l+1)*assign;
		tree[v].lazy=0;
		tree[v].lazyset=assign;
	}
	else
	{
		push(v,tl,tr);
		lli mid=(tl+tr)/2;
		updateAssign(2*v,tl,mid,l,min(r,mid),assign);
		updateAssign(2*v+1,mid+1,tr,max(l,mid+1),r,assign);
		tree[v].sq=tree[2*v].sq+tree[2*v+1].sq;
		tree[v].number=tree[2*v].number + tree[2*v+1].number;
	}
}

lli query(lli v,lli tl,lli tr,lli l,lli r)
{
	if(l>r)
	{
		return 0;
	}
	if(l<=tl && tr<=r)
	{
		return tree[v].sq;
	}
	push(v,tl,tr);
	lli mid=(tl+tr)/2;
	lli ans1=query(2*v,tl,mid,l,min(r,mid));
	lli ans2=query(2*v+1,mid+1,tr,max(l,mid+1),r);
	lli ans;
	ans=ans1 + ans2;
	return ans;
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
for(lli k=1;k<=t;k++)
{
	cout<<"Case "<<k<<":\n";
	f(i,0,400001)
	{
		tree[i].sq=0;
		tree[i].number=0;
		tree[i].lazy=0;
		tree[i].lazyset=0;
	}
	lli n,q,type;
	cin>>n>>q;
	lli arr[n];
	f(i,0,n)
	cin>>arr[i];
	buildTree(arr,1,0,n-1);
	while(q--)
	{
		cin>>type;
		if(type==2)
		{
			// Querying on the for the sum of squares
			lli l,r;
			cin>>l>>r;
			l--;
			r--;
			lli ans=query(1,0,n-1,l,r);
			cout<<ans<<endl;
		}
		if(type==1)
		{
			// Adds x to all numbers in the indices
			lli l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			updateRange(1,0,n-1,l,r,x);
		}	
		if(type==0)
		{
			// Changing the value this range
			lli l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			updateAssign(1,0,n-1,l,r,x);
		}
	}
	// f(i,1,2*n)
	// cout<<tree[i].sq<<" ";
}
return 0;
}
