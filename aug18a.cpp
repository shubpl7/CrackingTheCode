#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool mycomp(pair<int,pair<int,string>> &p1,pair<int,pair<int,string>> &p2)
{
       if(p1.first>p2.first)
              return true;
       else if(p1.first==p2.first)
       {
              if(p1.second.first<p2.second.first)
                     return true;
              else if(p1.second.first>p2.second.first)
                     return false;
              else
              {
                     return p1.second.second<p2.second.second;
              }
              
       }
       else
              return false;
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
       int n;
       cin>>n;
       string name;
       int time;
       map<string,pair<int,int>> mp;
       for(int i=0;i<n;i++)
       {
              cin>>name>>time;
              mp[name].first++;
              mp[name].second+=time;
       }
       vector<pair<int,pair<int,string>>> v;
       for(auto x:mp)
       {
              v.push_back({x.second.first,{x.second.second,x.first}});
       }
       sort(v.begin(),v.end(),mycomp);
       int i=1;
       for(auto x:v)
       {
              cout<<i<<" "<<x.second.second<<endl;
              i++;
       }
       return 0;
}