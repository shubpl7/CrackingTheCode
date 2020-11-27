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
int n;
string ans;
void fun(int open,int close,int idx)
{
       cout<<"fuctiona cal->"<<open<<" "<<close<<" "<<idx<<endl;
       if(idx==2*n)
       {
              cout<<ans<<endl;
              return;
       }
       if(open<n)
       {
              ans[idx]='(';
              fun(open+1,close,idx+1);
       }
       if(close<open)
       {
              ans[idx]=')';
              fun(open,close+1,idx+1);
       }
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
       ans.resize(2*n);
       fun(0,0,0);
       return 0;
}