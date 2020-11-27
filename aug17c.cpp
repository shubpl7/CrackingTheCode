#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> hor,ver;
int vcuts=0,hcuts=0,filled=0;
int solve(int n,int i,int j)
{
       if(ver[j]==0)
       {
              ver[j]=1;
              filled+=(n-hcuts);
              vcuts++;
       }
       if(hor[i]==0)
       {
              hor[i]=1;
              filled+=(n-vcuts);
              hcuts++;
       }
       return n*n-filled;
}
//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,k;
       cin>>n>>k;
       hor.resize(n+1,0);
       ver.resize(n+1,0);
       while(k--)
       {
              int i,j;
              cin>>i>>j;
              cout<<solve(n,i,j)<<" ";

       }
       return 0;
}