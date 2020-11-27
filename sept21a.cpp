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

map<int,int> seive(int n)
{
       map<int,int> ans;
       ans[2]=0;
       ans[3]=0;
       ans[5]=0;
       for(int i=2;i<=sqrt(n);i++)
       {
              int cnt=0;
              if(n%i==0)
              {
                     while(n%i==0)
                     {
                            n/=i;
                            cnt++;
                     }
                     ans[i]=cnt;
              }
       }
       if(n!=1)
              ans[n]=1;
       return ans;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int a,b;
       cin>>a>>b;
       auto F = seive(a);
       auto S = seive(b);
       if(F.size()!=S.size())
       {
              cout<<"-1";
              return 0;
       }
       
       int flag=0;
       int n=F.size();
       int ans=0;
       auto it1=F.begin();
       auto it2=S.begin();
       for(;it1!=F.end() && it2!=S.end();it1++,it2++)
       {
              if(it1->fi==it2->fi)
              {
                     if(it1->fi==2 || it1->fi==3 || it1->fi==5)
                     {
                            ans+=abs(it1->se - it2->se);
                     }
                     else
                     {
                            if(it1->se != it2->se)
                            {
                                   flag=1;
                                   break;
                            }
                     }
              }
              else
              {
                     flag=1;
                     break;
              }
              
       }
       if(flag)
              cout<<"-1";
       else
              cout<<ans;
       
       return 0;
}