#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool canAchieve(string s,string t,int k)
{
       int n=s.length();
       map<int,int> mp;
       map<char,int> mp1;
       int i=1;
       for(char ch='a';ch<='z';ch++,i++)
       {
              mp1[ch]=i;
       }
       for(int i=1;i<=k;i++)
       {
              mp[i]=1;
       }
       bool flag=true;
       for(int i=0;i<n;i++)
       {
              int diff;
              if(mp1[s[i]]<mp1[t[i]])
              {
                     diff=mp1[t[i]]-mp1[s[i]];
              }
              else
              {
                     diff=26-(mp1[s[i]]-mp1[t[i]]);
              }
              auto it=mp.find(diff);
              if(it!=mp.end())
              {
                     if(it->second==1)
                     {
                            it->second=0;
                     }
                     else
                            flag=false;
              }
              else
              {
                     flag=false;
              }
              
              
              
       }
       return flag;
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
       string s="abc",t="ddd";
       int k=3;
       if(canAchieve(s,t,k))
              cout<<"Yes\n";
       else
              cout<<"No\n";
       return 0;
}