// { Driver Code Starts
// Initial Template for C++

// alien dictionary
/*
Very nice question on topological sorting. Solved using bth the methods DFS and BFS
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void createAdj(string dict[], int N, map<char, vector<char>> &adj, vector<int> &indegree) {
        for(int i=0;i<N-1;i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            for(int i=0;i<s1.length() && i<s2.length();i++) {
                if(s1[i]!=s2[i]) {
                    adj[s1[i]].push_back(s2[i]);
                    indegree[s2[i]-'a']++;
                    break;
                }
            }
        }
        
    }
    // topological sort using DFS
    void dfs(char src, map<char, vector<char>>  &adj, set<char> &vis, string &order) {
        vis.insert(src);
        for(auto x: adj[src]) {
            if(!vis.count(x)) {
                dfs(x, adj, vis, order);
            }
        }
        order = src+order;
    }
    // Topological sort using BFS
    string bfs(vector<int> &indegree, map<char, vector<char>> &adj, int K) {
        queue<char> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push('a'+i);
            }
        }
        string ans="";
        while(!q.empty()) {
            char u = q.front();
            q.pop();
            ans+=u;
            for(auto x: adj[u]) {
                indegree[x-'a']--;
                if(indegree[x-'a']==0)
                    q.push(x);
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        map<char, vector<char>> adj;
        vector<int> indegree(K,0);
        createAdj(dict, N, adj, indegree);
        return bfs(indegree, adj, K);
        // set<char> vis;
        // string order="";
        // for(char ch = 'a';ch<='a'+K;ch++) {
        //     if(!vis.count(ch)) {
        //         dfs(ch, adj, vis, order);
        //     }
        // }
        // return order;
    }
};













// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends