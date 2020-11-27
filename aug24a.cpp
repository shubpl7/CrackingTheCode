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
              string s;
              cin>>s;
              unordered_map<int,bool> mp;
              vector<string> sub(n);
              for(int i=0;i<n;i++)
              {
                     string temp=s.substr(i,n);
                     sub[i]=temp;
                     mp[i]=false;
              }
              string ans(n,'0');
              for(int i=0;i<n;i++)
              {
                     vector<int> zeros,ones;
                     for(int j=0;j<n;j++)
                     {
                            if(sub[j][i]=='0' && mp[j]==false)
                                   zeros.push_back(j);
                            else if(sub[j][i]=='1' && mp[j]==false)
                                   ones.push_back(j);

                     }
                     if(zeros.size()==0)
                     {
                            ans[i]='1';
                            //flag=1;
                            break;
                     }
                     else if(ones.size()==0)
                     {
                            ans[i]='0';
                            break;
                     }
                     else
                     {
                            if(zeros.size()>=ones.size())
                            {
                                   ans[i]='0';
                                   for(auto x:zeros)
                                   {
                                          mp[x]=true;
                                   }
                            }
                            else
                            {
                                   ans[i]='1';
                                   for(auto x:ones)
                                   {
                                          mp[x]=true;
                                   }
                            }
                            
                     }
                     zeros.clear();
                     ones.clear();
                     
              }
              cout<<ans<<endl;
       }
       return 0;
}