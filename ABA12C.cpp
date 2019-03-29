    #include <iostream>
    using namespace std;
     
    int apples(int n,int k,int price[])
    {
        int dp[k+1];
        for(int i=1;i<=k;i++)
        dp[i]=price[i];
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(dp[j]==-1 || price[i-j]==-1)
                {
                    continue;
                }
                if(dp[i]==-1)
                dp[i]=dp[j]+price[i-j];
                else
                {
                    dp[i]=min(dp[i],dp[i-j]+price[j]);
                }
            }
        }
        return dp[k];
    }
     
    int main() {
    	ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    	int t;
    	cin>>t;
    	while(t--)
    	{
    	    int n,k;
    	    cin>>n>>k;
    	    int price[k+1];
    	    for(int i=1;i<=k;i++)
    	    cin>>price[i];
    	    cout<<apples(n,k,price)<<endl;
    	}
    	return 0;
    } 
