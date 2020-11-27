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
              string s;
              cin>>s;
              int n=s.length();
              int x;
              cin>>x;
              string ans(n,'?');
              bool flag=false;
              for(int i=0;i<n;i++)
              {
                     if(i-x<0)
                     {
                            if(s[i]=='1')
                            {
                                   if(i+x<n && ans[i+x]=='0')
                                          flag=true;
                                   if(i+x<n)
                                          ans[i+x]='1';
                            }
                            else
                            {
                                   if(i+x<n && ans[i+x]=='1')
                                          flag=true;
                                   if(i+x<n)
                                          ans[i+x]='0';
                            }
                            
                     }
                     else if(i+x>=n)
                     {
                            if(s[i]=='1')
                            {
                                   if(i-x>=0 && ans[i-x]=='0')
                                          flag=true;
                                   if(i-x>=0)
                                          ans[i-x]='1';
                            }
                            else
                            {
                                   if(i-x>=0 && ans[i-x]=='1')
                                          flag=true;
                                   if(i-x>=0)
                                          ans[i-x]='0';
                            }
                            
                     }
                     else if(i+x<n && i-x>=0)
                     {
                            if(s[i]=='1')
                            {
                                   if(ans[i-x]=='?' && ans[i+x]=='?')
                                          ans[i-x]='1';
                                   else if(ans[i-x]=='0' && ans[i+x]=='0')
                                          flag=true;
                            }
                            else if(s[i]==0)
                            {
                                   if(ans[i-x]=='1' || ans[i+x]=='1')
                                          flag=true;
                                   if(ans[i-x]=='?')
                                          ans[i-x]='0';
                                   if(ans[i+x]=='?')
                                          ans[i+x]='0';
                                   
                            }
                     }
                     
              }
              for(int i=0;i<ans.length();i++)
              {
                     if(ans[i]=='?')
                            ans[i]='0';
              }
              if(flag)
                     cout<<"-1\n";
              else
              {
                     cout<<ans<<endl;
              }
              
       }
       return 0;
}