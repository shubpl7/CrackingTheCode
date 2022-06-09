// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> adj[31];
    int size = 31;
    vector<int> dis;
    void addEdge(int i,int j) {
        adj[i].push_back(j);
    }
    int bfs(int src) {
        //vector<int> vis(31,0);
        //vis[src]=1;
        dis[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            if(u==30)
            {
                return dis[u];
            }
            q.pop();
            for(auto v: adj[u]) {
                if(dis[v]>dis[u]+1) {
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        
        
    }
    int minThrow(int N, int arr[]){
        // code here
        vector<int> move(31,-1);
        for(int i=0;i<2*N;i+=2) {
            move[arr[i]]=arr[i+1];
        }
        dis.resize(31,INT_MAX);
        for(int i=1;i<=30;i++) {
            for(int dice=0;dice<=6;dice++) {
                int j = i+dice;
                if(move[j]!=-1)
                    j = move[j];
                if(j<=30)
                    addEdge(i,j);
            }
        }
        return bfs(1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends