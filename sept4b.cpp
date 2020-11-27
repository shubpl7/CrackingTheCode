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
              int n,x,y;
              cin>>n>>x>>y;
              int alpha=n-2;
              int rem=n-2;
              int terms,addition;
              for(;alpha>=0;alpha--)
              {
                     if((y-x)%(alpha+1)==0)
                     {
                            terms=alpha;
                            addition=(y-x)/(alpha+1);
                            rem-=terms;
                            break;
                     }
              }
              if((x-1)/addition>=rem)
              {
                     int a=y-(n-1)*addition;
                     for(int i=0;i<n;i++)
                            cout<<a+i*addition<<" ";
                     cout<<endl;
              }
              else
              {
                     rem-=(x-1)/addition;
                     int last=y+rem*addition;
                     int a=last-(n-1)*addition;
                     for(int i=0;i<n;i++)
                            cout<<a+i*addition<<" ";
                     cout<<endl;
              }
              
       }

       return 0;
}