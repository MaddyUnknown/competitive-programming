#include<bits/stdc++.h>
#define N 1000007


using namespace std;

int lp[N];
unordered_set<int> prime_set;
vector<int> prime;


vector<int> fill()
{
    vector<int> prime;
    for(int i=2; i<=N; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.push_back(i);
            prime_set.insert(i);
        }
        for(int j = 0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=N; j++)
        {
            lp[i*prime[j]] = prime[j];
        }
    }
    return prime;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL);
    cout.tie(NULL); 
	memset(lp, 0, sizeof(lp));
    int t;
    cin>>t;
    prime = fill();
    while(t--)
    {
        int n;
        cin>>n;
	/* All even number greater than 2 can be expressed as sum of 2 prime numbers
	   All whole number greater than 3 can be expressed as sum of 3 prime numbers
	   All odd whole number greater than 3 can be expressed as sum of 2 prime if one prime is 2
	*/
        if(n==1 || n==2 || n==3)
        {
            cout<<"-1\n";
        }
        else if(n%2==0 && n>3)
        {
            cout<<"1\n";
        }
        else if(n%2==1 && prime_set.find(n-2)!=prime_set.end())
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"2\n";
        }
        //print(n);
    }
    
	return 0;
}
