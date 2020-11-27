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
       while(t--)
       {
            int n;
            cin>>n;
            VPII cor(n);
            for(int i=0;i<n;i++)
            {
                     int x,y;
                     cin>>x>>y;
                     cor[i]={x,y};
            }  
            int sum=0;
            int temp=n;
            while(temp>=3)
            {
                   sum+=temp;
                   temp = temp>>1;
            }
            cout<<sum<<endl;

       }
       return 0;
}