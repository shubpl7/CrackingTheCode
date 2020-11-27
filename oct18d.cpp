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
       int ti=0;
       while(t--)
       {
              ti++;
              string s;
              cin>>s;
              int n=s.size();
              VI ans;
              for(int i=0;i<=n-5;)
              {
                     if(s.substr(i,4)=="KICK")
                     {
                            ans.PB(0);
                            i+=3;
                     }
                     else if(s.substr(i,5)=="START")
                     {
                            ans.PB(1);
                            i+=5;
                     }
                     else
                            i++;
              }
              // for(auto x:ans)
              //        cout<<x<<" ";
              // cout<<endl;
              int k=ans.size();
              int cnt[k+1]={0};
              cnt[k]=0;
              for(int i=k-1;i>=0;i--)
              {
                     cnt[i]=ans[i]+cnt[i+1];
              }
              // for(int i=0;i<k;i++)
              // {
              //        cout<<cnt[i]<<" ";
              // }
              // cout<<endl;
              int total=0;
              for(int i=0;i<k;i++)
              {
                     if(ans[i]==0)
                     {
                            total+=cnt[i];
                     }
              }
              cout<<"Case #"<<ti<<": "<<total<<endl;
       }
       return 0;
}