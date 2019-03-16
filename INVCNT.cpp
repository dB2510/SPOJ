	#include <bits/stdc++.h>
	using namespace std;
	#define lli long long int 
	#define MOD 1000000007
	#define f(i,a,n) for(lli i = a; i < n; i++)
	#define pb push_back
	#define mp make_pair

	lli BIT[10000001];

	// void update(lli x,lli n,lli delta)
	// {
	// 	for(;x<=n;x+=x&(-1*x))
	// 	{
	// 		BIT[x]+=delta;
	// 	}
	// }

	void update(lli x,lli n)
	{
		for(;x<=n;x+=x&(-1*x))
		{
			BIT[x]+=1;
		}
	}

	lli query(lli l,lli r)
	{
		lli sum1=0,sum2=0;
		for(lli i=l-1;i>0;i-=i&(-1*i))
			sum2+=BIT[i];
		for(lli i=r;i>0;i-=i&(-1*i))
			sum1+=BIT[i];
		// cout<<"here";
		return sum1-sum2;
	}

	int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
	// #endif
	    // lli arr[]={2,3,8,6,1};
	    // lli n=5;
	    // for(lli i=0;i<n;i++)
	    // 	update(i+1,n,arr[i]);
	    // cout<<query(1,5);
	    lli t;
	    cin>>t;
	    while(t--)
	    {
	    	memset(BIT,0,sizeof(BIT));
	    	lli n;
	    	cin>>n;
	    	lli arr[n],max=LLONG_MIN;
	    	for(lli i=0;i<n;i++)
	    		{
	    			cin>>arr[i];
	    			if(arr[i]>max)
	    				max=arr[i];
	    		}
	    	lli sum=0;
	    	for(lli i=0;i<n;i++)
	    	{
	    		sum+=query(arr[i]+1,max);
	    		update(arr[i],max);
	    	}
	    	cout<<sum<<endl;
	    	// cout<<BIT[2];
	    }
	return 0;
	}

