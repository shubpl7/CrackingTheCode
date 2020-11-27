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
const int N = 10005;
int n;
int seive()//finding the no of prime factors
{
       int Primefactors[N]={0};
       SETI Pfs[N];
       for(int i=2;i<=n;i++)
       {
              if(Primefactors[i]==0)
              {
                     for(int j=i;j<=n+1;j+=i)
                     {
                            Primefactors[j]++;
                            Pfs[j].insert(i);
                     }
              }
       }
       for(int i=2;i<=1000;i++)
       {
              cout<<"Prime factors of "<<i<<" are : ";
              for(auto x:Pfs[i])
                     cout<<x<<" ";
              
              cout<<endl;
       }
       int cnt=0;
       for(int i=1;i<=n;i++)
       {
              if(Primefactors[i]==2)
                     cnt++;
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