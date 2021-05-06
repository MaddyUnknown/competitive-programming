#include <bits/stdc++.h>
#define N 2147483647
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n, q;
	    cin>>n>>q;
	    vector<int> arr(n,0);
	    vector<int> segment(n+1);
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    segment[0] = 0;
	    for(int i=0; i<n; i++)
	    {
	        segment[i+1] = segment[i]^arr[i];
	    }
	    int l,r, ans;
	    for(int i=0; i<q; i++)
	    {
	        cin>>l>>r;
	        ans = segment[r]^segment[l-1];
	        ans = ~ans;
	        ans = ans&N;
	        cout<<ans<<"\n";
	    }
	}
	return 0;
}
