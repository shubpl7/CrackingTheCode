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
bool check(VI &stalls,int n,int c,int ms)
{
       int cnt=1;
       int lastcow=stalls[0];
       for(int i=1;i<n;i++)
       {
              if(stalls[i]-lastcow>=ms)
              {
                     lastcow=stalls[i];
                     cnt++;
              }
              //cout<<ms<<"%% "<<cnt<<endl;
              if(cnt==c)
                     return true;
       }
       return false;
}
int FindAns(VI &stalls,int n,int c)
{
       int s=0,e=stalls[n-1]-stalls[0];
       int ans=0;
       while(s<=e)
       {
              int mid=s+(e-s)/2;
              bool Cows = check(stalls,n,c,mid);
              //cout<<s<<" "<<e<<" "<<mid<<" "<<Cows<<endl;
              if(Cows)
              {
                     ans=mid;
                     s=mid+1;
              }
              else
              {
                     e=mid-1;
              }
              
       }
       return ans;
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
              int n,c;
              cin>>n>>c;
              VI stalls(n);
              for(auto &x:stalls)
                     cin>>x;
              sort(stalls.begin(),stalls.end());
              cout<<FindAns(stalls,n,c)<<endl;
       }
       return 0;
}