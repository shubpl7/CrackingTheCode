#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

class Node{
    public:
        int data;
        Node * left, * right;
        Node(int x){
            data = x;
            left = right = NULL;
        }
};

void printZigZag(Node * head){
    stack<Node *> s1, s2;
    s1.push(head);
    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()) {
            cout<<s1.top()->data<<" ";
            Node * temp = s1.top();
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
            s1.pop();
        }
        while(!s2.empty()) {
            cout<<s2.top()->data<<" ";
            Node * temp = s2.top();
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
            s2.pop();
        }
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
    Node * head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    printZigZag(head);
    return 0;
}