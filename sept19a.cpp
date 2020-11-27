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
              int x;
              cin>>x;
              int cnt=0;
              int n=1;
              while(x>0)
              {
                     int alpha = (1LL<<n)-1;
                     int cells = (alpha*(alpha+1))/2;
                     //cout<<alpha<<" "<<cells<<" -- "<<x<<endl;
                     if(cells<=x)
                     {
                            cnt++;
                            n++;
                            x-=cells;
                     }
                     else
                            break;
              }
              cout<<cnt<<endl;
       }
       return 0;
}