#include<bits/stdc++.h>
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
string func(int k)
{
       string ans="";
       while(k)
       {
              int digit = k%10;
              ans+=('0'+digit);
              k/=10;
       }
       reverse(ans.begin(),ans.end());
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
       int k;
       string str;
       cin>>k;
       bool flag=false;
       if(k<0)
              flag=true;
       if(!flag)
       {
              str=func(k);
              sort(str.begin(),str.end());
              if(str[0]=='0')
              {
                     int j=-1;
                     for(int i=1;i<str.length();i++)
                     {
                            if(str[i]!='0')
                            {
                                   j=i;
                                   break;
                            }
                     }
                     if(j!=-1)
                            swap(str[0],str[j]);
              }
              cout<<str;
       }      
       else
       {
              k=abs(k);
              str=func(k);
              sort(str.begin(),str.end(),greater<char>());
              cout<<"-"<<str;
       }       
       return 0;
}