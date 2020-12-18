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
int n,m;
VI A,B;
int memo[100][100][5];
int LCS(int i,int j,int k)
{
       cout<<"LCS-->"<<i<<" "<<j<<" "<<k<<endl;
       if(memo[i][j][k]!=-1)
              return memo[i][j][k];
       if(i>n || j>m)
       {
              memo[i][j][k]=0;
              return 0;
       }
       if(A[i]==B[j])
       {
              int opt= 1+LCS(i+1,j+1,k);
              memo[i][j][k]=opt;
              return opt;
       }
       else
       {
              int opt1=-1;
              if(k>0)
                    opt1=1+LCS(i+1,j+1,k-1);
              int opt2=max(LCS(i+1,j,k),LCS(i,j+1,k));
              memo[i][j][k]=max(opt1,opt2);
              return max(opt1,opt2);
       }
       
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int k;
       cin>>n>>m>>k;
       A.resize(n+1);B.resize(m+1);
       for(int i=1;i<=n;i++)
              cin>>A[i];
       for(int i=1;i<=m;i++)
              cin>>B[i];
       memset(memo,-1,sizeof(memo));
       cout<<LCS(1,1,k);
       return 0;
}