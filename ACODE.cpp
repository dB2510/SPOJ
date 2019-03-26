#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define MAX 5000

lli dp[MAX+1];

lli alphaCode(string s,lli n)
{
    if(n==1)
        return 1;
    if(n<=0)
    	return 0;
    if(dp[n]!=-1)
        return dp[n];

    lli a=s[n-1]-'0',b=s[n-2]-'0';

    if(n==2)
    {
        lli temp=(s[0]-'0')*10 + (s[1]-'0');
        if(temp>26)
            dp[n]=1;
        else
            dp[n]=2;
        // return dp[n];
        if(a==0 and a>2)
        	return 0;
        if(a==0 and b<=2)
        	return 1;
    }
    else if(a!=0 and b!=0)
    {
    	lli sam=b*10 + a;
	    if(sam>26)
	        dp[n]=alphaCode(s,n-1);
	    else
	        dp[n]=alphaCode(s,n-1)+alphaCode(s,n-2);
	    // return dp[n];
    }
    else if(a==0 and (b==0 or b>2))
    	return 0;
    else if(a!=0 and b==0)
    {
    	dp[n]=alphaCode(s,n-1);
    }
    else if(a==0 and (b<=2 and b!=0))
    	dp[n]=alphaCode(s,n-2);
    return dp[n];
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    while(1)
    {
        memset(dp,-1,sizeof(dp));
        string n;
        cin>>n;
        if(n[0]=='0')
            break;
        lli num=n.length();
        cout<<alphaCode(n,num)<<endl;
    }
return 0;
}
