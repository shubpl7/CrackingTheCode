#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


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
       string s;
       cin>>s;
       unordered_map<string,int> mp;
       for(int i=0;i<n-1;i++)
       {
              string key=s.substr(i,2);
              mp[key]++;

       }
       string ans;
       int maxi=0;
       for(auto x:mp)
       {
              if(x.second>maxi)
              {
                     maxi=x.second;
                     ans=x.first;
              }
       }
       cout<<ans;
       return 0;
}