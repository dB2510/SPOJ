#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define MAX 300005;
#define MAX1 = 1e6 + 5;

int BIT[MAX];
int n;
int last[MAX1];
pair<int,pair<int,int>>q[MAX];

void update(int x,int delta)
{
	for(;x<=n;x+=x&(-1*x))
	{
		BIT[x]+=delta;
	}
}

int ans(int x)
{
	int sum=0;
	for(;x>0;x-=x&(-1*x))
		sum+=BIT[x];
	return sum;
}

int main() {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    memset(last,-1,sizeof(last));
    scanf("%d", &n);
    int arr[n],d;
    f(i,0,n)
    scanf("%d", &arr[i]);
    scanf("%d", &d);
    
    f(i,0,d)
    {
    	scanf("%d %d", &q[i].second.first, &q[i].first);
    	q[i].second.second=i;
    }
    sort(q,q+d);
    int answer[d];
    int j=0;
    f(i,0,n)
    {
    	if(last[arr[i]]!=-1)
    		update(last[arr[i]],-1);
    	last[arr[i]]=i+1;
    	update(i+1,1);
    	while(j<d && i+1==q[j].first)
    	{
    	    answer[q[j].second.second]=ans(q[j].first)-ans(q[j].second.first - 1);
    		j++;
    	}
    }
    f(i,0,d)
    printf("%d\n",answer[i]);
return 0;
}
