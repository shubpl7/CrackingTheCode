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
int32_t main()
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
              VI unloc;
              VI a(n);
              for(auto &x:a)
                     cin>>x;
              VI stat(n);
              for(auto &x:stat)
                     cin>>x;
              for(int i=0;i<n;i++)
              {
                     if(stat[i]==0)
                            unloc.PB(a[i]);
              }
              sort(unloc.begin(),unloc.end(),greater<int>());
              int k=0;
              for(int i=0;i<n;i++)
              {
                     if(stat[i]==0)
                     {
                            a[i]=unloc[k++];
                     }
                     cout<<a[i]<<" ";
              }
              cout<<endl;
       }
       return 0;
}