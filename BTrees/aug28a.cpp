#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

class Node{
    public:
        int data;
        Node * left, *right;
        Node(int x)
        {
            data = x;
            left=right=NULL;
        }
};
Node *p1;
class Btree{
    public:
        Node * root;
        Btree()
        {
            root=NULL;
        }
        int FindLevel(Node *,Node *, int, int);
};

int Btree::FindLevel(Node * temp,Node * parent, int x, int level)
{

    cout<<"FL "<<x<<"    "<<level<<endl;
    if(temp==NULL)
        return -1;
    if(temp->data == x)
    {
        p1=parent;
        return level;
    }
    int lt = FindLevel(temp->left,temp, x, level+1);
    if(lt==-1)
    {
        int rt = FindLevel(temp->right,temp, x, level+1);
        return rt;
    }
    return lt;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    Btree b;
    b.root = new Node(1);
    b.root->left = new Node(2);
    b.root->right = new Node(3);
    b.root->left->left = new Node(4);
    b.root->left->right = new Node(5);
    b.root->left->left->left = new Node(8);
    b.root->left->left->right = new Node(9);
    b.root->right->left = new Node(6);
    b.root->right->left->right = new Node(10);
    b.root->right->right = new Node(7);

    cout<<b.FindLevel(b.root,NULL,10,0)<<endl;
    cout<<p1->data<<" is the parent of 10";

    return 0;
}