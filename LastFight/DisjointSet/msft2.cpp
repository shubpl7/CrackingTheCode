#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
struct Node{
    int val;
    Node * left;
    Node * right;
    Node (int v) {
        val = v;
        left = right = NULL;
    }
};
class BT{
    public:
        Node * root;
        BT(){
            root = NULL;
        }
        int ans=0;
        string ansString="";
        pair<int, string> LongestPath(Node * curr){
            
            if(!curr)
                return make_pair(0,"");
            // if(curr->left==NULL && curr->right == NULL) {
            //     return 1;
            // }
            auto left = LongestPath(curr->left);
            auto right = LongestPath(curr->right);
            int currMax = 1;
            string currMaxString=to_string(curr->val);
            if(curr->left) {
                if(curr->left->val != curr->val) {
                    currMax = left.first +1;
                    currMaxString = to_string(curr->val)+left.second;
                }
            }
            if(curr->right) {
                if(curr->right->val != curr->val) {
                    if(currMax<right.first+1) {
                        currMax = right.first+1;
                        currMaxString = to_string(curr->val)+right.second;
                    }
                }
            }
            if(currMax>ans){
                ans = currMax;
                ansString = currMaxString;
            }
            cout<<"LP: "<<curr->val<<"    "<<currMax<<"   "<<currMaxString<<endl;
            return make_pair(currMax,currMaxString);
        }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    BT tree;
    tree.root = new Node(0);
    tree.root->left = new Node(1);
    tree.root->left->left = new Node(1);
    tree.root->left->right = new Node(0);
    tree.root->right = new Node(0);
    tree.root->right->left = new Node(1);
    tree.root->right->right = new Node(0);
    tree.root->right->left->left = new Node(0);
    tree.root->right->left->left->left = new Node(1);
    tree.LongestPath(tree.root);
    cout<<tree.ans<<endl;
    cout<<tree.ansString;
    return 0;
}