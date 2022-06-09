#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
#define INT_SIZE 16
typedef vector<int> VI;
typedef vector<VI> VVI;

class Node{
    public:
        Node *bit[2];
        int val;
        int idx;
        Node()
        {
            bit[0]=NULL;bit[1]=NULL;
            val=0;
            idx=-1;
        }
};

void insert(Node * root, int prefix_xor, int index_of_last_prefix_element) {
    for(int i=INT_SIZE-1;i>=0;i--) {
        bool val = prefix_xor & (1<<i);
        if(!root->bit[val])
            root->bit[val] = new Node();
        root = root->bit[val];
    }
    root->val = prefix_xor;
    root->idx = index_of_last_prefix_element;
}

//It returns maximum xor ending with arr[i]
pair<int,int> query(Node * root, int prefix_xor) {
    for(int i=INT_SIZE-1;i>=0;i--) {
        bool val = prefix_xor & (1<<i);
        if(root->bit[1-val])
            root = root->bit[1-val];
        else
            root = root->bit[val];
    }
    int max_xor = root->val ^ prefix_xor;
    pair<int, int> ans;
    ans.first = max_xor;
    ans.second = root->idx+1;
    return ans;

}


void maxSubarrayXOR(int arr[], int n)
{
    //code here
    int prefix_xor = 0, start_index=-1, end_index=-1;
    Node * root = new Node();
    int res = INT_MIN;
    insert(root, 0, -1);
    for(int i=0;i<n;i++) {
        prefix_xor = prefix_xor^arr[i];
        insert(root, prefix_xor, i);
        auto y = query(root, prefix_xor);
        if(y.first>res) {
            start_index = y.second;
            end_index = i;
            res = y.first;
        }
    }
    cout<<"Maximum XOR subarray is found between: "<<start_index<<" and "<<end_index<<" & value is: "<<res<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxSubarrayXOR(arr,n);
    return 0;
}