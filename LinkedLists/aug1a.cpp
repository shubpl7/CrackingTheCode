#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<int,string> > juice(n);
    for(int i=0;i<n;i++)
    {
        cin>>juice[i].first>>juice[i].second;
    }
    int ans = 9e9+7;
    int flag=0;
    for(int i=1;i< (1<<n); i++)
    {
        VI v;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                v.PB(j);
        }
        map<char,int> mp;
        int cost=0;
        for(auto x:v)
        {
            for(auto y: juice[x].second)
                mp[y]++;
            cost+= juice[x].first;
        }
        if(mp['A']>0 && mp['B']>0 && mp['C']>0)
        {
            flag = 1;
            ans = min(ans, cost);
        }
            
    }
    if(!flag)
        cout<<"-1";
    else
        cout<<ans;
    return 0;
}