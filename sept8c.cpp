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

void toh(int n,char source,char Auxilliary,char destination)
{
       cout<<"toh->"<<n<<" "<<source<<" "<<Auxilliary<<" "<<destination<<endl;
       if(n==0)
              return;
       toh(n-1,source,destination,Auxilliary);
       cout<<"Move disk "<<n<<" from tower "<<source<<" to tower "<<destination<<endl;
       toh(n-1,Auxilliary,source,destination);
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
       toh(n,'A','C','B');
       return 0;
}