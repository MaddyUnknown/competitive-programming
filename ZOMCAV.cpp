#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{
    return a>b;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
    {
        int n; 
        cin>>n;
        int a;
        vector<int> radiation(n+1,0);
        priority_queue<int> h;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            int low=(((i-a)>0)?(i-a):0); 
            int up=(((i+a)>n-1)?(n-1):(i+a));
            radiation[low] += 1;
            radiation[up+1] -= 1;
        }
        for(int i=1; i<n; i++)
        {
            radiation[i] += radiation[i-1];
            
        }
        /*for(int i=0; i<n; i++)
            cout<<radiation[i]<<" ";
        cout<<"\n";
        */
        
        for(int i=0; i<n; i++)
        {
            cin>>a;
            h.push(a);
        }
        sort(radiation.begin(), radiation.end(), comp);
        bool no_solution = false;
        for(int i=0; i<n; i++)
        {
            int top = h.top();
            h.pop();
            if(top!=radiation[i])
            {
                no_solution = true;
                break;
            }
        }
        if(!no_solution)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}
