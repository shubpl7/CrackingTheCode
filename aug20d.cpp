//https://codeforces.com/problemset/problem/912/B
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
int FindIndex(int n)
{
       int cnt=0;
       while(n)
       {
              n>>=1;
              cnt++;
       }
       return cnt-1;
}
//Cracking the Code
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,k;
       cin>>n>>k;
       if(k==1)
              cout<<n;
       else
       {
              int p= FindIndex(n);
              cout<<(1LL<<(p+1))-1;
       }
       
       return 0;
}