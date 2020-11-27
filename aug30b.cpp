#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int FindSubarray(vector<int> &v,int k)
{
       int n=v.size();
       vector<int> Psum(n,0);
       Psum[0]=v[0];
       for(int i=1;i<n;i++){
              Psum[i]=Psum[i-1]+v[i];
       }
       map<int,int> mp;
       mp[0]++;
       for(int i=0;i<n;i++)
       {
              Psum[i]=Psum[i]%k;
              Psum[i]=(Psum[i]+k)%k;
              mp[Psum[i]]++;
       }
       int ans=0;
       for(auto x:mp)
       {
              if(x.second>=2)
              {
                     int y=x.second;
                     ans+=(y*(y-1))/2;
              }
       }
       return ans;
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
       vector<int> v{4,5,0,-2,-3,1};
       int k=5;
       cout<<FindSubarray(v,k);
       return 0;
}