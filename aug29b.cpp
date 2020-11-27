#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int FindSubarray(vector<int> &v,int k)
{
       vector<int> PrefixSum(v.size(),0);
       PrefixSum[0]=v[0];
       map<int,int> mp;
       mp[0]++;
       // for(int i=1;i<v.size();i++)
       // {
       //        PrefixSum[i]=PrefixSum[i-1]+v[i];
       // }
       int sum=0;
       for(int i=0;i<v.size();i++)
       {
              sum+=v[i];
              sum=(sum%k+k)%k;
              //PrefixSum[i]=((PrefixSum[i]%k)+k)%k;
              //mp[PrefixSum[i]]++;
              mp[sum]++;
       }
       int ans=0;
       for(auto x:mp)
       {
              if(x.second>=2)
              {
                     int m=x.second;
                     ans+=(m*(m-1))/2;
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
       vector<int> v{1,5,17,1};
       int k=4;
       cout<<FindSubarray(v,k);
       return 0;
}