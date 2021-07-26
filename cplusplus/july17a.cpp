#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

int HighestSetBit(int n)
{
    int i=0;
    while ((1<<i)<=n)
    {
        i++;
    }
    return i-1;
    
}

int CalPairs(vector<int> &a)
{
    int freq[65]={0};
    for(int i=0;i<a.size();i++)
    {
        int hsb = HighestSetBit(a[i]);
        freq[hsb]++;
    }
    int ans = 0;
    for(int i=0;i<65;i++)
    {
        ans+=((freq[i]*(freq[i]-1))/2);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    priority_queue<int,VI> pq;
    while(t--)
    {
        int n;
        cin>>n;
        VI a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<CalPairs(a)<<endl;
        
    }
    
    return 0;
}