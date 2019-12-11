#include <bits/stdc++.h> 
using namespace std; 

// In optimised sieve we don't care about the even integers

void optimisedSieve(int n) 
{ 
	bool prime[n/2]; 
	memset(prime, false, sizeof(prime)); 

	// 2 is the only even prime so we can ignore that. Loop starts from 3. 
	for(int i = 3 ; i*i < n; i += 2) 
	{ 
		// If i is prime, mark all its multiples as composite 
		if (prime[i/2] == false) 
			for(int j = i*i;j < n;j += i*2) 
				prime[j/2] = true; 
	} 

	// writing 2 separately 
	std :: cout << 2 << std :: endl; 
    long long int n1 = 1;
	// Printing other primes 
	for(int i = 3; i < n ; i += 2) 
		if (prime[i/2] == false) 
		{
            n1++;
            if(n1 % 100 == 1)
            std :: cout << i << std :: endl;
        } 
} 

int main() 
{ 
	int n = 100000000; 
	optimisedSieve(n); 
	return 0; 
} 
