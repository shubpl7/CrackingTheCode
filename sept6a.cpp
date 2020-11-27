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
bool check(VI &ans, VI & per)
{
       for(int i=1;i<per.size();i++)
       {
              if(ans[i]!=per[i])
                     return true;
       }
       return false;
}
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
              VI per(n+1);
              for(int i=1;i<=n;i++)
              {
                     int a;
                     cin>>a;
                     per[i]=a;
              }
              VI ans(n+1);
              
              for(int i=1;i<=n;i++)
              {
                     int flag=0;
                     ans.clear();
                     vector<bool> vis(n+1,false);
                     vis[0]=true;
                     ans[1]=i;
                     vis[i]=true;
                     cout<<"value of i is : "<<i<<endl;
                     for(int j=1;j<n;j++)
                     {
                            int a =per[j]+per[j+1]-ans[j];
                            cout<<"# "<<a<<endl;
                            if(a<=0 || a>n || vis[a]==true)
                            {
                                   flag=1;
                                   break;
                            }
                            else
                            {
                                   vis[a]=true;
                                   ans[j+1]=a;
                            }
                            

                     }
                     if(flag==1)
                            continue;
                     else
                     {
                            bool ch = check(ans,per);
                            if(ch==true)
                            {
                                   for(int i=1;i<=n;i++)
                                          cout<<ans[i]<<" ";
                                   break;
                            }
                     }      
              }
              cout<<endl;

       }
       return 0;
}