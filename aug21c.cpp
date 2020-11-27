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
       vector<int> v{5,4,2,4,7,5,4,2,5,2};
       int cnt[32]={0};
       int n=v.size();
       for(int i=0;i<32;i++)
       {
              for(int j=0;j<n;j++)
              {
                     int mask = 1<<i;
                     if(v[j]&mask)
                            cnt[i]++;
              }
       }
       int ans=0;
       int p=1;
       for(int i=0;i<32;i++)
       {
              cnt[i]=cnt[i]%3;
              ans+=(cnt[i]*p);
              p<<=1;
       }
       cout<<ans;
       return 0;
}