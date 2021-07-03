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
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       vector<int> v;
       v.push_back(10);
       v.push_back(11);
       v.push_back(13);
       v.push_back(16);
       v.push_back(20);

       reverse(v.begin(),v.end());
       for(auto x:v)
       {
              cout<<x<<"---#";
       }

       v.erase(v.begin(),v.begin()+3);
       cout<<endl;
       for(auto x:v)
       {
              cout<<x<<"---#";
       }
       return 0;
}