#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair
#define MAX 10000025

lli primes[MAX];
bool prime[MAX],sqr[MAX];

void optimisedSieve() 
{ 
	for(lli i=0;i<MAX;i++)
	{
		sqr[i]=false;
		primes[i]=0;
		prime[i]=false;
	}
	// 2 is the only even prime so we can ignore that. Loop starts from 3. 
	for(lli i = 2 ; i*i <= MAX; i++) 
	{ 
		// If i is prime, mark all its multiples as composite 
		if (prime[i] == false) 
			for(lli j = i*i;j <= MAX;j += i) 
				prime[j] = true; 
	}

	for(lli i=1;i*i<=MAX;i++)
		sqr[i*i]=true;
	primes[2]=1;

	for(lli i = 3; i <= MAX ; i++) 
	{
		primes[i]=primes[i-1];
		if (prime[i] == false) 
		{
			for(lli j=1;j*j*j*j<=i;j++)
			{
				if(sqr[i-j*j*j*j])
				{
					primes[i]++;
					break;
				}
			}
        }
	}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<fixed<<setprecision(10);

lli t=1;
cin>>t;
optimisedSieve();
while(t--)
{
	lli n;
	cin>>n;
	cout<<primes[n]<<endl;
}
return 0;
}