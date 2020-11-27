#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int unsigned long long 
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
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
       int n,i,j,k,sum,l;
       cin>>n;
       if(n>=130){
              cout<<"Yes";
              return 0;
       }
       else
       {
              int a[130];
              for(int i=0;i<n;i++)
                     cin>>a[i];
              for(i=0;i<n-3;i++)
              {
                     for(j=i+1;j<n-2;j++)
                     {
                            for(k=j+1;k<n-1;k++)
                            {
                                   sum=a[i]^a[j]^a[k];
                                   for(l=k+1;l<n;l++)
                                   {
                                          if(sum==a[l])
                                          {
                                                 cout<<"Yes";
                                                 return 0;
                                          }
                                   }
                            }
                     }
              }
       }
       cout<<"No";
       return 0;
}