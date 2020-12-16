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
VI a;
VVI memo;
int f(int i,int j)
{
       cout<<"f--"<<i<<" "<<j<<endl;
       if(memo[i][j]!=-1)
              return memo[i][j];
       if(i>j){
              memo[i][j]=0;
              return 0;
       }
       if(j==i+1){
              memo[i][j]=max(a[i],a[j]);
              return max(a[i],a[j]);
       }
       int ans= max(a[i]+min(f(i+2,j),f(i+1,j-1)),a[j]+min(f(i,j-2),f(i+1,j-1)));
       memo[i][j]=ans;
       return ans;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
       a.resize(n+1);
       memo.resize(n+1,VI(n+1,-1));
       for(int i=1;i<=n;i++)
              cin>>a[i];
       cout<<f(1,n);
       return 0;
}