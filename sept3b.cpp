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
int n;
int seive()
{
       vector<SETI> v(n+1);
       VI primes;
       for(int i=2;i<=n;i++)
       {
              if(v[i].size()==0)
              {
                     primes.PB(i);
                     for(int j=i;j<=n;j+=i)
                     {
                            v[j].insert(i);
                     }
              }
       }
       int cnt=0;
       for(int i=2;i<=n;i++)
       {
              if(v[i].size()==2)
                     cnt++;
              // cout<<"Prime factors of "<<i<<" are: ";
              // for(auto x:v[i])
              // {
              //        cout<<x<<" ";
              // }
              // cout<<endl;
       }
       return cnt;

}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n;
       cout<<seive();
       return 0;
}