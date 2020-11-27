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
int FindSetBits(int n)
{
       int cnt=0;
       while(n)
       {
              n=n&(n-1);
              cnt++;
       }
       return cnt;
       //return __builtin_popcount(n);
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,p;
       cin>>n>>p;
       for(int k=1;k<=30;k++)
       {
              int temp=n-k*p;
              if(temp<0)
                     continue;
              int set_bits= FindSetBits(temp);
              //cout<<temp<<" "<<set_bits<<" "<<k<<endl;
              if(set_bits<=k && temp>=k)
              {
                     cout<<k;
                     return 0;
              }
       }   
       cout<<"-1";    
       return 0;
}