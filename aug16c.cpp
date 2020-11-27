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
#define SIZE 200007
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
VI sp(SIZE);
pair<int,int> maxi(int low,int high)
{
       auto it = max_element(sp.begin()+low,sp.begin()+high+1);
       //cout<<"nope ";
       return {(it-sp.begin()),*it};
}
int solve(int ToWhat, int low, int high)
{
       if(low>high)
              return 0;
       //int result=0;
       auto it = maxi(low,high);
       //result+=ToWhat-it.second;
       //cout<<"hi "<<it.first<<"->"<<it.second<<"   ";
       return (ToWhat-it.second)+(solve(it.second,low,it.first-1)+solve(it.second,it.first+1,high));

}
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
              sp.resize(n);
              for(auto &x:sp)
                     cin>>x;
              int max_value=sp[0];
              int low=0,high=0,ans=0;
              for(int i=0;i<n;i++)
              {
                     if(sp[i]>max_value)
                     {
                            high=i-1;
                            ans+=solve(max_value,low,high);
                            low=i+1;
                            max_value=sp[i];
                     }
              }
              if(high<=low)
              {
                     ans+=solve(max_value,low,n-1);
              }
              cout<<ans<<endl;
              sp.clear();
       }
       return 0;
}