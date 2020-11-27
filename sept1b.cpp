#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(vector<int> &v)
{
       map<int,vector<int>> mp;
       int sum=0;
       mp[0].push_back(-1);
       // vector<int> Psum(v.size(),0);
       // Psum[0]=v[0];
       // for(int i=1;i<v.size();i++)
       // {
       //        Psum[i]=Psum[i-1]+v[i];
       // }
       // int n=v.size();
       // for(int i=0;i<v.size();i++)
       // {
       //        Psum[i]=Psum[i]%n;
       //        mp[Psum[i]].push_back(i);
       // }
       int n=v.size();
       //int sum=0;
       for(int i=0;i<n;i++)
       {
              sum+=v[i];
              sum=sum%n;
              mp[sum].push_back(i);
       }
       for(auto x:mp)
       {
              if(x.second.size()>=2)
              {
                     int l=x.second[0]+1;
                     int r=x.second[1];
                     cout<<r-l+1<<endl;
                     for(int j=l;j<=r;j++)
                            cout<<j+1<<" ";
                     break;
              }
       }
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
              int n;
              cin>>n;
              vector<int> v(n);
              for(auto &x:v)
                     cin>>x;
              solve(v);
              cout<<endl;
       }
       return 0;
}