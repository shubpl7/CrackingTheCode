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
struct Node{
       int data;
       Node *left, *right;
       Node(int k)
       {
              data =k;
              left=right=NULL;
       }
};
class Btree{
       public:
              Node *root;
              VI v;
              int res=0;
              void PreOrder(Node *);
              void LevelOrder(Node *);
              int height(Node *);
              void diameter(Node *);
              void RootToLeaf(Node *);
};
void Btree::PreOrder(Node *head)
{
       if(head==NULL)
              return;
       cout<<head->data<<" ";
       PreOrder(head->left);
       PreOrder(head->right);
}
void Btree::LevelOrder(Node *head)
{
       queue<Node *> q;
       q.push(head);
       while(!q.empty())
       {
              int cnt =q.size();
              int sum=0;
              for(int i=0;i<cnt;i++)
              {
                     Node *t = q.front();
                     cout<<t->data<<" ";
                     sum+=t->data;
                     q.pop();
                     if(t->left)
                            q.push(t->left);
                     if(t->right)
                            q.push(t->right);
              }
              cout<<"--->"<<sum<<endl;
       }
}
int Btree::height(Node *head)
{
       if(head==NULL)
              return 0;
       int lh=height(head->left);
       int rh = height(head->right);
       return max(lh,rh)+1;
}
void Btree::diameter(Node *head)
{
       if(head==NULL)
              return;
       int lh = height(head->left);
       int rh= height(head->right);
       res=max(res,lh+rh);
}
void Btree::RootToLeaf(Node *head)
{
       if(head==NULL)
              return;
       v.push_back(head->data);
       if(head->left==NULL && head->right==NULL)
       {
              int sum=0;
              for(auto x:v)
              {
                     sum+=x;
                     cout<<x<<" ";
              }
              cout<<"--->"<<sum<<endl;
       }
       RootToLeaf(head->left);
       RootToLeaf(head->right);
       auto it =v.end();
       it--;
       v.erase(it);
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       Btree t;
       t.root = new Node(10);
       t.root->left = new Node(20);
       t.root->right = new Node(30);
       t.root->left->left = new Node(40);
       t.root->left->right = new Node(50);
       t.root->right->left = new Node(60);
       t.root->right->right = new Node(70);
       t.PreOrder(t.root);
       cout<<endl;
       t.LevelOrder(t.root);
       t.diameter(t.root);
       cout<<"Diameter is : "<<t.res;
       cout<<endl;
       t.RootToLeaf(t.root);
       return 0;
}