#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 10000007

int FastExponent(int a,int n)
{
       int p=a,ans=1;
       while(n)
       {
              if(n&1LL)
              {
                     ans=((ans%MOD)*(p%MOD))%MOD;
              }
              n>>=1LL;
              p=((p%MOD)*(p%MOD))%MOD;
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
       int a=2,n=30;
       cout<<FastExponent(a,n);
       return 0;
}