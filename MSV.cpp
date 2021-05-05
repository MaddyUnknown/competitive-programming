#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<int, int> prev, next;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(next.find(a[i])==next.end())
                next[a[i]] = 1;
            else
                next[a[i]] += 1;
        }
        int max_element = -1, max_ans = 0;
        for(int i=0; i<n; i++)
        {
            max_element = (max_element<a[i])?a[i]:max_element;
            if(prev.find(a[i])==prev.end())
                prev[a[i]] = 1;
            else
                prev[a[i]] += 1;
            auto prev_point = prev.find(a[i]);
            auto next_point = next.find(a[i]);
            if(prev_point->second == next_point->second)
            {
                int temp=0;
                for(int num = a[i]; num<=max_element; num+=a[i])
                {
                    auto pointer= prev.find(num);
                    if(pointer!=prev.end())
                        temp += pointer->second;
                }
                max_ans = (max_ans<(temp-1))?(temp-1):max_ans;
            }
        }
        cout<<max_ans<<"\n";
    }
    return 0;
}