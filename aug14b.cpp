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
bool compare(const string &s1, const string &s2)
{
       if(s1.length()==s2.length())
              return s1<s2;
       else
       {
              return s1.length()<s2.length();
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
       int n=3;
       vector<string> fruits(n);
       for(auto &x:fruits)
              getline(cin,x);
       sort(fruits.begin(),fruits.end(),compare);
       for(auto x:fruits)
              cout<<x<<endl;
       VI v{9,4,2,17,110};
       sort(v.begin(),v.end(),greater<int>());
       priority_queue<int,VI,greater<int>> pq;//min-heap
       return 0;
}