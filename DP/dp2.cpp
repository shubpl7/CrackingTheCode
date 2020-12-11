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
int topdown(int *arr)
{
       int memo[n+1][n+1];
       memset(memo,-1,sizeof(memo));

}
int bottomtop()
{

}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       cin>>n;
       int arr[n+1];
       for(int i=1;i<=n;i++)
              cin>>arr[i];
       cout<<topdown(arr);
       return 0;
}