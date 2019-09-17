#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define fb(i,a,n) for(lli i=n-1;i>=a;i--)
 
#define p64 pair<lli,lli>
#define v64 vector<lli>
#define p32 pair<int,int>
#define v32 vector<int>
#define vp64 vector<pair<lli , lli >>
#define vp32 vector<pair<int , int>>
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))
lli dp[105][105][2];
 
lli solve(lli n,lli k,lli currentn,lli currentk,int previousbit)
{
    if(currentn>n or currentk>k)
    {
        return 0;
    }
 
    if(currentn==n and currentk==k)
    {
        return dp[currentn][currentk][previousbit] = 1;
    }
     
    if(dp[currentn][currentk][previousbit]!=-1)
    {
        return dp[currentn][currentk][previousbit];
    }
    // cout<<currentk<<" "<<currentn<<endl;
 
    if(previousbit==0)
    {
        return dp[currentn][currentk][previousbit] = solve(n,k,currentn+1,currentk,0) + solve(n,k,currentn+1,currentk,1);
    }
    else
    {
        return dp[currentn][currentk][previousbit] = solve(n,k,currentn+1,currentk,0) + solve(n,k,currentn+1,currentk+1,1);
    }
   
 
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
cin>>t;
while(t--){
    lli test , n , k;
    cin>>test>>n>>k;
   
    f(i,0,n+1)
    {
        f(j,0,k+1)
        {
            dp[i][j][0]= -1;
            dp[i][j][1]=-1;
        }
    }
 
    lli ans = solve(n,k,0,0,0);
    // lli ans1 = dp[n][k];
    // f(i,0,n+1)
    // f(j,0,k+1)
    // cout<<dp[i][j]<<endl;
    cout<<test<<" "<<ans<<endl;
}
return 0;
}
