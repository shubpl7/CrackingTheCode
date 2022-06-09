#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
struct Node{
    int val;
    Node * left, * right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

class Btree{
    public:
        Node * root;
        Btree(){
            root = NULL;
        }
        void createTree();
        void preOrder(Node *);
        int longestAp(Node *);
};

vector<pair<int, int>> DFS(Node * curr, Node *par, int &ans) {
    if(!curr){
        return {};
    }
    vector<pair<int, int>> res;
    bool flag = false;

    if(!curr->left && !curr->right) {
        ans = max(ans, 1LL);
        vector<pair<int, int>> temp;
        temp.push_back({curr->val-par->val,1});
        return temp;
    }

    int inc = 0, dec = 0;
    vector<pair<int, int>> temp;
    if(curr->left) {
        auto left = DFS(curr->left, curr, ans);
        int curr_cd = curr->left->val - curr->val;
        for(auto x: left) {
            if(x.first == curr_cd) {
                inc = max(inc, 1+x.second);
                temp.push_back({inc, curr_cd});
            }
        }

    }

    if(curr->right) {
        auto right = DFS(curr->right, curr, ans);
        int curr_cd = curr->right->val - curr->val;
        for(auto x: right) {
            if(x.first == curr_cd) {
                dec = max(dec, 1+x.second);
                temp.push_back({dec, curr_cd});
            }
            
        }
    }
    ans = max(ans, inc+dec-1);
    return temp;
}
int Btree::longestAp(Node * curr) {
    int ans = 0;
    DFS(curr, NULL, ans);
    return ans;
}

void Btree::preOrder(Node * curr){
    if(curr) {
        preOrder(curr->left);
        cout<<curr->val;
        preOrder(curr->right);
    }
}
void Btree::createTree() {
    
    queue<Node*> q;
    int a;
    cin>>a;
    root = new Node(a);
    q.push(root);
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        cout<<"Enter left child of : "<<curr->val<<endl;
        int a;
        cin>>a;
        if(a!=-1){
            curr->left = new Node(a);
            q.push(curr->left);
        }
        cout<<"Enter right child of : "<<curr->val<<endl;
        int b;
        cin>>b;
        if(b!=-1){
            curr->right = new Node(b);
            q.push(curr->right);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //freopen("../../input.txt","r",stdin);
    //freopen("../../output.txt","w",stdout);
    #endif
    Btree t;
    t.createTree();
    t.preOrder(t.root);
    return 0;
}