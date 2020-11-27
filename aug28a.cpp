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
              int n,k;
              cin>>n>>k;
              string s;
              cin>>s;
              sort(s.begin(),s.end());
              set<char> st;
              int i=0;
              while(i<k)
              {
                     st.insert(s[i]);
                     i++;
              }
              if(i==n)
                     cout<<s[n-1]<<endl;
              else
              {
                     
                     if(st.size()==1)
                     {
                            string s1=s.substr(i,n-k);
                            string app="";
                            map<char,int> mp;
                            for(int i=k;i<n;i++)
                                   mp[s[i]]++;
                            if(mp.size()==1)
                            {
                                   int x=(n-k+k-1)/k;
                                   char ch=mp[s[i]];
                                   string app1(x,ch);
                                   app=app1;

                            }
                            else
                                   app=s1;
                            string ans=s[i-1]+app;
                            cout<<ans<<endl;
                     }
                     else
                            cout<<s[i-1]<<endl;
              }
              

       }
       return 0;
}