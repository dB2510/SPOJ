#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair

struct Node
{
	lli ans;
	lli first;
	lli second;
};

Node tree[400001];

void buildTree(lli arr[],lli v,lli tl,lli tr)
{
	if(tr-tl==1)
	{
		tree[v].ans=arr[tl]+arr[tr];
		tree[v].first=arr[tl];
		tree[v].second=arr[tr];
		lli mid=(tl+tr)/2;
		buildTree(arr,2*v,tl,mid);
		buildTree(arr,2*v+1,mid+1,tr);	
	}
	else if(tr==tl)
	{
		tree[v].ans=arr[tl];
		tree[v].first=arr[tl];
		tree[v].second=arr[tl];
	}
	else
	{
		lli mid=(tl+tr)/2;
		buildTree(arr,2*v,tl,mid);
		buildTree(arr,2*v+1,mid+1,tr);
		lli max1=max(tree[2*v].first,tree[2*v].second);
		lli max2=max(tree[2*v+1].first,tree[2*v+1].second);
		tree[v].ans=max2+max1;
		tree[v].first=max1;
		tree[v].second=max2;
		lli ans1=tree[2*v].ans;
		lli ans2=tree[2*v+1].ans;
		if(ans1>ans2)
		{
			tree[v].ans=ans1;
			tree[v].first=tree[2*v].first;
			tree[v].second=tree[2*v].second;
		}
		else
		{
			tree[v].ans=ans2;
			tree[v].first=tree[2*v+1].first;
			tree[v].second=tree[2*v+1].second;
		}
		if(tree[v].ans<max2+max1)
		{
			tree[v].ans=max2+max1;
			tree[v].first=max1;
			tree[v].second=max2;
		}
	}
}

void updateTree(int v,int tl,int tr,int pos,int value)
{
    if(tl==tr)
    {
    	tree[v].ans=value;
    	tree[v].first=value;
    	tree[v].second=value;
    }
    else
    {
        int mid=(tl+tr)/2;
        if(pos>mid)
            updateTree(2*v+1,mid+1,tr,pos,value);
        else
            updateTree(2*v,tl,mid,pos,value);
        // tree[v]=min(tree[2*v],tree[2*v+1]);
        lli max1=max(tree[2*v].first,tree[2*v].second);
		lli max2=max(tree[2*v+1].first,tree[2*v+1].second);
		tree[v].ans=max2+max1;
		tree[v].first=max1;
		tree[v].second=max2;
		lli ans1=tree[2*v].ans;
		lli ans2=tree[2*v+1].ans;
		if(ans1>ans2)
		{
			tree[v].ans=ans1;
			tree[v].first=tree[2*v].first;
			tree[v].second=tree[2*v].second;
		}
		else
		{
			tree[v].ans=ans2;
			tree[v].first=tree[2*v+1].first;
			tree[v].second=tree[2*v+1].second;
		}
		if(tree[v].ans<max2+max1)
		{
			tree[v].ans=max2+max1;
			tree[v].first=max1;
			tree[v].second=max2;
		}
    }
}


Node query(lli v,lli tl,lli tr,lli left,lli right)
{
	Node res;
	res.ans=LLONG_MIN;
	res.first=LLONG_MIN;
	res.second=LLONG_MIN;
    if(tl > right || tr < left)
        return res;
    if(tl >= left && tr <= right)
        return tree[v];
    lli mid=(tr+tl)/2;
    Node ans1=query(2*v,tl,mid,left,right);
    Node ans2=query(2*v+1,mid+1,tr,left,right);
    lli max1=max(ans1.first,ans1.second);
	lli max2=max(ans2.first,ans2.second);
	Node ANS;
	// ANS.ans=max2+max1;
	// ANS.first=max1;
	// ANS.second=max2;
	lli Ans1=ans1.ans;
	lli Ans2=ans2.ans;
	if(Ans1>Ans2)
	{
		ANS.ans=Ans1;
		ANS.first=ans1.first;
		ANS.second=ans1.second;
	}
	else
	{
		ANS.ans=Ans2;
		ANS.first=ans2.first;
		ANS.second=ans2.second;
	}
	if(ANS.ans<max2+max1)
	{
		ANS.ans=max2+max1;
		ANS.first=max1;
		ANS.second=max2;
	}
    return ANS;
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
f(i,0,n)
cin>>arr[i];
buildTree(arr,1,0,n-1);
cin>>q;
while(q--)
{
	char type;
	cin>>type;
	lli l,r;
	if(type=='U')
	{
		cin>>l>>r;
		l--;
		updateTree(1,0,n-1,l,r);
	}
	else
	{
		cin>>l>>r;
		l--;
		r--;
		Node res;
		res=query(1,0,n-1,l,r);
		cout<<res.ans<<endl;
	}
}
// Node res;
// res=query(1,0,n-1,1,3);
// cout<<res.ans<<" "<<res.first<<" "<<res.second;
return 0;
}
