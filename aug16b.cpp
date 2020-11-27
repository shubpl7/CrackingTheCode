#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int long long 
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
       int t;
       cin>>t;
       while (t--)
       {
              /* code */
              int n,k;
              cin>>n>>k;
              VI v(n);
              for(auto &x:v)
                     cin>>x;
              int maxi= *max_element(v.begin(),v.end());
              VI v1(n),v2(n);
              for(int i=0;i<n;i++)
              {
                     v1[i]=maxi-v[i];
              }
              int maxi2= *max_element(v1.begin(),v1.end());
              for(int i=0;i<n;i++)
              {
                     v2[i]=maxi2-v1[i];
              }
              if(k%2==0)
              {
                     for(auto x:v2)
                            cout<<x<<" ";
              }
              else
              {
                     for(auto x:v1)
                            cout<<x<<" ";
              }
              cout<<endl;
              
       }
       
       return 0;
}