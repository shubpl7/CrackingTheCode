#include<bits/stdc++.h>
using namespace std;
// #define int long long 
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
       
       int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

       for(int i=0;i<3;i++)
       {
              for(int j=0;j<4;j++)
              {
                     cout<<*(arr+i)+j<<" ";
              }
              cout<<endl;
       }
       cout<<endl;
       int i=1,j=2;
       cout<<arr[i][j]<<endl;

       cout<<*(*(arr+i)+j)<<endl;

       cout<<*(arr[i]+j)<<endl;
       
       return 0;
}