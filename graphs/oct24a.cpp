#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int getCommonStrings(string x, string y)
{
    int i=0,j=0;
    while(i<x.length() && j<y.length())
    {
        if(x[i]==y[j])
        {
            i++;
            j++;
        }
        else
        break;
    }
    return i;
}

int sumQueries(vector<string> arr, vector<string> queries)
{
    int ans=0;
    for(auto x: queries)
    {
        for(auto y:arr)
        {
            ans+=getCommonStrings(x,y);
        }
    }
    return ans;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("../input.txt","r",stdin);
    // freopen("../output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int q;
    cin>>q;
    vector<string> qu(q);
    for(int i=0;i<q;i++)
        cin>>qu[i];

    cout<<sumQueries(arr,qu);
    return 0;
}