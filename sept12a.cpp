#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
int x;
int ans=INT64_MAX;
PII anspair={1,1};
VPII fact;
void solve()
{
       int temp=x;
       for(int i=2;i*i<=x;i++)
       {
              int count=0;
              if(x%i==0)
              {

                     while(x%i==0)
                     {
                            x/=i;
                            count++;
                     }
                     fact.PB({i,count});
              }
       }
       if(x!=1)
              fact.PB({x,1});
       x=temp;
       fact.PB({1,1});
       int t=fact.size();
       for(int i=1;i<(1<<t);i++)
       {
              int a=1,b=1;
              for(int j=0;j<=t-1;j++)
              {
                     if(i&(1<<j))
                     {
                            a*=(int)pow(fact[t-j-1].fi,fact[t-j-1].se);
                     }
              }
              b=x/a;
              if(max(a,b)<ans)
              {
                     ans=max(a,b);
                     anspair={a,b};
              }
              //cout<<a<<" "<<b<<" "<<" and ans pair is : "<<anspair.fi<<" "<<anspair.se<<endl;
       }

}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       
       cin>>x;
       solve();
       int a=max(anspair.first,anspair.second);
       int b=min(anspair.first,anspair.second);
       cout<<a<<" "<<b;
       return 0;
}