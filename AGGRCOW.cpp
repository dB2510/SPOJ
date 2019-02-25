#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool ispossible(ll int arr[],ll int n,ll int dist,ll int c)
{
    ll int cowscompleted=1,lastpos=0;
    for(ll int i=1;i<n;i++)
    {
        if((arr[i]-arr[lastpos])>=dist)
        {
            lastpos=i;
            cowscompleted++;
            if(cowscompleted>=c)
                return true;
        }
    }
    return false;
}

void binarysearch(ll int arr[],ll int n,ll int c)
{
    ll int start=arr[0],end=arr[n-1]-arr[0],mid;
    
    while(end>=start)
    {
        mid=(start+end)/2;
        if(ispossible(arr,n,mid,c))
            start=mid+1;
        else
            end=mid-1;
    }
    cout<<start-1<<endl;
}

int main() {
    ll int t;
    cin>>t;
    while(t--)
    {
        ll int n,c,max;
        cin>>n>>c;
        ll int x[n];
        for(ll int i=0;i<n;i++)
            cin>>x[i];
        sort(x,x+n);
        binarysearch(x,n,c);
    }
    return 0;
}
