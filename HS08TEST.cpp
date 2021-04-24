#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int amount;
	float balance, cost;
	cin>>amount>>balance;
	if(amount%5==0)
	{
	    cost = float(amount)+0.5;
	    if(cost>balance)
	    {
	        cout<<balance<<setprecision(2)<<endl;
	    }
	    else
	    {
	        cout<<balance-cost<<setprecision(2)<<endl;
	    }
	}
	else
	{
	    cout<<balance<<setprecision(2)<<endl;
	}
	return 0;
}

