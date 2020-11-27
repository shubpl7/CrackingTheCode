#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> solve(vector<pair<int,int>> &queries)
{
       vector<map<int,int>> v;
       v.push_back({0,1});
       for(auto x:queries)
       {
              if(x.first==0)
              {
                     map<int,int> mp;
                     mp[x.second]=1;
                     v.push_back(mp);
              }
              else
              {
                     for(auto y:v)
                     {
                            y[x.second]++;
                     }
              }
              
       }
       vector<int> output;
       for(auto x:v)
       {
              int ans=0;
              for(auto z:x)
              {
                     if(z.second%2==0)
                            continue;
                     else
                     {
                            ans^=(z.first);
                     }
                     
              }
              output.push_back(ans);
       }
       sort(output.begin(),output.end());
       return output;
}
//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              int q;
              cin>>q;
              vector<pair<int,int>> queries(q);
              for(int i=0;i<q;i++)
              {
                     int x,y;
                     cin>>x>>y;
                     queries.push_back({x,y});
              }
              auto it=solve(queries);
              for(auto x:it)
                     cout<<x<<" ";
       }
       return 0;
}