#include<bits/stdc++.h>
#define int long long
using namespace std;

int BFS(int x)
{
       //int k=0;
       queue<pair<int,int>> q;
       q.push({0,0});
       unordered_map<int,int> vis;
       vis[0]=1;
       while(!q.empty())
       {
              auto u = q.front();
              q.pop();
              cout<<u.first<<"    "<<u.second<<endl;
              if(u.first==x)
              {
                     return u.second;
              }
              int k=u.second;
              if(vis.find(u.first+k+1)==vis.end())
              {
                     vis[u.first+k+1]=1;
                     q.push({u.first+k+1,k+1});
              }
              if(vis.find(u.first-1)==vis.end())
              {
                     vis[u.first-1]=1;
                     q.push({u.first-1,k+1});
              }
       }
       return -1;
}

//Cracking the Code
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
              int x;
              cin>>x;
              cout<<BFS(x)<<endl;
       }
       return 0;
}